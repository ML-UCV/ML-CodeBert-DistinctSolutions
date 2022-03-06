#include <iostream>
#include <stack>
#include <fstream>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

int prec(char c)

{

    if(c=='^')return 3;

    if(c=='*' || c=='/')return 2;

    if(c=='+' || c=='-') return 1;

    return -1;

}

string infixToPostfix(string a)

{

    string temp="";

    stack<char>s;

    int i,n=a.size();

    for(i=0; i<n; ++i)

    {

        if(a[i]=='a')temp+='a';

        else if(a[i]=='(')s.push('(');

            else if(a[i]==')')

            {

                while(!s.empty() && s.top()!='(')

                {

                    temp+=s.top();

                    s.pop();

                }

                if(s.top()=='(')s.pop();

            }

            else{

                while(!s.empty() && prec(a[i])<=prec(s.top()))

                {

                    temp+=s.top();

                    s.pop();

                }

                s.push(a[i]);

            }

    }

    while(!s.empty())

    {temp+=s.top();s.pop();}

    return temp;

}

int main()

{

    string a="";

    char c;

    int x[100005],k=1,i;

    while(fin>>c)

    {

        if(c<'0' || c>'9')a+=c;

        else

        {

            a+='a';

            int nr = c-'0';

            while(fin>>c)

                if(c<'0' || c>'9')

                {

                    a+=c;

                    break;

                }

                else{

                    int cifra=c-'0';

                    nr=nr*10+cifra;

                }

            x[k]=nr;

            ++k;

        }

    }

    k=1;

    a=infixToPostfix(a);

    int n= a.size();

    stack<int>s;

    for(i=0;i<n;++i)

    {

        if(a[i]=='a'){

            s.push(x[k]);

            ++k;

        }

        else{

            int unu=s.top();s.pop();int doi=s.top();s.pop();

            if(a[i]=='+')s.push(unu+doi);

            if(a[i]=='*')s.push(unu*doi);

            if(a[i]=='/')s.push(doi/unu);

            if(a[i]=='-')s.push(doi-unu);

        }

    }

    fout<<s.top();

    return 0;

}
