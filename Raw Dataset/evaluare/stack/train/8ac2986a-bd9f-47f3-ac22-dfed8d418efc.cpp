#include <bits/stdc++.h>





using namespace std;
ifstream fin("evaluare.in");
ofstream fout("evaluare.out");
void citire();
int vf = 0;
int prio(char x)
{
 if( x=='(' || x == ')')
  return 0;
 if( x=='+' || x=='-')
  return 1;

  return 2;
}
int operatie ( int a, int b, char c )
{

  switch (c)
 {
  case '+': return a+b;
  case '-': return a-b;
  case '*': return a*b;
  case '/': return a/b;

 }
}
int eval(char []);
char x[300001];
int s[100001];
void postfix(char []);
void rez();
void afis();
int main()
{
 fin >> x;
 postfix(x);


 fout<< eval(x);
}
void postfix(char x[])
{
 int poz = 0;
 int N =strlen (x);
 char aux[300001] = {0};
 for ( int i = 0 ; i < N ; i++)
 {
  if(isdigit(x[i]))
  {
   aux[poz++] = x[i] ;
  }
  else
  {
   if(i>0 && isdigit(x[i-1]))
    aux[poz++]=' ';
   if(x[i]=='(')
    s[vf++]=x[i];
   else
    if(x[i]==')')
    {
     while(s[vf-1]!='(')
     {
      aux[poz++]=s[--vf];
     }
     vf--;
    }
   else
   {
    while(vf != 0 && prio(x[i]) <= prio(s[vf-1]))
    {
      aux[poz++]=s[--vf];
    }
    s[vf++] = x[i];
   }
  }


 }
 if(isdigit(aux[poz-1])) aux[poz++]=' ';
 while(vf!=0)
 {
  aux[poz++] = s[--vf];
 }

 strcpy(x,aux);

}
int eval( char x[])
{
 int N =strlen(x);
 int numar =0;
 for( int i=0 ;i < N ;i ++)
 {
  if(isdigit(x[i])) numar = numar*10 +(x[i]-'0');
  else
   if (x[i]== ' ') {
    s[vf++]=numar;
    numar=0;
   }
  else
  {
   int nr2=s[--vf], nr1= s[--vf];
   s[vf++] = operatie ( nr1 ,nr2 , x[i]);
  }
 }
 return s[vf-1];
}
