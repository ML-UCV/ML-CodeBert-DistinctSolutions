#include <fstream>




using namespace std;



ifstream cin("stramosi.in");

ofstream cout("stramosi.out");

const int NMAX=250099;

long long n,m,a[30][NMAX],p,q,k;



int main(){

cin >>n>>m;

for(int i=1;i<=n;i++) cin>>a[0][i];



for(int i=1;(1<<i)<=n;i++){



 for(int j=1;j<=n;j++){

  a[i][j]=a[i-1][a[i-1][j]];



 }

}

while(m--){

 cin >>q>>p;

 int flag=0;

 while(p){

  if(p %2==1)

    q=a[flag][q];

    flag++;

  p/=2;

 }

 cout <<q<<"\n";

}

return 0;

}
