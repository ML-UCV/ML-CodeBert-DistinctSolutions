#include <fstream>
#include <iostream>






using namespace std;



int v[100001], n;



int sol;



void Merge(int mat[], int st, int mij, int dr)

{

    int L[100001], D[100001];

    int i, j, k;

    int n1 = mij - st + 1;

    int n2 = dr - mij;



    for(i = 0; i < n1; i++)

    {

        L[i] = mat[st + i];





    }



    for(i = 0; i < n2; i++)

        D[i] = mat[mij + 1 + i];



    i = j = 0;

    k = st;

    int contor = 0;



    while(i < n1 && j < n2)

    {

        if(L[i] > D[j])

        {

            mat[k] = D[j];



            sol += j - i + n1 - contor;

            j++;

            contor++;

            sol %= 9917;

        }

        else

        {

            mat[k] = L[i];



            i++;

        }



        k++;

    }



    while(i < n1)

    {

        mat[k] = L[i];



        i++;

        k++;

    }



    while(j < n2)

    {

        mat[k] = D[j];



        j++;

        k++;

    }

}



void MergeSort(int mat[], int st, int dr)

{

    if(st < dr)

    {

        int mij = st + (dr - st) / 2;

        MergeSort(mat, st, mij);

        MergeSort(mat, mij + 1, dr);



        Merge(mat, st, mij, dr);

    }



}



int main()

{

    int i, j;



    ifstream fin("inv.in");

    ofstream fout("inv.out");



    fin >> n;



    for(i = 1; i <= n; i++)fin >> v[i];



    MergeSort(v, 1, n);



    fout << sol;



    fin.close();

    fout.close();



    return 0;

}
