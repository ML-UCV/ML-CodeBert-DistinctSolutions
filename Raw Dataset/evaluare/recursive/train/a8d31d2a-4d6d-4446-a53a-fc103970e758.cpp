#include <bits/stdc++.h>

using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

string s;

int eval();
int termen();
int factor();

int pos = 0;
int n;

int eval()
{
 int r = termen();

 while(pos < n && (s[pos] == '+' || s[pos] == '-'))
 {
  if(s[pos] == '+')
  {
   ++pos;
   r += termen();
  }
  else
  {
   ++pos;
   r -= termen();
  }
 }

 return r;
}

int termen()
{
 int f = factor();

 while(pos < n && (s[pos] == '*' || s[pos] == '/'))
 {
  if(s[pos] == '*')
  {
   ++pos;
   f *= factor();
  }
  else
  {
   ++pos;
   f /= factor();
  }
 }

 return f;
}

int factor()
{
 int e = 0;

 if(s[pos] == '(')
 {
  ++pos;
  e = eval();
  ++pos;

  return e;
 }
 else
 {
  while(s[pos] >= '0' && s[pos] <= '9')
  {
   e = e * 10 + s[pos] - '0';
   ++pos;
  }

  return e;
 }
}

main()
{
 fin >> s;
 n = s.size();
 fout << eval();

}
