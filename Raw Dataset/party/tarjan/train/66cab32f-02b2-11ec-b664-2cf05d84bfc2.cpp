#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;



int a1[1003], a2[1003], b1[1003], b2[1003], N, M;

int val[103];



void solve(){



 int l1,l2;



 for(int i=1;i<=M;++i)

 {

  l1 = val[a1[i]]; l2 = val[a2[i]];

  if(b1[i]) l1 ^= 1;

  if(b2[i]) l2 ^= 1;

  if(!l1 && !l2)

  {

   if(rand() % 2)

   {

    val[a1[i]] ^= 1;

   }

   else

   {

    val[a2[i]] ^= 1;

   }

   i = 0;

  }
 }

}



int main(){

 ifstream cin("party.in");

 ofstream cout("party.out");

 int i,j,x,y,z;



 srand(int(time(NULL)));



 cin >> N >> M;



 for(i=1;i<=M;++i)

 {

  cin >> a1[i] >> a2[i] >> z;

  if(z == 1 || z == 3) b2[i] = 1;

  if(z == 2 || z == 3) b1[i] = 1;

 }







 solve();

 int NR = 0;

 for(i=1;i<=N;++i) if(val[i]) ++NR;



 cout << NR << "\n";

 for(i=1;i<=N;++i) if(val[i]) cout << i << "\n";



 return 0;

}
