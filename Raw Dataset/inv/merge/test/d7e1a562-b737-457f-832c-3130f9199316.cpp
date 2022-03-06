#include <iostream>
#include <fstream>




using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");





int v[100000 +2];



int cnt = 0;



void Merge(int st, int mij, int dr)

{

    int aux[100000 +2];

    int i = st, j = mij+1, k = 0;



    while(i <= mij && j <= dr)

    {

        if(v[i] <= v[j])

        {

            aux[k++] = v[i++];

        }

        else

        {

            aux[k++] = v[j++];

            cnt += (mij - i + 1);

            cnt%=9917;

        }

    }



    while(i <= mij)

    {

        aux[k++] = v[i++];

    }



    while(j <= dr)

    {

        aux[k++] = v[j++];

    }



    for(i=st; i<=dr; i++)

    {

        v[i] = aux[i-st];

    }

}





void MergeSort(int st, int dr)

{

    if(st == dr)

    {

        return;

    }

    int mij = (st+dr)/2;

    MergeSort(st, mij);

    MergeSort(mij+1, dr);

    Merge(st, mij, dr);



}



int main()

{

    int n;

    fin>>n;

    for(int i=1; i<=n; i++)

    {

        fin>>v[i];

    }



    MergeSort(1, n);

    fout<<cnt;



    fin.close();

    fout.close();

    return 0;

}
