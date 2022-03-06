#include<bits/stdc++.h>
using namespace std;
ifstream fin("strmatch.in"); ofstream fout("strmatch.out");







long long n ,m;

string a, b;

long long h1=0, h2=0, hb=0;

long long ord[300];

vector<long long> pos;





int32_t main(){

ios_base :: sync_with_stdio(false); fin.tie(NULL); fout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

getline(fin, b);

getline(fin, a);

n=a.length(); m=b.length();

if(n<m){fout<<0; return 0;}

long long o0=1;



for(char c='a'; c<='z'; c++){

    ord[c]=o0;

    o0++;

}

for(char c='A'; c<='Z'; c++){

    ord[c]=o0;

    o0++;

}

for(char c='0'; c<='9'; c++){

    ord[c]=o0;

    o0++;

}



long long pw=1, bs=62;

for(long long i=0; i<m; i++){

    hb+=(pw*(ord[b[i] ]-ord['a']+1))%(1000000007); hb%=(1000000007);

    pw*=bs; pw%=(1000000007);

}



long long pw1=1, pw2=1;

long long cnt=0;

for(long long i=0; i<m; i++){

    h2+=(pw2*(ord[a[i] ]-ord['a']+1))%(1000000007); h2%=(1000000007);

    pw2*=bs; pw2%=(1000000007);

}

if(h2==hb){

    pos.push_back(0);

    cnt++;

}



for(long long i=m; i<n; i++){

    h2-=(pw1*(ord[a[i-m] ]-ord['a']+1))%(1000000007); h2+=(1000000007); h2+=(pw2*(ord[a[i] ]-ord['a']+1))%(1000000007); h2%=(1000000007);

    pw2*=bs; pw1*=bs; pw1%=(1000000007); pw2%=(1000000007);

    hb*=bs; hb%=(1000000007);

    if(hb==( h2)){ if(pos.size()<1000){pos.push_back(i-m+1);} cnt++; }

    Next:continue;

}

fout<<cnt<<"\n";

for(long long i=0; i<min((long long)pos.size(), (long long)1000); i++){

    fout<<pos[i]<<" ";

}



return 0;

}
