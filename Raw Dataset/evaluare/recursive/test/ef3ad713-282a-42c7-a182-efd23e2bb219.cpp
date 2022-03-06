#include<stdio.h>
char s[100100];

int poz;

int eval();

int produs();

int termen(){

 int aux=0;

 if(s[poz]=='('){

  ++poz;

  aux=eval();

  ++poz;

  return aux;

 }

 while('0'<=s[poz] && s[poz]<='9')

  aux=aux*10+(s[poz++]-'0');

 return aux;

}

int produs(){

 int aux=termen();

 while(s[poz]=='*' || s[poz]=='/'){

  if(s[poz++]=='*')

   aux*=termen();

  else

   aux/=termen();

 }

 return aux;

}

int eval(){

 int aux=produs();

 while(s[poz]=='+' || s[poz]=='-'){

  if(s[poz++]=='+')

   aux+=produs();

  else

   aux-=produs();

 }

 return aux;

}

int main(){

 freopen("evaluare.in","r",stdin);

 freopen("evaluare.out","w",stdout);

 scanf("%s",s);

 printf("%d\n",eval());

 fclose(stdin);

 fclose(stdout);

 return 0;

}
