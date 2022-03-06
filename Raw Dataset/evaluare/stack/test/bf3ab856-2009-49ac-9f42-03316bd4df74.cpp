#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
using namespace std;



string x;

stack<char> a;

stack<int> b;

char pr[256];



int proces(int a,int b,char semn)

{

 if(semn=='+') return a+b;

 if(semn=='-') return a-b;

 if(semn=='*') return a*b;

 if(semn=='/') return a/b;

 return 0;

}



void f()

{

 char semn=a.top();

 a.pop();

 if(semn=='(') return;

 int c=b.top();

 b.pop();

 int d=b.top();

 b.pop();

 b.push(proces(d,c,semn));

 return;

}

int main()

{

 pr['+']=pr['-']=0;

 pr['*']=pr['/']=1;

 pr['(']=pr[')']=3;

 freopen("evaluare.in","r", stdin);

 freopen("evaluare.out","w", stdout);

 getline(cin,x);

 for(unsigned int i=0;i<x.size();i++)

 {



  if(isdigit(x[i]) || ( (i==0 || x[i-1]=='(') && x[i]=='-') )

  {

   int nr=0,y=1;

   if(x[i]=='-')

   {

    i++;

    y*=-1;

   }

   while(isdigit(x[i]))

   {

    nr=nr*10+x[i]-'0';

    i++;

   }

   nr*=y;

   b.push(nr);

   i--;

   continue;

  }

  else

  {

   if(x[i]=='(') a.push(x[i]);

   else if(x[i]==')')

   {

    while(a.top()!='(') f();

    a.pop();

   }

   else

   {

    while(a.size()>0 && pr[x[i]]<=pr[a.top()] && a.top()!='(')

    {

     f();

    }

    a.push(x[i]);



   }

  }

 }

 while(a.size()) f();

 printf("%d",b.top());



 return 0;

}
