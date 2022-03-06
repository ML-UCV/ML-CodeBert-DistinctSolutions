#include <bits/stdc++.h>
using namespace std;





ifstream fin("schi.in");

ofstream fout("schi.out");
const int MAXN=4e4;

int n, place;

int arbore[MAXN*4];

int v[MAXN], sol[MAXN];





void build(int left, int right, int nod)

{

    if(left==right)

    {

        arbore[nod]=1;

        return;

    }

    int mij=(left+right)/2;

    build(left, mij, nod*2);

    build(mij+1, right, nod*2+1);

    arbore[nod]=arbore[nod*2]+arbore[nod*2+1];

}



int query(int kel, int left, int right, int nod)

{

    if(left==right)

        return left;

    int mij=(left+right)/2;

    if(arbore[2*nod]>=kel)

        return query(kel, left, mij, nod*2);

    return query(kel-arbore[nod*2], mij+1, right, nod*2+1);

}





void update(int pos, int left, int right, int nod)

{

    arbore[nod]--;

    if(left==right)

        return;

    int mij=(left+right)/2;

    if(pos<=mij)

        update(pos, left, mij, nod*2);

    else

        update(pos, mij+1, right, nod*2+1);

}
int main()

{

    fin>>n;

    for(int i=1; i<=n; i++)

        fin>>v[i];

    build(1,n,1);

    for(int i=n; i>=1; i--)

    {

        place=query(v[i], 1, n, 1);

        update(place, 1, n, 1);

        sol[place]=i;

    }

    for(int i=1; i<=n; i++)

        fout<<sol[i]<<"\n";



    return 0;

}
