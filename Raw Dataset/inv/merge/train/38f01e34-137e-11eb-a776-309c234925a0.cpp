#include <fstream>
using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");

int w[100001];

int Interclasare(int v[], int left, int right);
int MergeSort(int v[], int left, int right);

int main()
{
    int n;
    int i;
    fin >> n;
    int v[n];
    for (i = 0; i < n; i++)
        fin >> v[i];
    fout << MergeSort(v, 0, n - 1) % 9917;
    return 0;
}

int MergeSort(int v[], int left, int right)
{
    if (left == right)
    {
        return 0;
    }
    int m = (left + right) / 2;
    int inversiune = 0;
    inversiune += MergeSort(v, left, m);
    inversiune += MergeSort(v, m + 1, right);
    inversiune += Interclasare(v, left, right);
    return inversiune % 9917;
}
int Interclasare(int v[], int left, int right)
{
    int i, j, k;
    int m = (left + right) / 2;
    i = left;
    k = left;
    j = m + 1;
    int inversiune = 0;
    while (i <= m && j <= right)
    {
        if (v[i] <= v[j])
        {
            w[k] = v[i];
            i++;
            k++;
        }
        else
        {
            w[k] = v[j];
            inversiune += m - i + 1;
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        w[k] = v[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        w[k] = v[j];
        k++;
        j++;
    }
    for (k = left; k <= right; k++)
    {
        v[k] = w[k];
    }
    return inversiune % 9917;
}
