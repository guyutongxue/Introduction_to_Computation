#include <stdio.h>///整活
int f[9],s,y,r[93];int g(
int _){int i=0,x=0;_>8&&(
r[++s]=y);for(;++i<_;)x|=
f[i]|f[i]<<_-i|f[i]>>_-i;
for(i=0;i<8;i++)x&1<<i||(
f[_]=1<<i,y=y<<4|i+1,g(_+
1),y>>=4);}int main(){for
(g(1),scanf("%d",&s);s--;
scanf("%d",&y),printf("%"
"x\n",r[y]));}///////////