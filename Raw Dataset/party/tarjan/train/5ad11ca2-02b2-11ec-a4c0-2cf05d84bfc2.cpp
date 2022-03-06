#include <fstream>


using namespace std;



struct cerinta {

    int x, y, z;

    }A[1024];

int P[128];

int n, m, ok, i, X, Y, Z, k;

int main()

{

    ifstream fin("party.in");

    ofstream fout("party.out");

    fin>>n>>m;

    for(i=1;i<=n;i++)

        P[i]=1;

    for(i=1;i<=m;i++)

        fin>>A[i].x>>A[i].y>>A[i].z;

    ok=0;

    while(ok==0){

    ok=1;

    for (i=1;i<=m;i++){

    X=A[i].x, Y=A[i].y, Z=A[i].z;

if(Z==0)

if(P[X]==0 && P[Y]==0)

    {P[X]=1;P[Y]=1;ok=0;break;}

if(Z==1)

if(P[X]==0 && P[Y]!=0)

   {P[Y]=0;ok=0;break;}

if(Z==2)

if(P[Y]==0 && P[X]!=0)

   {P[X]=0;ok=0;break;}

if(Z==3)

if(P[X]==1 && P[Y]==1)

   {P[Y]=0;ok=0;break;}

}}

    for(i=1;i<=n;i++)

    if(P[i])k++;

    fout<<k<<endl;

    for(i=1;i<=n;i++)

    if(P[i])fout<<i<<endl;



}
