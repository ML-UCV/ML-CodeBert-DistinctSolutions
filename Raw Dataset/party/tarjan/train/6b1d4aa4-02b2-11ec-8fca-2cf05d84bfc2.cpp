#include<fstream>
#include<cstdlib>
using namespace std;

ifstream fi("party.in");

ofstream fo("party.out");



const int maxz = 1005;

const int maxn = 105;



bool este[maxn];

int i,n,m,x,y,z;

int nr=0;



struct triplet{

       int x,y,z;



       bool verific(){

                      if(z==0) return(este[x] || este[y]);

                      if(z==1) return(este[x] || !este[y]);

                      if(z==2) return(!este[x] || este[y]);

                      if(z==3) return(!(este[x] && este[y]));

                      return 1;

                     }



       void select_random(){

                            int r=rand()%2;

                            if(r==0) este[x]=!este[x];

                            else este[y]=!este[y];

                           }

};



triplet t[maxz];



int main(){

    fi>>n>>m;

    for(i=1;i<=m;i++) fi>>t[i].x>>t[i].y>>t[i].z;

    for(i=1;i<=n;i++) este[i]=1;



    i=1;

    while(i<=m){

                if(!t[i].verific()){ t[i].select_random(); i=1; }

                else i++;

               }



    for(i=1;i<=n;i++) if(este[i]) nr++;

    fo<<nr<<"\n";

    for(i=1;i<=n;i++) if(este[i]) fo<<i<<"\n";



    fi.close();

    fo.close();

    return 0;

}
