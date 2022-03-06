#include <iostream>
#include<fstream>
using namespace std;

ifstream f ("inv.in");

ofstream g ("inv.out");

long long v[100003];

int nr=0,n;

void merge(long long *v,int st, int dr,int mijloc)

{

    int temp[dr-st+1];

    int i=st, j = mijloc+1,k=0;

    while(i<= mijloc and j<=dr)

    {

        if(v[i]<=v[j])

        {

            temp[k++] = v[i];

            i++;

        }

        else

        {

            nr += mijloc - i + 1;

            nr = nr % 9917;

            temp[k++] = v[j];

            j++;

        }



    }

    while(i<=mijloc)

    {

        temp[k++] = v[i];

        i++;

    }

    while(j<=dr)

    {

        temp[k++] = v[j];

        j++;

    }

    for(i=st; i<=dr; i++)

        v[i] = temp[i-st];



}

void mergeSort(long long v[],int st,int dr)

{

    if(st<dr)

    {

        int mijloc = (st+dr)/2;

        mergeSort(v,st,mijloc);

        mergeSort(v,mijloc+1,dr);

        merge(v,st,dr,mijloc);

    }

}

int main()

{

    f>>n;

    for(int i=0; i<n; i++)

        f>>v[i];



    mergeSort(v,0,n-1);





    g<<nr;







    return 0;

}
