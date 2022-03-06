#include <fstream>
#include <cstring>
using namespace std;



const int NMAX = 100005;

int n;

char s[NMAX];

int st[NMAX], top;



inline bool isDigit(char ch)

{

 return '0' <= ch && ch <= '9';

}



int main()

{

 ifstream fin("evaluare.in");

 ofstream fout("evaluare.out");

 fin >> (s + 1);

 n = strlen(s + 1);

 s[0] = '(';

 s[n + 1] = ')';

 ++n;

 for (int i = 0;i <= n;++i)

 {

  if (s[i] == '+')

   continue;

  else if (s[i] == '-')

   st[++top] = 1000000002;

  else if (s[i] == '*')

   st[++top] = 1000000003;

  else if (s[i] == '/')

   st[++top] = 1000000004;

  else if (s[i] == '(')

   st[++top] = 1000000001;

  else if (s[i] == ')')

  {

   int x = 0;

   while (top > 0 && st[top] != 1000000001)

    x += st[top--];

   --top;

   if (top == 0)

    st[++top] = x;

   else if (st[top] == 1000000003)

    --top, st[top] *= x;

   else if (st[top] == 1000000004)

    --top, st[top] /= x;

   else if (st[top] == 1000000002)

    st[top] = -x;

   else

    st[++top] = x;

  }

  else

  {

   int x = 0;

   while (i <= n && isDigit(s[i]))

    x = x * 10 + (s[i++] - '0');

   --i;

   if (top == 0)

    st[++top] = x;

   else if (st[top] == 1000000003)

    --top, st[top] *= x;

   else if (st[top] == 1000000004)

    --top, st[top] /= x;

   else if (st[top] == 1000000002)

    st[top] = -x;

   else

    st[++top] = x;

  }

 }

 fout << st[1] << "\n";

 fin.close();

 fout.close();

 return 0;

}
