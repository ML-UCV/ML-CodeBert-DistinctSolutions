#include <bits/stdc++.h>
using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



int st,qu,x,y;

string s,nr;

string q[100005];

char a[100005];

int aa[100005];



bool comp(char A,char B)

{

    if((A=='+' || A=='-') && B!='(') return true;

    if((A=='*' || A=='/') && (B=='*' || B=='/')) return true;

    return false;

}



int main()

{

    getline(f,s);

    for(int i=0;i<s.size();++i)

    {

        if(s[i]=='(') a[++st]=s[i];

        else if(s[i]==')')

        {

            while(a[st]!='(')

            {

                q[++qu]=a[st];

                --st;

            }

            --st;

        }

        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')

        {

            while(st && comp(s[i],a[st]))

            {

                q[++qu]=a[st];

                --st;

            }

            a[++st]=s[i];

        }

        else

        {

            nr="";

            while(i<s.size() && s[i]>='0' && s[i]<='9')

            {

                nr+=s[i];

                ++i;

            }

            --i;

            q[++qu]=nr;

        }

    }

    while(st)

    {

         q[++qu]=a[st];

         --st;

    }

    st=0;

    for(int i=1;i<=qu;++i)

    {

        if(q[i][0]>='0' && q[i][0]<='9')

        {

            x=atoi(q[i].c_str());

            aa[++st]=x;

        }

        else

        {

            y=aa[st]; --st;

            x=aa[st]; --st;

            if(q[i][0]=='+') x+=y;

            if(q[i][0]=='-') x-=y;

            if(q[i][0]=='*') x*=y;

            if(q[i][0]=='/') x/=y;

            aa[++st]=x;

        }

    }

    g<<aa[st];

    return 0;

}
