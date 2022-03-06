#include <bits/stdc++.h>


using namespace std;

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");



stack <char> s;

stack <int> ev;

vector <int> v;

char c[100005], t;

int i, n, nr, p;





int putere(char c)

{

    switch(c)

    {

        case '+': return 1;

        case '-': return 1;



        case '*': return 2;

        case '/': return 2;



        case '(': return 0;

    }

}

int tip(char c)

{

    switch(c)

    {

        case '-': return -1;

        case '+': return -2;

        case '*': return -3;

        case '/': return -4;

    }

}

int numar()

{

    int nr=0;

    while('0'<=c[i]&&c[i]<='9')

        {

            nr=nr*10+c[i]-'0';

            i++;

        }

    return nr;

}

int main()

{

    fin.getline(c, 100005);

    n=strlen(c);

    for(i=0;i<n;i++)

    {

        if('0'<=c[i]&&c[i]<='9')

        {

            nr=numar();

            v.push_back(nr);

            i--;

        }

        else

        {

            if(c[i]==')')

            {

                t=s.top();

                while(s.top()!='(')

                {

                    v.push_back(tip(s.top()));

                    s.pop();

                }

                s.pop();

            }

            else if(c[i]=='(')

                s.push(c[i]);

            else

            {

                p=putere(c[i]);



                while(!s.empty()&&putere(s.top())>=p)

                    {

                        v.push_back(tip(s.top()));

                        s.pop();

                    }

                s.push(c[i]);

            }

        }

    }



    while(!s.empty())

        {

            v.push_back(tip(s.top()));

            s.pop();

        }



    for(i=0;i<v.size();i++)

    {

        if(v[i]<0)

        {

            int E, e1, e2;

            e2=ev.top();

            ev.pop();

            e1=ev.top();

            ev.pop();

            if(v[i]==-1)

                E=e1-e2;

            else if(v[i]==-2)

                E=e1+e2;

            else if(v[i]==-3)

                E=e1*e2;

            else if(v[i]==-4)

                E=e1/e2;

            ev.push(E);

        }

        else ev.push(v[i]);

    }

    fout << ev.top();

    return 0;

}
