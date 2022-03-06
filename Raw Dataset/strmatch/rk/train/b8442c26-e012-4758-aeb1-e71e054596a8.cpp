#include <fstream>
#include <iostream>
#include <string>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



typedef long long ll;



const ll p = 256, MOD1 = 100007, MOD2 = 100021;



ll p1 = 1, p2 = 1, hasha1, hasha2, hash1, hash2;

string txt, pat;

vector<ll> v;



int main()

{

    fin>>pat>>txt;

    for(int i = 0; i < pat.length(); ++i) {

        hasha1 = (hasha1 * p + pat[i]) % MOD1,

        hasha2 = (hasha2 * p + pat[i]) % MOD2;



        if(i) p1 = (p1 * p) % MOD1, p2 = (p2 * p) % MOD2;

    }



    for(int i = 0; i < pat.length(); ++i)

        hash1 = (hash1 * p + txt[i]) % MOD1,

        hash2 = (hash2 * p + txt[i]) % MOD2;



    if(hash1 == hasha1 && hash2 == hasha2) v.push_back(0);



    for(int i = pat.length(); i < txt.length(); ++i) {

        hash1 = ((hash1 - (txt[i - pat.length()] * p1) % MOD1 + MOD1) * p + txt[i]) % MOD1,

        hash2 = ((hash2 - (txt[i - pat.length()] * p2) % MOD2 + MOD2) * p + txt[i]) % MOD2;



        if(hash1 == hasha1 && hash2 == hasha2) v.push_back(i - pat.length() + 1);

    }



    fout<<v.size()<<"\n";

    for(int i = 0; i < 1000 && i < v.size(); ++i)

        fout<<v[i]<<" ";

    return 0;

}
