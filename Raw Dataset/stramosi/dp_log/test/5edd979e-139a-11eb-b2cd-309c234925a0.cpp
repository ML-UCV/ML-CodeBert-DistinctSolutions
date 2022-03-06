#include <fstream>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int d[19][250004];

int n,m,i,p,a,b,j;

int main()

{

 fin>>n>>m;

 for(i=1;i<=n;) fin>>d[0][i++];

 for(i=0;i<18;i++) for(j=1;j<=n;) d[i+1][j]=d[i][d[i][j++]];

 for(;m--;){

fin>>a>>b;

p=0;

while(b) b&(1<<p)?a=d[p][a],b-=(1<<p):0,p++;

fout<<a<<"\n";

}

}
