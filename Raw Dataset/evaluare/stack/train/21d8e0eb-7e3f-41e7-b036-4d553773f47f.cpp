#include <fstream>
#include <iostream>
#include <string>
using namespace std;



const int N = 100005;



string a;

int st[N], top;



void Read ()

{

    ifstream fin ("evaluare.in");

    fin >> a;

    fin.close();

}



void Solve ()

{

    int i;

    for (i = 0; a[i];)

    {

        if (a[i] == '+')

            i++;

        else if (a[i] == '(')

        {

            st[++top] = 1e9 + 1;

            i++;

        }

        else if (a[i] == '*')

        {

            st[++top] = 1e9 + 2;

            i++;

        }

        else if (a[i] == '/')

        {

            st[++top] = 1e9 + 3;

            i++;

        }

        else if (a[i] == '-')

        {

            st[++top] = 1e9 + 4;

            i++;

        }

        else if ('0' <= a[i] && a[i] <= '9')

        {

            int x = 0;

            while ('0' <= a[i] && a[i] <= '9')

            {

                x = x * 10 + a[i] - '0';

                i++;

            }

            if (st[top] == 1e9 + 2)

                st[--top] *= x;

            else if (st[top] == 1e9 + 3)

                st[--top] /= x;

            else if (st[top] == 1e9 + 4)

                st[top] = -x;

            else st[++top] = x;

        }

        else

        {

            i++;

            int x = 0;

            while (st[top] != 1e9 + 1)

            {

                x += st[top];

                top--;

            }

            top--;

            if (st[top] == 1e9 + 2)

                st[--top] *= x;

            else if (st[top] == 1e9 + 3)

                st[--top] /= x;

            else if (st[top] == 1e9 + 4)

                st[top] = -x;

            else st[++top] = x;

        }

    }

    int ans = 0;

    for (int i = 1; i <= top; i++)

        ans += st[i];

    ofstream fout ("evaluare.out");

    fout << ans << "\n";

    fout.close();

}



int main()

{

    Read();

    Solve();

    return 0;

}
