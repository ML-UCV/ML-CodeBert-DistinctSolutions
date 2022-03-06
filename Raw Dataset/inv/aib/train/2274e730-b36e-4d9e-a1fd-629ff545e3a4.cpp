#include<fstream>
#include<algorithm>
#include<vector>



using namespace std;

ifstream cin("inv.in");
ofstream cout("inv.out");

int AIB[100000 +1];
vector<pair<int,int>> v;

void update(int x,int n){
 for(;x<=n;x+=x&(-x))
  AIB[x]++;
}

int query(int x){
 int ans=0;

 for(;x>0;x-=x&(-x))
  ans+=AIB[x];

 return ans;
}

int main(){
 int n;
 cin>>n;

 int ans=0;
 for(int i=1;i<=n;i++){
  int x;
  cin>>x;

  v.push_back({x,i});
 }

 sort(v.begin(),v.end());

 for(int i=0;i<n;i++){
  ans=(ans+i-query(v[i].second))%9917;
  update(v[i].second,n);
 }

 cout<<ans<<endl;
 return 0;
}
