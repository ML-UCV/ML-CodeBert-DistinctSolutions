#include <fstream>
#include <cstring>
#include <list>


using namespace std;



ifstream fin ("swap.in");

ofstream fout ("swap.out");



list<int> l[30];



int A[50010],v[50010],i,j,n,m,rez;



char a[50010],b[50010];



void query (int x) {



    for (int i=x;i>0;i-=(i&(-i)))

        rez+=A[i];



}



void update (int x) {



    for (int i=x;i<=n;i+=(i&(-i)))

        A[i]++;

}





int main () {



    fin>>a;

    fin>>b;

    n=strlen(a);

    for (i=0;i<n;i++)

        l[a[i]-'a'].push_back(i+1);



    m=strlen (b);



    for (i=0;i<m;i++) {

        if (l[b[i]-'a'].empty()){

            fout<<"-1\n";

            return 0;

        }

        v[i+1]=*l[b[i]-'a'].begin();

        l[b[i]-'a'].pop_front();

    }

    for (i=1;i<=n;i++)

        v[i]=n-v[i]+1;

    for (i=1;i<=n;i++) {

        query(v[i]);

        update (v[i]);

    }

    fout<<rez<<"\n";



    return 0;

}
