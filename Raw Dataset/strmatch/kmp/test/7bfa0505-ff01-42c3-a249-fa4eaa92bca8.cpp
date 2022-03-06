#include <fstream>
#include <string>
using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

string s, w;


int t[2000001], n, m;


void precalc()
{
    int i, k = 0;
    t[0] = -1;
    for (i = 1; i<w.size(); i++, k++)
    {
        if (w[k] == w[i])
            t[i] = t[k];
        else
        {
            t[i] = k;
            while (k >= 0 && w[i] != w[k])
                k = t[k];
        }
    }
    t[w.size()] = k;
}

int ap[1001];

int main()
{
    fin >> w >> s;
    precalc();
    int i, k = -1;
    for (i = 0; i<s.size(); i++)
    {
        while (k >= 0 && w[k] != s[i])
            k = t[k];
        if (k < 0)
            k = 0;
        if (w[k] == s[i])
        {
            k++;
            if (k == w.size())
            {
                ap[0]++;
                if (ap[0] <= 1000)
                    ap[ap[0]] = i-k+1;
                k = t[k];
            }
        }
    }
    fout << ap[0] << '\n';
    for (i = 1; i<=min(ap[0], 1000); i++)
        fout << ap[i] << ' ';
    return 0;
}
