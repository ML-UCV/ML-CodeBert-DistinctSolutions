#include <fstream>
using namespace std;

int aux[100001];
int interclasare(int v[], int l, int m, int r, int &nrinv){

    int i = l;
    int j = m+1;
    int h=0;

    while(i <= m && j <= r){
        if(v[i] <= v[j]){
            aux[h] = v[i];
            h++;
            i++;
        }else{
            nrinv += m-i+1;
            nrinv = nrinv % 9917;
            aux[h] = v[j];
            h++;
            j++;
        }
    }

    while(i <= m){
        aux[h] = v[i];
        h++;
        i++;
    }


    while(j <= r) {
        aux[h] = v[j];
        h++;
        j++;
    }

    for(i = l; i <= r;i++)
        v[i] = aux[i-l];

}

void mergeSort(int v[], int l, int r, int &nrInv){

    if(l < r){
        int m = (l+r)/2;

        mergeSort(v, l, m, nrInv);
        mergeSort(v, m+1, r, nrInv);

        interclasare(v, l, m, r, nrInv);
    }
}

int main() {
    ifstream f("inv.in");
    ofstream g("inv.out");

    int n;
    f >> n;

    int v[n];
    for(int i = 0; i < n; i++)
        f >> v[i];

    int nr = 0;
    mergeSort(v, 0, n-1, nr);
    g << nr;
    return 0;
}
