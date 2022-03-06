#include <iostream>
#include<fstream>
#include<algorithm>


struct ura{

int x, y, c;

}v[400001], sol[200001];



using namespace std;

bool cmp(ura a, ura b) {

    return a.c<b.c;

}

int sef[200001];

int sefsup(int poz) {

    if(sef[poz]==poz) {

            return poz;

    }

    else {

            return sef[poz]=sefsup(sef[poz]);

    }

}



void unire(int p1, int p2) {

    int sefx=sefsup(p1);

    int sefy=sefsup(p2);

    sef[sefy]=sefx;

}

int main() {

    int i, n, m, s, k;



    ifstream fin("apm.in");

    ofstream fout("apm.out");

    fin>>n>>m;

    for(i=1;i<=m;i++) {

            fin>>v[i].x>>v[i].y>>v[i].c;

    }

    for(i=1;i<=n;i++) {

            sef[i]=i;

    }

    sort(v+1, v+m+1, cmp);

    s=0;

    k=1;

    for(i=1;i<=m && k<=n-1;i++) {

            if(sefsup(v[i].x)!=sefsup(v[i].y)) {

                    sol[k]=v[i];

                    unire(v[i].x, v[i].y);

                    s=s+v[i].c;

                    k++;

            }

    }

    fout<<s<<"\n"<<n-1<<"\n";

    for(i=1;i<n;i++) {

            fout<<sol[i].x<<" "<<sol[i].y<<"\n";

    }

    return 0;

}
