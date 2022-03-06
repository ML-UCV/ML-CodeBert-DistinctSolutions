#include<bits/stdc++.h>
using namespace std;



int expresie();

int termen();

int factor();



char s[100005];



int i,n;



int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);



    scanf("%s",s+1);



    n=strlen(s+1);

    i=1;



    printf("%d\n",expresie());





    return 0;

}

int expresie()

{

    int r=termen();

    while(s[i]=='+' || s[i]=='-')

    {

        if(s[i]=='+')

        {

            i++;

            r+=termen();

        }

            else

        {

            i++;

            r-=termen();

        }

    }



    return r;

}







int termen()

{

    int r=factor();

    while(s[i]=='*' || s[i]=='/')

    {

        if(s[i]=='*')

        {

            i++;

            r*=factor();

        }

            else

        {

            i++;

            r/=factor();

        }

    }



    return r;

}

int factor()

{

    int r;



    if(s[i]=='(')

    {

        i++;

        r=expresie();

        i++;

    }

        else

    {

        r=0;

        while(isdigit(s[i]))

        {

            r=r*10+s[i]-'0';

            i++;

        }

    }



    return r;

}
