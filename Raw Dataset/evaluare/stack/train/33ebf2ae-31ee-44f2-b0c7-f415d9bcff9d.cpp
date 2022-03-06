#include <bits/stdc++.h>


using namespace std;



ifstream si("evaluare.in");

ofstream so("evaluare.out");



long long op[100001],q[100001],n,i,nr,nr2,x;

char s[100001];



void calc(int a,int b)

{

    if(op[b]=='+')

    {

        q[a-1]+=q[a];

    }

    if(op[b]=='-')

    {

        q[a-1]-=q[a];

    }

    if(op[b]=='*')

    {

        q[a-1]*=q[a];

    }

    if(op[b]=='/')

    {

        q[a-1]/=q[a];

    }

    return;



}



int gr(char c)

{

    if(c=='+' or c=='-')

    {

        return 1;

    }

    if(c=='*' or c=='/')

    {

        return 2;

    }

    return 0;

}



int main()

{

    si.getline(s,100001);

    n=strlen(s);

    for(i=0; i<n; i++)

    {

        if(isdigit(s[i]))

        {

            x=0;

            while(isdigit(s[i]))

            {

                x*=10;

                x+=s[i]-'0';

                i++;

            }

            i--;

            q[++nr]=x;

        }

        else

        {

            if(nr2==0 || s[i]=='(' || gr(op[nr2])<gr(s[i]))

            {

                op[++nr2]=s[i];

            }

            else if(s[i]==')')

            {

                while(op[nr2]!='(')

                {

                    calc(nr,nr2);

                    nr--;

                    nr2--;

                }

                nr2--;

            }

            else

            {

                while(gr(s[i])<=gr(op[nr2]))

                {

                    calc(nr,nr2);

                    nr--;

                    nr2--;

                }

                op[++nr2]=s[i];

            }

        }

    }

    while(nr2)

    {

        calc(nr,nr2);

        nr--;

        nr2--;

    }

    so<<q[1];

    return 0;

}
