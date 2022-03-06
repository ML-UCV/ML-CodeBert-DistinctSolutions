#include <cstdio>
#include <iostream>
const long MAX = 100010;



char s[MAX];

int i = 0;







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

   int rezultat = factor();

   while(s[i] == '*' || s[i] == '/')

   {

       switch(s[i])

       {

           case '*':

            i++;

            rezultat *=factor();

            break;

           case '/':

            i++;

            rezultat /=factor();

            break;

       }

   }

   return rezultat;

}
long factor() {

    if(s[i] == '(')

    {

        i++;

        int rez = eval();

        i++;

        return rez;

    }

    int rez = 0;

    while(isdigit(s[i]))

    {

        rez = rez*10 + (s[i++]-'0');

    }

    return rez;

}







int main() {



    fgets(s, MAX, fopen("evaluare.in", "r"));

    fprintf(fopen("evaluare.out", "w"), "%ld\n", eval());



    return 0;



}
