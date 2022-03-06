#include <iostream>
#include <fstream>
using namespace std;

const int NMAX = 100000, MD = 9917;
int sir[NMAX + 1];
int mergeSort(int l,int r)
{
    int i, j, k, mid , counter, tmp[NMAX + 1];
    mid = (l + r) / 2;
    i = l;
    j = mid +1;
    k = 0;
    counter = 0;
    while(i <= mid && j <= r)
    {
        if(sir[i] <= sir[j])
        {
            tmp[k] = sir[i++];
        }
        else
        {
            tmp[k] = sir[j++];
            counter += mid -i+1;
            counter %= MD;
        }
        k++;
    }
    while(i <= mid)
    {
        tmp[k] = sir[i++];
        k++;
    }
    while(j <= r)
    {
        tmp[k] = sir[j++];
        k++;
    }
    for(i = l; i <= r; i++)
    {
        sir[i] = tmp[i-l];
    }
    return counter;
}
int inversiuni(int st, int dr)
{
    if (st >= dr)
    {
        return 0;
    }
    int mij, leftInv, rightInv, totalInv;
    mij = (st+dr)/2;
    leftInv = inversiuni(st,mij);
    rightInv = inversiuni(mij+1,dr);
    totalInv = leftInv+rightInv+mergeSort(st,dr);
    return totalInv;
}
int main()
{
    ifstream fin("inv.in");
    ofstream fout("inv.out");
    int n,i;
    fin >> n;
    for(i = 1; i <= n; i++)
    {
        fin >> sir[i];
    }
    fout << inversiuni(1,n) % MD;
    fin.close();
    fout.close();
    return 0;
}
