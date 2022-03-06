#include <cstdio>
const long MAX = 100010;



char s[MAX];

int i = 0;







long termen();



long factor();
long eval()

{



 long rezultat = factor();



 while ( s[i] =='+' || s[i]=='-' )

    {



  switch ( s[i] )

  {



   case '+':



    ++i;



    rezultat += factor();



    break;



   case '-':



    ++i;



    rezultat -= factor();



    break;



  }



 }



 return rezultat;



}
long termen()

{

    long nr=0;

    while(s[i]>='0' && s[i]<='9')

            nr=nr*10+s[i++]-'0';

    if(s[i]=='(')

    {

        i++;

        nr=eval();

        i++;

    }

    return nr;

}
long factor()

{

    long rezultat=termen();

    while ( s[i] =='*' || s[i]=='/' )

    {



  switch ( s[i] )

  {



   case '*':



    ++i;



     rezultat *= termen();



    break;



   case '/':



    ++i;



    rezultat /= termen();



    break;



  }



 }

 return rezultat;

}







int main() {



    fgets(s, MAX, fopen("evaluare.in", "r"));

    fprintf(fopen("evaluare.out", "w"), "%ld\n", eval());



    return 0;



}
