#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



int N,M,cT;

int T[200005],R[200005];

struct Muchie{int x,y,c;}V[400005];

vector< pair<int,int> >mArb;



bool comp(Muchie a, Muchie b)

{

    return a.c<b.c;

}



void citire()

{

    fin>>N>>M;

    for(int i=1;i<=M;i++)

        fin>>V[i].x>>V[i].y>>V[i].c;

    sort(V+1,V+M+1,comp);

}



int parinte(int vf)

{

    if(!T[vf])

        return vf;

    int p=parinte(T[vf]);

    T[vf]=p;

    return p;

}



void unire(int pA, int pB)

{

    if(R[pA]<R[pB])

        T[pA]=pB;

    else

    {

        T[pB]=pA;

        if(R[pA]==R[pB])

            R[pA]++;

    }

}



void rezolvare()

{

    for(int i=1;i<=M;i++)

    {

        int pX=parinte(V[i].x),pY=parinte(V[i].y);

        if(pX!=pY)

        {

            unire(pX,pY);

            mArb.push_back({V[i].x,V[i].y});

            cT+=V[i].c;

        }

    }

    fout<<cT<<'\n'<<mArb.size()<<'\n';

    for(unsigned i=0;i<mArb.size();i++)

        fout<<mArb[i].first<<" "<<mArb[i].second<<'\n';

}



int main()

{

    citire();

    rezolvare();

    return 0;

}
