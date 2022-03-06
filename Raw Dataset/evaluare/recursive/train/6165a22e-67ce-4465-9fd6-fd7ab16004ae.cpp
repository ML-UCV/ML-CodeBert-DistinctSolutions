#include <bits/stdc++.h>



using namespace std;

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");

char sir[100009];int n,p;

int termen () ;

int factor ();



int eval () {

 int r=termen();

 while(sir[p]=='+' || sir[p]=='-') {

  if(sir[p]=='+')

   ++p,r+=termen();

  else

   ++p,r-=termen();

 }

 return r;

}

int termen () {

 int r=factor();

 while(sir[p]=='*' || sir[p]=='/') {

  if(sir[p]=='*')

   ++p,r*=factor();

  else

   ++p,r/=factor();

 }

 return r;

}

int factor () {

 int r=0;

 if(sir[p]=='(') {

  ++p;r=eval();

  ++p;

 }

 else {

  while(sir[p]>='0' && sir[p]<='9')

   r=r*10+sir[p]-'0',++p;

 }

 return r;

}



int main () {

 fin.getline(sir+1,100005);p=1;n=strlen(sir+1);

 fout<<eval();

 return 0;

}
