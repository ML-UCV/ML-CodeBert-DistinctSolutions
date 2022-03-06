#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("inv.in"); ofstream fout("inv.out");

int merge(int v[] , int left , int mid , int right)
{
    int i = left , j = mid , k = left , temp[200200];
    int count = 0;
    while (i<=mid-1 && j<=right)
    {
        if(v[i] <= v[j])
        {
            temp[k] = v[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = v[j];
            j++; k++;
            count += (mid - i);
        }
    }
    while(i<=mid-1)
    {
        temp[k] = v[i];
        i++; k++;
    }
    while(j<=right)
    {
        temp[k] = v[j];
        j++; k++;
    }
    for(i=left ; i<=right ; i++)
        v[i] = temp[i];
    return count;
}

int mergesort(int v[], int left, int right)
{
    int mid, count = 0;

    if(right > left)
    {
        mid = (right + left)/2;
        count = mergesort(v , left , mid) % 9917;
        count += mergesort(v , mid+1 , right) % 9917;
        count += merge(v , left , mid+1 , right) % 9917;
    }
    return count;
}

int main()
{
    int n , v[200200];
    fin >> n;
    int temp[n];
    for(int i=0 ; i<n ; i++)
        fin >> v[i];
    int ans = mergesort(v , 0 , n-1) % 9917;
    fout << ans;
}
