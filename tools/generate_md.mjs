// @ts-check

import fetch from 'node-fetch';
import * as cheerio from 'cheerio';
import iconv from 'iconv-lite';
import * as fs from 'fs';
import * as path from 'path';
import { dirname } from 'path';

const ANSWER_DIRECTORY = "pg_answer";
const OUTPUT_FILE = `dist/${ANSWER_DIRECTORY}.md`;

let _cookie = null;
function saveCookie(cookie) {
    _cookie = cookie;
}
function loadCookie() {
    if (_cookie === null) return {};
    return {
        cookie: _cookie,
    };
}
const userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.73";
const acceptLanguage = "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6";
const headers = {
    'User-Agent': userAgent,
    'Accept-Language': acceptLanguage
};

function getUsername() {
    return process.env.PG_USERNAME;
}
function getPassword() {
    return process.env.PG_PASSWORD;
}

async function login() {
    const username = getUsername();
    const password = getPassword();
    if (!username || !password) {
        console.log("Login fail: no username or password");
        return false;
    }
    const data = new URLSearchParams();
    data.append("appid", "ProgrammingGrid");
    data.append("userName", username);
    data.append("password", password);
    data.append("randCode", "");
    data.append("smsCode", "");
    data.append("otpCode", "");
    data.append("redirUrl", "https://programming.pku.edu.cn/authcallback");
    return fetch("https://iaaa.pku.edu.cn/iaaa/oauthlogin.do", {
        method: "POST",
        headers: {
            ...headers,
            'Content-Type': 'application/x-www-form-urlencoded; charset=UTF-8',
        },
        redirect: 'manual',
        body: data
    })
        .then(r => r.json())
        .then((/** @type {any} */json) => {
            console.log(json);
            if (json.success !== true) {
                console.log("Login fail: IAAA success = false");
                return false;
            }
            return fetch(`https://programming.pku.edu.cn/authcallback?_rand=${Math.random()}&token=${json.token}`, {
                headers: {
                    ...headers
                },
                redirect: 'manual'
            }).then(r => {
                const cookie = r.headers.get('Set-Cookie');
                if (cookie === null) {
                    console.log("Login fail: no Set-Cookie field");
                    return false;
                }
                console.log("Login success.");
                saveCookie(cookie);
                console.log(cookie);
                return true;
            });
        })
        .catch(err => {
            console.log(err);
            console.log("Login fail: exception");
            return false;
        });
}

const COURSE_ID = "8e6b7866023a4489babca3f56973f317";

(async () => {
    if (!await login()) process.exit();
    const setInfos = await fetch(`https://programming.pku.edu.cn/programming/course/${COURSE_ID}/show.do`, {
        headers: {
            ...headers,
            ...loadCookie()
        },
    })
        .then(r => r.buffer())
        .then(buf => {
            const text = iconv.decode(buf, 'gb2312');
            const $ = cheerio.load(text);
            const list = $("ul.homework");
            return list.children().map(function (i) {
                const a = $(this).children("a");
                // const color = $(this).children("font").attr("color");
                const href = a.attr("href");
                const text = a.text();
                if (typeof href === "undefined") return null;
                const result = /problemsId=([0-9a-f]{32})/.exec(href);
                if (result === null) return null;
                const pId = result[1];
                return {
                    id: pId,
                    text: text,
                    // available: color !== "green"
                };
            }).toArray();
        });
    const problemInfo = await Promise.all(setInfos.map(async (set) => {
        console.log(`Fetch set: ${set.id}`);
        return fetch(`https://programming.pku.edu.cn/programming/admin/course/${COURSE_ID}/showProblemList.do?problemsId=${set.id}&type=json`, {
            headers: {
                ...headers,
                ...loadCookie()
            },
        })
            .then(r => r.json())
            .then(async (/** @type {any} */json) => {
                /**
                 * @type {{
                 *  title: string,
                 *  id: string
                 * }[]} */
                const problems = json.problemlist.problems;
                return {
                    /** @type {string} */
                    title: json.problemlist.title,
                    problems: await Promise.all(problems.map(async ({ id }) => {
                        console.log(`Set ${set.id}, Fetch problem: ${id}`);
                        return fetch(`https://programming.pku.edu.cn/programming/problem/${id}/show.do?problemsId=${set.id}&type=json`, {
                            headers: {
                                ...headers,
                                ...loadCookie()
                            },
                        })
                            .then(r => r.json())
                            .then((/** @type {any} */json) => {
                                /** 
                                 * @type {{
                                 *  title: string,
                                 *  id: string;
                                 *  description: string,
                                 *  aboutInput: string;
                                 *  aboutOutput: string;
                                 * }} */
                                const problem = json.problem;
                                function htmlify(/** @type {string} */str) {
                                    return `<p>${str.replace(/\n/g, "<br>").replace(/<\/?strong>/, "")}</p>`;
                                }
                                return {
                                    title: problem.title,
                                    id: problem.id,
                                    description: htmlify(problem.description),
                                    aboutInput: htmlify(problem.aboutInput),
                                    aboutOutput: htmlify(problem.aboutOutput),
                                };
                            });
                    }))
                };
            });
    }));

    const answerIds = fs.readdirSync(`../${ANSWER_DIRECTORY}`);
    const answers = {};
    answerIds.forEach(id => {
        const answer = fs.readFileSync(`../${ANSWER_DIRECTORY}/${id}`, "utf8");
        answers[path.basename(id, ".cpp")] = answer.replace(/\r\n/g, "\n");
    });

    let markdownContent = "# 参考答案汇总\n\n";

    for (const {title, problems} of problemInfo) {
        markdownContent += `## ${title}\n`;
        problems.forEach(({ id, title, description, aboutInput, aboutOutput }) => {
            markdownContent += `### ${title}\n`;
            markdownContent += `\n\n<details>\n\n#### 题目描述\n${description}\n\n`;
            markdownContent += `#### 输入\n${aboutInput}\n\n`;
            markdownContent += `#### 输出\n${aboutOutput}\n\n</details>\n\n`;
            if (id in answers) {
                markdownContent += `#### [点我查看参考答案](#ans_${id})\n\n`;
            } else {
                markdownContent += `#### 暂无参考答案\n\n`;
            }
        });
    }
    markdownContent += "## 参考答案\n\n"
    for (const id in answers) {
        markdownContent += `###### ans_${id}\n`;
        markdownContent += `\`\`\`cpp\n${answers[id]}\n\`\`\`\n`;
    }

    fs.mkdirSync(dirname(`../${OUTPUT_FILE}`), { recursive: true });
    fs.writeFileSync(`../${OUTPUT_FILE}`, markdownContent);
})();