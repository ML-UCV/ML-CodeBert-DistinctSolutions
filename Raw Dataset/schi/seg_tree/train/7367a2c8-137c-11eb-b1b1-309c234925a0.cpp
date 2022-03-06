#include <fstream>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int n, i, a[120002], f[30001], concurent[30001], poz_temp[30001];

void build(int st, int dr, int nod){

    if(st == dr){

        a[nod] = f[st];

        return;

    }

    int mid = (st+dr)/2;

    build(st, mid, 2*nod);

    build(mid+1, dr, 2*nod+1);

    a[nod] = a[2*nod]+a[2*nod+1];

}



void cauta(int st, int dr, int nod, int poz){

    if(st == dr){

        concurent[st] = i;

        f[st]=0;

        int x = nod;

        while(x){

            a[x]--;

            x /= 2;

        }

        return;

    }

    int mid = (st+dr)/2;

    if(poz <= a[2*nod])

        cauta(st, mid, 2*nod, poz);

    else

        cauta(mid+1, dr, 2*nod+1, poz-a[2*nod]);

}



int main(){

    fin>>n;

    for(i=1;i<=n;i++){

        fin>>poz_temp[i];

        f[i] = 1;

    }

    build(1, n, 1);

    for(i=n;i>0;i--){



        cauta(1, n, 1, poz_temp[i]);

    }

    for(i=1;i<=n;i++)

        fout<<concurent[i]<<"\n";

    return 0;

}
