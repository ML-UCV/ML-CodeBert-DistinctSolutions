#include <bits/stdc++.h>

using namespace std;

ifstream in("evaluare.in");
ofstream out("evaluare.out");

char s[100005];
char op[50005];
int nr[50005],optop,nrtop,pr[200];


int calculate(int a,int b,char op)
{
 if(op=='+') return a+b;
 else if(op=='-') return a-b;
 else if(op=='*') return a*b;
 else if(op=='/') return a/b;
}
int main()
{
 in>>s;
 pr['+']=1;
 pr['-']=1;
 pr['*']=2;
 pr['/']=2;
 int lung=strlen(s);
 for(int i=0;i<lung;i++)
 {
  if(s[i]=='(')
   op[++optop]=s[i];
  else if(s[i]==')')
  {
   while(op[optop]!='(')
   {
    int ans=calculate(nr[nrtop-1],nr[nrtop],op[optop]);
    optop--;
    nrtop--;
    nr[nrtop]=ans;
   }
   optop--;
  }
  else if(s[i]>='0' && s[i]<='9')
  {
   int number=0;
   while(s[i]>='0' && s[i]<='9')
   {
    number=number*10+s[i]-'0';
    i++;
   }
   i--;
   nr[++nrtop]=number;
  }
  else
  {
   while(optop>0 && pr[op[optop]]>=pr[s[i]])
   {
    int ans=calculate(nr[nrtop-1],nr[nrtop],op[optop]);
    optop--;
    nrtop--;
    nr[nrtop]=ans;
   }
   op[++optop]=s[i];
  }
 }
 while(optop>0)
 {
  int ans=calculate(nr[nrtop-1],nr[nrtop],op[optop]);
  nrtop--;
  optop--;
  nr[nrtop]=ans;
 }
 out<<nr[nrtop];
 return 0;
}
