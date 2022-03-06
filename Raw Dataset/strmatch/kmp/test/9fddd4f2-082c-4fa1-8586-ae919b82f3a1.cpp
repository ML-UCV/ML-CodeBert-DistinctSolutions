#include <bits/stdc++.h>
using namespace std;



const int mod=1e9+7;

const int modu=1999999973;

const int modul=998244353;



int ans,pref[6000005];

vector<int>indx;

string s,t;



void kmp(){

    t=(s+"#"+t);

    int j=0;

    for(int i=1;i<t.size();i++){

        if(t[i]==t[j]){

            pref[i+1]=j+1;

            ++j;

            continue;

        }

        else{

            while(j!=0){

                j=pref[j];

                if(t[i]==t[j]){

                    pref[i+1]=j+1;

                    ++j;

                    break;

                }

            }

        }

    }

    for(int i=0;i<t.size();i++){

        if(pref[i+1]>=s.size()) indx.push_back(i);

    }

}



int32_t main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);

    srand(chrono::steady_clock::now().time_since_epoch().count());

    ifstream cin("strmatch.in");

    ofstream cout("strmatch.out");

    cin >> s >> t;

    kmp();

    cout << indx.size() << '\n';

    int g=indx.size();

    for(int i=0;i<min(1000,g);i++) cout << indx[i]-2*s.size() << ' ';

}
