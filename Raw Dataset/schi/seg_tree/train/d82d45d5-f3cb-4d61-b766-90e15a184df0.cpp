#include<fstream>


using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

const int Nmax = 30005;

int N,v[Nmax],res[Nmax],A[16*Nmax];

int Query(int amo,int st,int dr,int i)

{

    if(st==dr) return st;

    int mij=(st+dr)/2;

    if(amo <= A[2*i])

        return Query(amo,st,mij,2*i);

    else

    {

        amo-=A[2*i];

        return Query(amo,mij+1,dr,2*i+1);

    }

}

void Update(int wh,int val,int st,int dr,int i)

{

    A[i]+=val;

    if(st==dr) return;

    int mij=(st+dr)/2;

    if(wh<=mij) Update(wh,val,st,mij,2*i);

    else Update(wh,val,mij+1,dr,2*i+1);

}

int main(){

    in>>N;

    for(int i=1;i<=N;i++)

    {

        in>>v[i];

        Update(i,1,1,N,1);

    }

    for(int i=N;i>=1;i--)

    {

        int wh=Query(v[i],1,N,1);

        res[wh]=i;

        Update(wh,-1,1,N,1);

    }

    for(int i=1;i<=N;i++)

        out<<res[i]<<'\n';

    return 0;

}
