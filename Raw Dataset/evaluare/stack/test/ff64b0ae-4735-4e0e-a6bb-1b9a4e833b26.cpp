#include <bits/stdc++.h>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

int i,v1,v2,rez;

string str;

stack <int>val;

stack <char>s;

int calc(int v1,int v2,char op)

{

    if(op=='+') return v2+v1;

    else if(op=='-') return v1-v2;

    else if(op=='*') return v1*v2;

    else return v1/v2;

}

int preced(char op)

{

    if(op=='-'||op=='+') return 1;

    if(op=='*'||op=='/') return 2;

    return 0;

}

int ev()

{



    char op;

getline(fin,str);

    for(i=0; i<str.size(); i++)

    {



        if(str[i]==' ')continue;

        if(isdigit(str[i])==true)

        {

            v1=0;

            while(isdigit(str[i])==true&&i<str.size())

            {

                v1=v1*10+(str[i]-'0');

                i++;

            }i--;

            val.push(v1);

        }

        else if(str[i]=='(')

        {

            s.push(str[i]);

        }

        else if(str[i]==')')

        {

            while(!s.empty()&&s.top()!='(')

            {

                v2=val.top();

                val.pop();

                v1=val.top();

                val.pop();

                op=s.top();

                s.pop();

                val.push(calc(v1,v2,op));

            }

            if(!s.empty())s.pop();

        }

        else

        {

            while(!s.empty()&&preced(s.top())>=preced(str[i]))

            {

                v2=val.top();

                val.pop();

                v1=val.top();

                val.pop();

                op=s.top();

                s.pop();

                val.push(calc(v1,v2,op));

            }

            s.push(str[i]);

        }

    }

    while(!s.empty())

    {

        v2=val.top();

        val.pop();

        v1=val.top();

        val.pop();

        op=s.top();

        s.pop();

        val.push(calc(v1,v2,op));



    }

    return val.top();



}

int main()

{fout<<ev();

    return 0;

}
