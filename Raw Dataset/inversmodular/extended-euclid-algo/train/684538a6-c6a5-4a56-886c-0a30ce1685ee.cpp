#include<cstdio>
int a,n,x,y;
inline void E(int &x,int &y,int a,int b)
{
 int z;
    if(!b)
        x=1,y=0;
    else
        E(x,y,b,a%b),z=x,x=y,y=z-y*(a/b);
}
int main()
{
    freopen("inversmodular.in","r",stdin),freopen("inversmodular.out","w",stdout),scanf("%d%d",&a,&n),E(x,y,a,n),printf("%d",x<=0?(n+x%n):x);
}
