#include <fstream>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int merge(int arr[], int l, int m, int r)

{

    int i, j, k;

    int n1 = m - l + 1;

    int n2 = r - m;

    int inv = 0;

    int L[n1], R[n2];



    for (i = 0; i < n1; i++)

        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)

        R[j] = arr[m + 1+ j];



    i = 0;

    j = 0;

    k = l;

    while (i < n1 && j < n2)

    {

        if (L[i] <= R[j])

        {

            arr[k] = L[i];

            i++;

            inv += j;

            inv %= 9917;

        }

        else

        {

            arr[k] = R[j];

            j++;

        }

        k++;

    }



    while (i < n1)

    {

        arr[k] = L[i];

        i++;

        k++;

        inv += j;

        inv %= 9917;

    }



    while (j < n2)

    {

        arr[k] = R[j];

        j++;

        k++;

    }

    inv %= 9917;

    return inv;

}



int mergeSort(int arr[], int l, int r)

{

    if (l < r)

    {

        int m = l+(r-l)/2;

        int inv = 0;



        inv += mergeSort(arr, l, m);

        inv %= 9917;

        inv += mergeSort(arr, m+1, r);

        inv %= 9917;



        inv += merge(arr, l, m, r);

        inv %= 9917;

        return inv;

    }

    return 0;

}



int v[100000];



int main()

{

    int n;

    fin >> n;

    for(int i = 0; i < n; i++)

        fin >> v[i];

    int inv = mergeSort(v, 0, n-1);

    inv %= 9917;

    fout << inv;

    return 0;

}
