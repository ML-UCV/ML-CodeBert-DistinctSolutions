#include<bits/stdc++.h>
using namespace std;

string s,s1;

queue<int> q[30];

int z(int i)

{

 return i&(-i);

}

int arb[100100],rez;

void add(int i)

{

 for(; i <= 100000; i += z(i))

  arb[i]++;

}

int get(int i)

{

 int ans = 0;

 for (;i; i-= z(i))

  ans+= arb[i];

 return ans;

}

int main()

{

 ifstream cin("swap.in");

 ofstream cout("swap.out");

 cin >> s >> s1;

 for (int i = 0 ; i < s.length(); i++)

 {

  q[int(s[i] - 'a')].push(i+1);

 }

 for (int i = 0 ; i < s1.length();i++)

 {

  if (q[s1[i] - 'a'].size() == 0) return cout<<-1,0;

  int poz = q[s1[i] - 'a'].front();

  q[s1[i] - 'a'].pop();

  rez += poz-i-1 + get(s.length()) - get(poz);

  add(poz);

 }

 cout << rez;

}
