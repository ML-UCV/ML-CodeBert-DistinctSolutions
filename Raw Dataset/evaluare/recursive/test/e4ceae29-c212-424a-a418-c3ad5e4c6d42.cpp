#include <iostream>
#include <fstream>




using namespace std;



char expr[1000100], *p = expr;



long expresie();

long termen();



long eval()

{

 long r = termen();



 while (*p == '+' || *p == '-')

 {



  switch (*p)

  {

  case '+': ++p;

   r = r + termen();

   break;



  case '-': ++p;

   r = r - termen();

   break;



  }





 }

 return r;

}



long termen()

{



 long r = expresie();



 while (*p == '*' || *p == '/')

 {

  switch (*p)

  {

  case '*': ++p;

   r = r * expresie();

   break;



  case '/': ++p;

   r = r / expresie();

   break;

  }





 }



 return r;



}



long expresie()

{



 long r = 0;



 if (*p == '(')

 {

  ++p;

  r = eval();

  ++p;

 }

 else

 {

  while (*p >= '0' && *p <= '9')

  {

   r = r * 10 + *p - '0';

   p++;



  }



 }



 return r;





}
void citire()

{

   ifstream in("evaluare.in");



 in.getline(expr, 1000100);







   in.close();



}



int main()

{

 citire();

 ofstream out("evaluare.out");



 out << eval();







 out.close();



 return 0;

}
