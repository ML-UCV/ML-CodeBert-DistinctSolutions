#include <fstream>
#include <string>

using namespace std;

string sir;

int poz;

int eval();
int termen();
int factor();

int expr()
{
  int val = termen();

  while (poz < sir.size())
  {
    if (sir[poz] == '+')
    {
      ++poz;
      val += termen();
    }
    else if (sir[poz] == '-')
    {
      ++poz;
      val -= termen();
    }
    else
      break;
  }

  return val;
}

int termen()
{
  int val = factor();

  while (poz < sir.size())
  {
    if (sir[poz] == '*')
    {
      ++poz;
      val *= factor();
    }
    else if (sir[poz] == '/')
    {
      ++poz;
      val /= factor();
    }
    else
      break;
  }

  return val;
}

int factor()
{
  int val = 0;

  if (sir[poz] == '(')
  {
    ++poz;
    val = expr();
    ++poz;
  }
  else
  {
    while (poz < sir.size() && '0' <= sir[poz] && sir[poz] <= '9')
    {
      val = val * 10 + (sir[poz] - '0');
      ++poz;
    }
  }

  return val;
}

int main()
{
  ifstream cin("evaluare.in");
  ofstream cout("evaluare.out");

  cin >> sir;

  cout << expr() << '\n';

  return 0;
}
