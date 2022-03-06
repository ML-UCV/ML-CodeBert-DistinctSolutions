#include <string>
#include <stack>
#include <fstream>


std::ifstream in("evaluare.in");

std::ofstream out("evaluare.out");





int Priority(char x)

{

 if (x == '+' || x == '-')

  return 1;

 if (x == '*' || x == '/')

  return 2;



 return 0;

}







int ApplyOperator(int a, int b, char op)

{

 switch (op)

 {

  case '+': return a + b;

  case '-': return a - b;

  case '*': return a * b;

  case '/': return a / b;

 }

}



int Evaluate(std::string& Stream)

{

 int i;





 std::stack<int> Valori;





 std::stack<char> Operatori;



 int n = Stream.length();



 for (i = 0; i < n; i++)

 {

  if (Stream[i] == '(')

  {

   Operatori.push(Stream[i]);

  }





  else if (isdigit(Stream[i]))

  {

   int numar = 0;



   while (i < Stream.length() && isdigit(Stream[i]))

   {

    numar = (numar * 10) + (Stream[i] - '0');

    i++;

   }

   i--;



   Valori.push(numar);

  }





  else if (Stream[i] == ')')

  {



   while(!Operatori.empty() && Operatori.top() != '(')

   {

    int val2 = Valori.top();

    Valori.pop();



    int val1 = Valori.top();

    Valori.pop();



    char op = Operatori.top();

    Operatori.pop();



    Valori.push(ApplyOperator(val1, val2, op));

   }





   Operatori.pop();

  }



  else

  {
   while (!Operatori.empty() && Priority(Operatori.top()) >= Priority(Stream[i]))

   {

    int val2 = Valori.top();

    Valori.pop();



    int val1 = Valori.top();

    Valori.pop();



    char op = Operatori.top();

    Operatori.pop();



    Valori.push(ApplyOperator(val1, val2, op));

   }



   Operatori.push(Stream[i]);

  }



 }



 while (!Operatori.empty())

 {



  int val2 = Valori.top();

  Valori.pop();



  int val1 = Valori.top();

  Valori.pop();



  char op = Operatori.top();

  Operatori.pop();



  Valori.push(ApplyOperator(val1, val2, op));

 }



 return Valori.top();

}



int main()

{

 std::string Stream;

 in >> Stream;

 out << Evaluate(Stream);

}
