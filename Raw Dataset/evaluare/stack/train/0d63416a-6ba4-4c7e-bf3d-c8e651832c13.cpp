#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
ifstream fin("evaluare.in");
ofstream fout("evaluare.out");
int n, m, i, j, dg;
char s[200005];
stack<int> val;
stack<char> op;
int fa(int x, char semn, int y)
{
 if(semn=='+')
  return x+y;
 else if(semn=='-')
  return y-x;
 else if(semn=='*')
  return x*y;
 else return y/x;
}
int pred(char semn)
{
 if(semn=='*'||semn=='/')
  return 2;
 else if(semn=='+'||semn=='-')return 1;
 return 0;
}
int main()
{
 fin>>s;
 n=strlen(s);
 for(i=0;i<n;++i)
 {
  if(s[i]>='0'&&s[i]<='9')
  {
   if(dg==-1)
    dg=0;
   dg=dg*10+s[i]-'0';
   continue;
  }
  if(dg>-1)
  {
   val.push(dg);
   dg=-1;
  }
  if(s[i]=='(')
   op.push('(');
  else if(s[i]==')')
  {
   while(op.top()!='(')
   {
    int x=val.top();
    val.pop();
    int y=val.top();
    val.pop();
    val.push(fa(x,op.top(),y));
    op.pop();
   }
   op.pop();
  }
  else
  {
   while(!op.empty()&&pred(op.top())>=pred(s[i]))
   {
    int x=val.top();
    val.pop();
    int y=val.top();
    val.pop();
    val.push(fa(x,op.top(),y));
    op.pop();
   }
   op.push(s[i]);
  }
 }
 if(dg>-1)
  val.push(dg);
 while(!op.empty())
 {
  int x=val.top();
  val.pop();
  int y=val.top();
  val.pop();
  cout<<x<<' '<<y<<'\n';
  val.push(fa(x,op.top(),y));
  op.pop();
 }
 fout<<val.top();
}
