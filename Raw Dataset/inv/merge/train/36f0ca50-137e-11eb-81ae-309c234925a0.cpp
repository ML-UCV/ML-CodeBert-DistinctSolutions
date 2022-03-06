#include <iostream>
#include <fstream>




using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



int nr=0,n,S[100005];







void interclasare(int arr[], int s, int d)

{

    int mijl = (s + d) / 2;



    int i = s;

    int j = mijl + 1;

    int k = 0;





    int size = d - s + 1;

    int c[size];



    while (i <= mijl && j <= d) {

        if (arr[i] <= arr[j]) {

            c[k] = arr[i];

            k++;

            i++;

        }

        else {



            nr += mijl - i + 1;

            nr = nr % 9917;

            c[k] = arr[j];

            k++;

            j++;

        }

    }

    while (i <= mijl) {

        c[k] = arr[i];

        k++;

        i++;

    }

    while (j <= d) {

        c[k] = arr[j];

        k++;

        j++;

    }

    for (i = 0; i < k; i++) {

        arr[s+i] = c[i];

    }



}



void merge_sort(int arr[], int s, int d)

{

    int mijl;

    if (s < d){



        mijl = (s+d) / 2;

        merge_sort(arr,s,mijl);

        merge_sort(arr,mijl+1,d);



        interclasare(arr,s,d);

    }

}



int main()

{

    f>>n;

    for(int i=0; i<n; ++i)

    {

        f>>S[i];

    }

    f.close();

    merge_sort(S, 0, n-1);

    g << nr % 9917;

    g.close();

    return 0;

}
