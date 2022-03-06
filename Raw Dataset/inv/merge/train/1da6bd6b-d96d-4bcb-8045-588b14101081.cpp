#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inv.in");

ofstream g ( "inv.out");

int nr;



void interclasare(int a[], int l, int r){







int mid= (l + r) / 2;



int i = l;

int j = mid + 1;

int aux = 0;



int size = r - l + 1;

int v[size];



while ( i <= mid and j <= r) {

if (a[i] <= a[j]) {

v[aux] = a [i];

aux++;

i++;

} else {

nr += mid - i + 1;

nr = nr % 9917;

v[aux] = a[j];

aux++;

j++;

}

}



while (i <= mid) {

v[aux] = a[i];

aux++;

i++;

}

while (j <= r) {

        v[aux] = a[j];

aux++;

j++;

}



for (int i= 0; i < aux; ++i) {

a[l+i] = v[i];

}



}



void mergesort(int a[], int l, int r){

if (l == r)

return;

int mid = (l + r) / 2;

mergesort(a, l, mid);

mergesort(a, mid + 1, r);

interclasare(a, l, r);



}



int main() {





int n;

int vt[100005];

f >> n;

for (int i = 0; i < n; ++i) {

f>> vt[i];

}

mergesort(vt, 0, n-1);

g<< nr;

return 0;

}
