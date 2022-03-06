#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

char A[100001];

int nl,a,b;

queue <int>ex;

stack <pair<char,int> >semn;

stack <int>evaluare;



int prioritate(char c)

{

    if(c=='+')

        return 1;

    if(c=='-')

        return 1;

    if(c=='*')

        return 2;

    if(c=='/')

        return 2;

    return 0;

}

int conv(pair<char,int> c)

{

    if(c.first=='+')

        return -1;

    if(c.first=='-')

        return -2;

    if(c.first=='*')

        return -3;

    if(c.first=='/')

        return -4;

    return 0;

}

int nr(int &r)

{

    int d=0;

    while('0'<=A[r]&&A[r]<='9')

    {

        d=d*10+A[r]-'0';

        r++;

    }

    return d;

}

int main()

{

    fin>>A;

    nl=strlen(A);

    int k=0;

    for(int i=0;i<nl;i++)

    {

        if('0'<=A[i]&&A[i]<='9')

            ex.push(nr(i));

        if(prioritate(A[i])>0)

        {

            while(!semn.empty()&&(prioritate(A[i])+k<=semn.top().second))

            {

                ex.push(conv(semn.top()));

                semn.pop();

            }

            semn.push({A[i],prioritate(A[i])+k});

        }

        if(A[i]=='(')

            k+=2;

        if(A[i]==')')

            k-=2;

    }

    while(!semn.empty())

    {

        ex.push(conv(semn.top()));

        semn.pop();

    }

    while(!ex.empty())

    {

        if(ex.front()>=0)

        {

            evaluare.push(ex.front());



            ex.pop();

        }

        else

        {

            a=evaluare.top();

            evaluare.pop();

            b=evaluare.top();

            evaluare.pop();

            if(ex.front()==-1)

                evaluare.push(b+a);

            if(ex.front()==-2)

                evaluare.push(b-a);

            if(ex.front()==-3)

                evaluare.push(b*a);

            if(ex.front()==-4)

                evaluare.push(b/a);



            ex.pop();

        }

    }

    fout<<evaluare.top();

    return 0;

}
