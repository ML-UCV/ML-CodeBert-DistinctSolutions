#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

char x[100001];
int i, lg;

int factor();
int produs();
int suma();

int factor()
{
    int r;
    if (x[i] == '(')
    {
        i++;
        r = suma();
        i++;
    }
    else
    {

        r = 0;
        while (i<lg && isdigit(x[i]))
        {
            r = r*10 + x[i] - 48;
            i++;
        }

    }
    return r;
}

int produs()
{
    int p = factor(), op;

    while (i<lg && (x[i] == '*' || x[i] == '/'))
    {
        if (x[i] == '*')
            op = 0;
        else
            op = 1;
        i++;
        if (op == 0)
            p = p * factor();
        else
            p = p / factor();
    }
    return p;
}

int suma()
{
    int r = produs(), op;

    while (i<lg && (x[i] == '+' || x[i] == '-'))
    {
        if (x[i] == '+') op = 0;
        else op = 1;
        i++;
        if (op == 0) r = r + produs();
        else r = r - produs();
    }
    return r;
}

int main()
{
    fin >> x;
    lg = strlen(x);
    fout << suma();
    return 0;
}
