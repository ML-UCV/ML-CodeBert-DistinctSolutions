#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

ifstream in ("evaluare.in");

ofstream out ("evaluare.out");

string s;

int num[100007],st[100007];

int pd=-1000000001,pi=-1000000002,plu=-1000000003,minu=-1000000004,inm=-1000000005,imp=-1000000006;

int main()

{

    in>>s;

    int n=s.length();

    int i=0,f=0,k=0;

    int nr=0;

    while(i<n)

    {

        if(isdigit(s[i]))

        {

            nr=0;

            while(isdigit(s[i]))

            {

                nr=nr*10+(s[i]-'0');

                i++;

            }

            i--;

            num[++f]=nr;

        }

        else

        {

            if(s[i]=='(')

                st[++k]=pd;

            else if(s[i]==')')

            {

                while(st[k]!=pd)

                    num[++f]=st[k--];

                k--;

            }

            else if (s[i]=='+')

            {

                while(st[k]!=pd&&k)

                    num[++f]=st[k--];

                st[++k]=plu;

            }

            else if (s[i]=='-')

            {

                while(st[k]!=pd&&k)

                    num[++f]=st[k--];

                st[++k]=minu;

            }

            else if (s[i]=='*')

            {

                while((st[k]==inm||st[k]==imp)&&k)

                    num[++f]=st[k--];

                st[++k]=inm;

            }

            else if (s[i]=='/')

            {

                while((st[k]==inm||st[k]==imp)&&k)

                    num[++f]=st[k--];

                st[++k]=imp;

            }

        }

        i++;

    }

    while(k)

        num[++f]=st[k--];

    for(i=1; i<=f; i++)

    {

        if(num[i]>=0)

            st[++k]=num[i];

        else

        {

            if(num[i]==inm)

            {

                if(k<2)

                    st[k]=0;

                else

                {

                    st[--k]*=st[k+1];

                }

            }

            else if(num[i]==imp)

            {

                st[--k]/=st[k+1];

            }

            else if(num[i]==plu)

            {

                st[--k]+=st[k+1];

            }

            else if(num[i]==minu)

            {

                st[--k]-=st[k+1];

            }

        }

    }

    out<<st[1];

    return 0;

}
