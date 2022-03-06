#include <bits/stdc++.h>




using namespace std;



int ARB[105000], rs;

string s, S;

void add(int i)

{

 for (; i < 100000; i += (i & (-i))) ARB[i]++;

}

int get (int i)

{

 int rs = 0;

 for (;i;i-=(i & (-i))) rs+=ARB[i];

 return rs;

}

queue < int > Q[40];

int main(){

    ifstream cin("swap.in");

    ofstream cout("swap.out");

    cin >> s >> S;

    for (int i = 0; i < s.size(); i++) Q[s[i]-'a'].push(i+1);

    for (int i = 0; i < S.size(); i++)

    {

     if(Q[S[i]-'a'].empty()) return cout << -1, 0;

     int curr = Q[S[i]-'a'].front();

     Q[S[i]-'a'].pop();

     rs += curr - i - 1 + get(s.size()) - get(curr);

     add(curr);

    }

    cout << rs;

    cerr << "Fucking time elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';

    return 0;

}
