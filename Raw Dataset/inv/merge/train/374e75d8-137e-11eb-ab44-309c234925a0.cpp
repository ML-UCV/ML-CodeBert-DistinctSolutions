#include <bits/stdc++.h>

std::ifstream fin("inv.in");
std::ofstream fout("inv.out");

int n, inversions, v[100001];

void merge(int v[], int left, int right)
{
    int mid = (left + right) / 2;
    int i = left, j = mid + 1;
    int aux[right - left + 1], index = 0;
    while(i <= mid && j <= right)
        if(v[i] <= v[j])
            aux[index++] = v[i++];
        else
        {
            aux[index++] = v[j++];
            inversions += (mid - i + 1);
            inversions = inversions % 9917;
        }

    while(i <= mid)
        aux[index++] = v[i++];
    while(j <= right)
        aux[index++] = v[j++];

    for(i = 0; i < index; i++)
        v[left + i] = aux[i];

}

int mergeSort(int v[], int left, int right)
{
    if(left < right)
    {
        mergeSort(v, left, (left + right) / 2);
        mergeSort(v, (left + right) / 2 + 1, right);
        merge(v, left, right);
    }

    return inversions;
}


int main()
{
    fin >> n;
    for(int i = 0; i < n; i++)
        fin >> v[i];
    fout << mergeSort(v, 0, n - 1);

    return 0;
}
