#include <fstream>
using namespace std;

ifstream cin("stramosi.in");
ofstream cout("stramosi.out");

int n,q,d[18][250001],a,b;

int main()
{
 cin>>n>>q;

 for(int i=1;i<=n;i++)
  cin>>d[0][i];
 for(int k=1;k<=17;k++){
  for(int i=1;i<=n;i++){
   d[k][i]=d[k-1][d[k-1][i]];
  }
 }
 while(q--){
  cin>>a>>b;
  for(int i=17;i>=0;i--)
   if ( (b & (1 <<i)) == (1 << i)) {
    a=d[i][a];
   }
  cout<<a<<'\n';
 }
}
