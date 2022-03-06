#include <fstream>
#include <string>


using namespace std;



string sir;

int poz;



int expresie();

int termen();

int factor();



int expresie()

{

  int val = termen();



  while (sir[poz] == '+' || sir[poz] == '-')

  {

    if (sir[poz] == '+')

    {

      poz++;

      val += termen();

    }

    else

    {

      poz++;

      val -= termen();

    }

  }



  return val;

}



int termen()

{

  int val = factor();



  while (sir[poz] == '*' || sir[poz] == '/')

  {

    if (sir[poz] == '*')

    {

      poz++;

      val *= factor();

    }

    else

    {

      poz++;

      val /= factor();

    }

  }



  return val;

}



int factor()

{

  int val = 0;



  if (sir[poz] == '(')

  {

    poz++;

    val = expresie();

    poz++;

  }

  else

  {

    while (poz < sir.size() && '0' <= sir[poz] && sir[poz] <= '9')

    {

      val = val * 10 + (int)(sir[poz] - '0');

      poz++;

    }

  }



  return val;

}



int main()

{

  ifstream in("evaluare.in");

  ofstream out("evaluare.out");



  in >> sir;



  out << expresie();



  return 0;

}
