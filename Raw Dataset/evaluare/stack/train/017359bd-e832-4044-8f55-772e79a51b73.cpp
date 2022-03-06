#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

char x[100001];
int i, lg;

int nr();
int prod();
int suma();

int main()
{
    fin >> x;
    lg = strlen(x);
    fout << suma();
    return 0;
}

int nr()
{
    int r = 0;
    if (x[i] == '(')
    {
        i++;
        r = suma();
        i++;
    }
    else
    {
        while (isdigit(x[i]))
        {
            r = r * 10 + x[i] - 48;
            i++;
        }
    }
    return r;
}

int produs()
{
    int r = nr();
    while (i<lg && (x[i] == '*' || x[i] == '/'))
    {
        i++;
        if (x[i-1] == '*')
            r = r * nr();
        else
            r = r / nr();
    }
    return r;
}

int suma()
{
    int r = produs();
    while (i<lg && (x[i] == '+' || x[i] == '-'))
    {
        i++;
        if (x[i-1] == '+')
            r = r + produs();
        else
            r = r - produs();
    }
    return r;
}
