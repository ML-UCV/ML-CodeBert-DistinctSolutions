#include <bits/stdc++.h>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100005],semne[100005],semne1[100005];

int h,stiva[100005],sol[100005],k,h1;

int main()

{

    f>>s;

    int nr=0;

    for(int i=0; s[i]; i++)

    {

        if(s[i]=='('||s[i]==')'||s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/')

        {

            if(s[i-1]!=')'&&s[i]!='(')

                stiva[++h]=nr;

            nr=0;

            semne1[++k]=s[i];

            if(s[i]=='+'||s[i]=='-')

                while(semne1[k-1]!='('&&k>1)

                {

                    semne[++h]=semne1[k-1];

                    semne1[k-1]=semne1[k];

                    k--;

                }

            else if(s[i]=='*'||s[i]=='/')

                while(semne1[k-1]!='('&&semne1[k-1]!='+'&&semne1[k-1]!='-'&&k>1)

                {

                    semne[++h]=semne1[k-1];

                    semne1[k-1]=semne1[k];

                    k--;

                }

            else if(s[i]==')')

            {

                while(semne1[k-1]!='(')

                {

                    semne[++h]=semne1[k-1];

                    semne1[k-1]=semne1[k];

                    k--;

                }

                k-=2;

            }

        }

        else

            nr=nr*10+s[i]-'0';

    }

    if(s[strlen(s)-2]!=')'&&s[strlen(s)-1]!=')')

        stiva[++h]=nr;

    while(semne1[k])

        semne[++h]=semne1[k],k--;

    for(int i=1; i<=h; i++)

    {

        if(semne[i])

        {

            switch(semne[i])

            {

            case '+':

                sol[h1-1]=sol[h1-1]+sol[h1];

                break;

            case '-':

                sol[h1-1]=sol[h1-1]-sol[h1];

                break;

            case '*':

                sol[h1-1]=sol[h1-1]*sol[h1];

                break;

            case '/':

                sol[h1-1]=sol[h1-1]/sol[h1];

                break;



            }

            h1--;

        }

        else

            sol[++h1]=stiva[i];

    }

    g<<sol[h1];



    return 0;

}
