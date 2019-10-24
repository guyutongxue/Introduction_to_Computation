#include<iostream>
#include<algorithm>
using namespace std;
struct Student{
    int ID;
    int chineseGrade;
    int mathGrade;
    bool operator<(Student b)const{
        if((chineseGrade+mathGrade)==(b.chineseGrade+b.mathGrade))return ID<b.ID;
        return (chineseGrade+mathGrade)>(b.chineseGrade+b.mathGrade);
    }
};
Student st[100002];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st[i].ID>>st[i].chineseGrade>>st[i].mathGrade;
    }
    sort(st+1,st+n+1);
    for(int i=1;i<=3;i++){
        cout<<st[i].ID<<" "<<(st[i].chineseGrade+st[i].mathGrade)<<endl;
    }
    return 0;
}