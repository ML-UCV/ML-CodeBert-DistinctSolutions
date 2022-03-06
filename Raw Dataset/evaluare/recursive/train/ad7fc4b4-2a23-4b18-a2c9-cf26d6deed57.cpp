#include<stdio.h>
char s[100005];

char *p=s;

int factor();

int termen();



int eval(){

    int r=factor();

    while(*p=='+'||*p=='-'){

        if(*p=='+'){

            ++p;

            r=r+factor();

        }

        else{

            ++p;

            r=r-factor();

        }

    }

    return r;

}



int factor(){

    int r=termen();

    while(*p=='*'||*p=='/'){

        if(*p=='*'){

            ++p;

            r=r*termen();

        }

        else{

            ++p;

            r=r/termen();

        }

    }

    return r;

}



int termen(){

    int r;

    if(*p=='('){

        p++;

        r=eval();

        p++;

    }

    else{

        r=0;

        while(*p<='9'&&*p>='0'){

            r=r*10+*p-'0';

            p++;

        }

    }

    return r;

}





int main(){

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    scanf("%s",&s);

    printf("%d",eval());

}
