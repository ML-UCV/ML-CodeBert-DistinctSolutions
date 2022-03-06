#include <iostream>
#include <fstream>
#include <cstring>
std::ifstream fin("evaluare.in");
std::ofstream fout("evaluare.out");

char c[100500], *p=c;
char op[4][4]={"+-","*/","^",""};
int LEVMAX=2;


int eval(int a,int b,char oper)
{
  if(oper=='+')
    return a+b;
  if(oper=='-')
    return a-b;
  if(oper=='/')
    return a/b;
  return a*b;
}

int expr(int lev)
{
  int x,y;
  if(lev==LEVMAX)
  {
    if(*p=='(')
    {
      ++p;
      x= expr(0);
      ++p;
    }
    else
    {
      x=0;
      while(*p>='0' &&*p<='9')
      {
        x=x*10+(*p-'0');
        ++p;
      }
    }
  }
  else
    for(x=expr(lev+1);strchr(op[lev],*p);x=y)
      y=eval(x,expr(lev+1),*p++);
  return x;
}
int main()
{
  fin.getline(c,100500);
  int str= strlen(c);
  c[str]='\n';
  c[str+1]='\0';



  fout<<expr(0);
}
