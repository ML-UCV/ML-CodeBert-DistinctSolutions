#include <fstream>
#include <cstring>
#include <deque>


using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");



int i,n,a,b,nr,sol,poz;

int f1[30],f2[30],v[50005],aint[3*50005];

char A[50005],B[50005];

deque <int> d[30];



void update(int nod, int st, int dr){

    if(st==dr){

        aint[nod]++;

        return;

    }

    int mij=(st+dr)/2;

    if(poz<=mij)

        update(2*nod,st,mij);

    else

        update(2*nod+1,mij+1,dr);

    aint[nod]=aint[2*nod]+aint[2*nod+1];

}



void query(int nod, int st, int dr){

    if(a<=st && dr<=b){

        nr+=aint[nod];

        return;

    }

    int mij=(st+dr)/2;

    if(mij>=a)

        query(2*nod,st,mij);

    if(mij<b)

        query(2*nod+1,mij+1,dr);

}



int main()

{

    fin>>(A+1)>>(B+1);

    n=strlen(A+1);

    for(i=1;i<=n;i++){

        f1[A[i]-'a'+1]++;

        f2[B[i]-'a'+1]++;

        d[B[i]-'a'+1].push_back(i);

    }

    for(i=1;i<=26;i++)

        if(f1[i]!=f2[i]){

            fout<<-1;

            return 0;}

    for(i=1;i<=n;i++){

        v[i]=d[A[i]-'a'+1].front();

        d[A[i]-'a'+1].pop_front();

    }

    for(i=1;i<=n;i++){

        nr=0;

        a=v[i]+1; b=n;

        query(1,1,n);

        sol+=nr;

        poz=v[i];

        update(1,1,n);

    }

    fout<<sol;

    return 0;

}
