#include <fstream>
#include <algorithm>

using namespace std;
ifstream cin("inv.in");
ofstream cout("inv.out");
bool ms(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int aib[100005],n;
void upd(int a){
    for(;a<=n;a+=(a&(-a))){
        aib[a]++;
    }
}
int que(int a){
    int sol=0;
    for(;a>=1;a-=(a&(-a))){
        sol+=aib[a];
    }
    return sol;
}
pair<int,int> v[100005];
int main()
{
    int a,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)
        v[i].first=i;
    sort(v+1,v+n+1,ms);
    for(int i=1;i<=n;i++){
        a=v[i].first;
        sum+=i-que(a)-1;
        sum%=9917;
        upd(a);

    }
    cout<<sum;
    return 0;
}
