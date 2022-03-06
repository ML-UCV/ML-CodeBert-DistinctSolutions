#include <bits/stdc++.h> //Andrei Alexandru a.k.a Sho10



using namespace std;

int n,p[5000005];

string second,t;

vector<int>ans;

void solve(){

t=(second+'#'+t);

int j=0;

for(int i=1;i<t.size();i++)

{

    if(t[i]==t[j]){

        p[i+1]=j+1;

        j++;

        continue;

    }

    while(j!=0){

        j=p[j];

        if(t[i]==t[j]){

            p[i+1]=j+1;

            j++;

            break;

        }

    }

}

for(int i=0;i<t.size();i++)

{

    if(p[i+1]==second.size()){

        ans.push_back(i);

    }

}

}

int32_t main(){

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

cin>>second>>t;

solve();

cout<<ans.size()<<'\n';

int n=ans.size();

for(int i=0;i<min(1000,n);i++)

{

    cout<<ans[i]-2*second.size()<<' ';

}

}
