#include<fstream>
using namespace std;

    ifstream f("inv.in");

    ofstream g("inv.out");



int n;

long long nr_permutari;

const int MOD = 9917;



void afisare(int a[], int size_array){

    for(int i = 0 ; i < size_array ; i++){

        g<<a[i]<< " ";

    }

    g<<'\n';

}



void merge_function(int a[], int low, int mid, int high){

    int len1 = mid - low + 1;

    int len2 = high - mid;

    int L[len1], R[len2];

    int i, j;

    for(i = 0 ; i < len1 ; i++)

        L[i] = a[low + i];

    for(i = 0 ; i < len2 ; i++)

        R[i] = a[mid + i + 1];

    i = j = 0;

    int k = low;



    while(i < len1 && j < len2){

        if(L[i] <= R[j])

            a[k++] = L[i++];

        else{

            a[k++] = R[j++];

            nr_permutari += len1 - i;

            nr_permutari %= MOD;

        }

    }

    while(i < len1)

        a[k++] = L[i++];

    while(j < len2){

        a[k++] = R[j++];

    }



}



void mergesort(int a[], int low, int high){

    int mid = low + (high - low) / 2;

    if(low < high){

        mergesort(a, low, mid);

        mergesort(a, mid + 1, high);



        merge_function(a, low, mid, high);

    }

}





int main(){



f>>n;

int a[n];

for(int i = 0 ; i < n ; i++)

    f>>a[i];



mergesort(a, 0, n-1);



g<<nr_permutari % MOD;



return 0;

}
