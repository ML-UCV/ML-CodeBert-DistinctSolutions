#include <iostream>
#include <cstdio>
const long MAX = 100010;



char S[MAX],s[MAX];

int i = 0;



int numar()

{

    int nr=0;

    while(s[i]>='0' && s[i]<='9')

    {

        nr=nr*10+s[i]-'0';

        ++i;

    }

    return nr;

}



long termen();



long factor();
long eval() {



 long rezultat = termen();



 while ( s[i] =='+' || s[i]=='-' ) {



  switch ( s[i] ) {



   case '+':



    ++i;



    rezultat += termen();



    break;



   case '-':



    ++i;



    rezultat -= termen();



    break;



  }



 }



 return rezultat;



}
long termen() {

    long rezultat=factor();

    while ( s[i] =='*' || s[i]=='/' ) {



  switch ( s[i] ) {



   case '*':



    ++i;



    rezultat *= factor();



    break;



   case '/':



    ++i;



    rezultat /= factor();



    break;



  }



 }



 return rezultat;



}
long factor() {

    int nr=0;

   if(s[i]=='(')

   {

       i++;

       nr=eval();

       i++;

   }

   if(s[i]>='0' && s[i]<='9')

   nr=numar();



   return nr;

}







int main() {



    fgets(s, MAX, fopen("evaluare.in", "r"));





    fprintf(fopen("evaluare.out", "w"), "%ld\n", eval());



    return 0;



}
