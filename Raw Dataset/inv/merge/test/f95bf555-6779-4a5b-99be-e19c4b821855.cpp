#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int MOD = 9917;

int a[100005], b[100005], sol;

ifstream fin ("inv.in");

ofstream fout ("inv.out");

void Merge (int left, int right, int m)

{

    int i, j, k = 0;

    i = left;

    j = m + 1;

    while (i <= m && j <= right)

        if (a[i] <= a[j]) b[++k] = a[i++];

        else

        {

            sol = (sol + (m - i + 1)) % MOD;

            b[++k] = a[j++];

        }

    while (i <= m)

        b[++k] = a[i++];

    while (j <= right)

        b[++k] = a[j++];

    j = 1;

    for (i = left; i <= right; i++)

        a[i] = b[j++];

}



void MergeSort (int left, int right)

{

    if (right - left <= 1)

    {

        if (a[right] < a[left])

        {

            swap (a[left], a[right]);

            sol++;

            sol %= MOD;

        }

    }

    else

    {

        int m = (left + right) / 2;

        MergeSort(left, m);

        MergeSort(m + 1, right);

        Merge(left, right, m);

    }

}



int main()

{

    int n;

    fin >> n;

    for (int i = 1; i <= n; i++)

        fin >> a[i];

    MergeSort(1, n);

    fout << sol << "\n";

    fout.close();

    return 0;

}
