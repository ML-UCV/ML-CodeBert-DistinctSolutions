#include<bits/stdc++.h>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

string s;

stack<char>sol;

stack<int>rez;

queue<string>q;

unordered_map<char,int>mp;

int me(char a,char b)

{

    return mp[a]>=mp[b];

}

int conv(string s)

{

    int ret=0;

    for(int i=0;i<s.size();i++)

        ret=ret*10+s[i]-'0';

    return ret;

}

int main()

{

    mp['+']=mp['-']=1;

    mp['*']=mp['/']=2;

    fin>>s;

    s='('+s+')';

    for(int i=0;i<s.size();i++)

    {

        if(s[i]=='(')

        {

            sol.push('(');

            continue;

        }



        if(s[i]==')')

        {

            while(sol.top()!='(')

            {

                string t;

                t+=sol.top();

                sol.pop();

                q.push(t);

            }

            sol.pop();

            continue;

        }



        if(isdigit(s[i]))

        {

            string t;

            while(isdigit(s[i]))

            {

                t+=s[i];

                i++;

            }

            i--;

            q.push(t);

            continue;

        }



        while(1)

        {

            if(sol.top()=='(')

                break;

            if(!me(sol.top(),s[i]))

                break;

            string t;



            t+=sol.top();

            sol.pop();

            q.push(t);

        }

        sol.push(s[i]);

    }

    while(!q.empty())

    {

        string t=q.front();

        q.pop();

        if(isdigit(t[0]))

        {



            rez.push(conv(t));

            continue;

        }

        int g=rez.top();

        rez.pop();

        int f=rez.top();

        rez.pop();

        int z=0;

        if(t[0]=='+')

            z=f+g;

        if(t[0]=='-')

            z=f-g;

        if(t[0]=='*')

            z=f*g;

        if(t[0]=='/')

            z=f/g;

        rez.push(z);

    }

    fout<<rez.top()<<'\n';

}
