#include <iostream>
#include <fstream>


using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");





long a[100001];

int n,inv_count;

long Ifinal;



void MergeSort(long a[], int st, int dr)

{

    if(st < dr)

    {

        int mij =(st + dr)/2;



        MergeSort(a,st,mij);

        MergeSort(a,mij+1,dr);





        int k=0;

        int i=st;

        int j=mij+1;



        int temp[100001];

        int inv_count=0;



        while (i <= mij && j<=dr)

            if(a[i]<=a[j])

            {

                temp[k++]=a[i++];

                Ifinal+=inv_count;



            }

            else

            {

                temp[k++]=a[j++];

                inv_count++;



            }



        while(i<=mij)

        {

            temp[k++]=a[i++];

            Ifinal+=inv_count;

        }

        while(j<=dr)

            temp[k++]=a[j++];





        for(i=st; i<=dr; i++)

            a[i]=temp[i-st];

    }

}



long Inv(long a[],int n)

{

    MergeSort(a,0,n-1);

    return Ifinal;

}





int main()

{

    in>>n;

    for(int i=0; i<n; i++)

        in>>a[i];



    out<<Inv(a,n)%9917;



    return 0;

}
