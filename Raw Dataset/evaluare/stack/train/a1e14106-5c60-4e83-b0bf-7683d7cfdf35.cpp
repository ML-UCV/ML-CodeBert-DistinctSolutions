#include <fstream>
#include <cstring>
#include <stack>


using namespace std;



ifstream f ("evaluare.in");

ofstream g ("evaluare.out");



char s[100005];

int aux[100005];



void Precalc ()

{

 stack < int > stiva;

  for (int i=0; s[i]; i++)

  {

      if (s[i] == '(')

        stiva.push(i);



      if (s[i] == ')')

      {

        aux[stiva.top()] = i;

        stiva.pop();

      }

  }

}



int Solve (int st, int dr)

{

 int numar, k, j, v[100005], rez = 0;

 char semn = '+';

 numar = k = 0;

  for (int i=st; i<=dr; i++)

  {

      if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')

         semn = s[i];



      if (s[i] >= '0' && s[i] <= '9')

      {

          numar = 0, j = i;

           while (s[j] >= '0' && s[j] <= '9')

           {

               numar = numar * 10 + s[j] - '0';

               j ++;

           }

         i = j-1;



         if (semn == '+')

            k ++, v[k] = numar;

         else if (semn == '-')

            k ++, v[k] = -numar;

         else if (semn == '*')

            v[k] = v[k] * numar;

         else if (semn == '/')

            v[k] = v[k] / numar;

      }



      if (s[i] == '(')

      {

        numar = Solve(i+1, aux[i]-1);

         if (semn == '+')

            k ++, v[k] = numar;

         else if (semn == '-')

            k ++, v[k] = -numar;

         else if (semn == '*')

            v[k] = v[k] * numar;

         else if (semn == '/')

            v[k] = v[k] / numar;



         i = aux[i];

      }

  }

  for (int i=1; i<=k; i++)

      rez += v[i];

  return rez;

}



int main()

{

 f >> s;

 Precalc();

 g << Solve(0, strlen(s)-1);

    return 0;

}
