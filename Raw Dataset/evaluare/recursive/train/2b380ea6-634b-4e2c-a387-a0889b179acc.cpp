#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;





char ex[100010],*p = ex;



long termen();



long factor();



long eval(){

 long r = termen();

 while(*p == '+' || *p == '-'){

  if(*p == '+'){

   ++p;

   r += termen();



  }

  if(*p == '-'){

   ++p;

   r -= termen();



  }

 }

 return r;



}



long termen(){

 long r = factor();

 while(*p == '*' || *p == '/'){

  if(*p == '*'){

   ++p;

   r *= factor();



  }

  if(*p == '/'){

   ++p;

   r /= factor();

     }



 }

 return r;

}



long factor(){

 long r = 0;

 if(*p == '('){

  ++p;

  r = eval();

  ++p;

 }else{

  while(*p >= '0' && *p <= '9'){

   r = r*10 + *p - '0';

   ++p;



  }

 }

 return r;



}



int main(){



 fgets(ex, 100010, fopen("evaluare.in", "r"));

    fprintf(fopen("evaluare.out", "w"), "%ld\n", eval());

    return 0;

}
