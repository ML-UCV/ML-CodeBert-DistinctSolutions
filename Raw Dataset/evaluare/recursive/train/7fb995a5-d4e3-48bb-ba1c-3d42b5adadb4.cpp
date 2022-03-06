#include<cstdio>
char s[100001],*p=s,r[100001],o;

inline void S(int x)

{

    if(x<0)

        x=-x,r[o++]='-';

    int i,d=x>999999999?10:x>99999999?9:x>9999999?8:x>999999?7:x>99999?6:x>9999?5:x>999?4:x>99?3:x>9?2:1;

    for(i=d-1;i>=0;x/=10,i--)

        r[o+i]=x%10+48;

    o+=d;

}

inline int E(int l)

{

    int x,y;

    if(l==2)

        if(*p=='(')

            p++,x=E(0),p++;

        else

            for(x=0;*p>='0'&&*p<='9';p++)

                x=x*10+*p-'0';

    else

        for(x=E(l+1);(!l&&(*p=='+'||*p=='-'))||(l&&(*p=='*'||*p=='/'));x=y)

            if(!l)

                if(*p=='+')

                    p++,y=x+E(l+1);

                else

                    p++,y=x-E(l+1);

            else if(*p=='*')

                p++,y=x*E(l+1);

            else

                p++,y=x/E(l+1);

    return x;

}

int main()

{

    freopen("evaluare.in","r",stdin),freopen("evaluare.out","w",stdout),fread(s,1,100001,stdin),S(E(0)),fwrite(r,1,o,stdout);

}
