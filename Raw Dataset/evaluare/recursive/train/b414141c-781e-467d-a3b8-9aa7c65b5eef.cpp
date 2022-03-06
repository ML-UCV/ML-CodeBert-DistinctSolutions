#include<cstdio>


char s[100001],*p=s;

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

    freopen("evaluare.in","r",stdin),freopen("evaluare.out","w",stdout),fgets(s,100001,stdin),printf("%d",E(0));

}
