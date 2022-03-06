#include <fstream>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int n,v[30005],i,poz;

short aib[30005],sol[30005];

inline int query(int poz){

   int r=0;

    for(;poz;poz-=poz&-poz)

        r+=aib[poz];

    return r;

}

inline void update(int poz,int val){

for(;poz<=n;poz+=poz&-poz)

    aib[poz]+=val;

}

inline int solve(int x){

int st=1,dr=n,mid;

while(st<=dr){

     mid=(st+dr)/2;

    if(query(mid)>=x)

      dr=mid-1;

      else st=mid+1;

}

return st;

}

int main(){



fin>>n;

for(i=1;i<=n;i++){

    fin>>v[i];

    update(i,1);

}

for(i=n;i>=1;i--){

    poz=solve(v[i]);

    sol[poz]=i;

    update(poz,-1);

}

for(i=1;i<=n;i++)

    fout<<sol[i]<<'\n';

}
