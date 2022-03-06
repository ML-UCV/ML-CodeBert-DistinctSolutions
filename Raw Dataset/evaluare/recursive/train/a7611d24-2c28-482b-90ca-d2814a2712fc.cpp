#include <fstream>
#include <string>


using namespace std;



ifstream cin("evaluare.in"); ofstream cout("evaluare.out");



string s;

int i;



int f1();

int f2();

int f3();



int f1()

{

 int ans = f2();

 while (s[i] == '+' || s[i] == '-')

 {

  if (s[i] == '+')

  {

   i++;

   ans = ans + f2();

  }

  else

  {

   i++;

   ans = ans - f2();

  }

 }

 return ans;

}



int f2()

{

 int ans = f3();

 while (s[i] == '*' || s[i] == '/')

 {

  if (s[i] == '*')

  {

   i++;

   ans = ans * f3();

  }

  else

  {

   i++;

   ans = ans / f3();

  }

 }

 return ans;

}



int f3()

{

 int ans = 0;

 if (s[i] == '(')

 {

  i++;

  ans = f1();

  i++;

 }

 else

 {

  while (i < s.size() && s[i] >= '0' && s[i] <= '9')

  {

   ans = ans * 10 + (s[i] - '0');

   i++;

  }

 }

 return ans;

}





int main()

{

 cin >> s;

 cout << f1();

 return 0;

}
