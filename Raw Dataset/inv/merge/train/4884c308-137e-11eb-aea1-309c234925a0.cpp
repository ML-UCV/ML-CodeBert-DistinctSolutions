#include<fstream>
using namespace std;

ifstream cin("inv.in");

ofstream cout("inv.out");

int n,v[100005],aux[100005];

long long cnt;

void mergesort(int s,int d){

    if(s==d) return;

    int m=(s+d)/2;

    mergesort(s,m);

    mergesort(m+1,d);

    int i=s,j=m+1,k=0;

    while(i<=m && j<=d)

        if(v[i]<=v[j]) aux[++k]=v[i++];

        else {

            aux[++k]=v[j++];

            cnt+=m-i+1;

        }

    while(i<=m) aux[++k]=v[i++];

    while(j<=d) aux[++k]=v[j++];

    for(i=s,k=1;i<=d;i++,k++)

        v[i]=aux[k];

}

int main(){

    cin>>n;

    for(int i=1;i<=n;i++)

        cin>>v[i];

    mergesort(1,n);

    cout<<cnt%9917;

}
