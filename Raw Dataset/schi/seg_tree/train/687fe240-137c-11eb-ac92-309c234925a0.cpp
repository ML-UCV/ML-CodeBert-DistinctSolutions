#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 30005;

ifstream fin("schi.in");
ofstream fout("schi.out");

int n;
int arb[N * 4], init[N], place[N];

void build(int left = 1, int right = n, int index = 1)
{
    if(left == right)
    {
        arb[index] = 1;
        return;
    }

    int mid = (left + right) / 2;
    build(left, mid, index * 2);
    build(mid + 1, right, index * 2 + 1);
    arb[index] = arb[index * 2] + arb[index * 2 + 1];
}

int getPlace(int p, int left = 1, int right = n, int index = 1)
{
    arb[index]--;
    if(left == right)
        return left;

    int mid = (left + right) / 2;
    if(arb[index * 2] >= p)
        return getPlace(p, left, mid, index*2);
    return getPlace(p - arb[index * 2], mid + 1, right, index * 2 + 1);
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> init[i];

    build();

    for(int i = n; i > 0; i--)
    {
        int ans = getPlace(init[i]);
        place[ans] = i;
    }

    for(int i = 1; i <= n; i++)
        fout << place[i] << '\n';
    fout << '\n';

    return 0;
}
