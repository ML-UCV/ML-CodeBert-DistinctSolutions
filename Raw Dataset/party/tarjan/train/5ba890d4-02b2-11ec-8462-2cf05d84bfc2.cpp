#include <fstream>


using namespace std;



struct cerinta {

    int x, y, z;}

    a[1100];

int v[150];

int N,k, M, ok, i, X, Y, Z ;

    ifstream fin("party.in");

    ofstream fout("party.out");

int main()

{



    fin>>N>>M;

    for(i=1;i<=N;i++)v[i]=1;

    for(i=1;i<=M;i++)fin>>a[i].x>>a[i].y>>a[i].z;

    ok=0;

    while(ok==0){

    ok=1;

    for (i=1;i<=M;i++){

    X=a[i].x, Y=a[i].y, Z=a[i].z;

if(Z==0)

if(v[X]==0 && v[Y]==0){v[X]=1;v[Y]=1;ok=0;break;}

if(Z==1)

if(v[X]==0 && v[Y]!=0){v[Y]=0;ok=0;break;}

if(Z==2)

if(v[Y]==0 && v[X]!=0){v[X]=0;ok=0;break;}

if(Z==3)

if(v[X]==1 && v[Y]==1){v[Y]=0;ok=0;break;}

}}

    for(i=1;i<=N;i++)

    if(v[i])k++;

    fout<<k<<'\n';

    for(i=1;i<=N;i++)

    if(v[i])fout<<i<<'\n';

    return 0;

}
