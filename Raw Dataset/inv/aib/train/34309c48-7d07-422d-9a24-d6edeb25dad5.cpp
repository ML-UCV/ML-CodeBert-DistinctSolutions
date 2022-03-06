#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream cin("inv.in");

ofstream cout("inv.out");



int ans,aint[400005],v[100005],n,t,nr,st,dr,s;

vector <int> b;



void query(int nod,int l,int r, int st,int dr){

    if(st<=l && dr>=r){

        s+=aint[nod];

        return;

    }

    int mij=(l+r)>>1;

    if(st<=mij){

        query(nod*2,l,mij,st,dr);

    }

    if(dr>mij){

        query(nod*2+1,mij+1,r,st,dr);

    }

}



void update(int nod,int l,int r,int poz,int val){

    if(l==poz && r==poz){

        aint[nod]+=val;

        return;

    }

    int mij;

    mij=(l+r)>>1;

    if(poz<=mij){

        update(nod*2,l,mij,poz,val);

    }

    if(poz>mij){

        update(nod*2+1,mij+1,r,poz,val);

    }

    aint[nod]=aint[nod*2]+aint[nod*2+1];



}



int main()

{

 cin>>n;

 for (int i=1;i<=n;i++) {

  cin>>v[i];

  b.push_back(v[i]);

    }

 sort(b.begin(),b.end());

 b.erase(unique(b.begin(),b.end()),b.end());

 for (int i=1;i<=n;i++){

  v[i]=lower_bound(b.begin(),b.end(),v[i])-b.begin()+1;

 }

 for(int i=1;i<=n;i++){

            s=0;

        query(1,1,n,v[i]+1,n);

        ans+=s;

        ans%=9917;

        update(1,1,n,v[i],1);

 }

 cout<<ans;

    return 0;

}
