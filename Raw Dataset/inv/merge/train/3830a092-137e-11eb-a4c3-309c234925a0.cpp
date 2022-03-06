#include <iostream>
#include <fstream>


int nr = 0;



void interclasare(int a[], int st, int dr){



int mijloc = (st + dr) / 2;



int i = st;

int j = mijloc + 1;

int aux = 0;



int size = dr - st + 1;

int arr[size];



while ( i <= mijloc and j <= dr) {

if (a[i] <= a[j]) {

arr[aux] = a [i];

aux++;

i++;

} else {

nr += mijloc - i + 1;

nr = nr % 9917;

arr[aux] = a[j];

aux++;

j++;

}

}



while (i <= mijloc) {

arr[aux] = a[i];

aux++;

i++;

}

while (j <= dr) {

arr[aux] = a[j];

aux++;

j++;

}



for (int k = 0; k < aux; ++k) {

a[st+k] = arr[k];

}



}



void mergesort(int a[], int st, int dr){

if (st == dr)

return;

int mijloc = (st + dr) / 2;

mergesort(a, st, mijloc);

mergesort(a, mijloc + 1, dr);

interclasare(a, st, dr);



}



int main() {

std :: ifstream fin("inv.in");

std :: ofstream fout ( "inv.out");



int n;

int vt[100005];

fin >> n;

for (int i = 0; i < n; ++i) {

fin >> vt[i];

}

mergesort(vt, 0, n-1);

fout << nr;

return 0;

}
