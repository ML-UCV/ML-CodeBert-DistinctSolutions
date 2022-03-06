#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream cin("strmatch.in");
ofstream cout("strmatch.out");

const int NMAX = 2e6;

int M, N;
char a[NMAX + 2], b[NMAX + 2];
int pi[NMAX + 2];

void ComputePi()
{
    int j = 0;

    for(int i = 2; i <= M; i++)
    {
        while(j && a[i] != a[j + 1])
            j = pi[j];

        if(a[i] == a[j + 1])
            j++;

        pi[i] = j;
    }
}

int nrm;
vector <int> m;

void Kmp()
{
    int j = 0;

    for(int i = 1; i <= N; i++)
    {
        while(j && b[i] != a[j + 1])
            j = pi[j];

        if(b[i] == a[j + 1])
            j++;

        if(j == M)
        {
            nrm++;
            if(m.size() < 1000)
                m.push_back(i - M);
            j = pi[j];
        }
    }
}

int main()
{
    cin >> (a + 1) >> (b + 1);
    M = strlen(a + 1);
    N = strlen(b + 1);

    ComputePi();

    Kmp();

    cout << nrm << '\n';
    for(auto it : m)
        cout << it << ' ';

    return 0;
}
