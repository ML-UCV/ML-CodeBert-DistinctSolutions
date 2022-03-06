#include <fstream>
#include <string>
#include <queue>




using namespace std;



ifstream cin ("swap.in");

ofstream cout("swap.out");



int arb[100100];



void add(int i){

  for(; i < 100000; i+=(i & (-i)))

      arb[i]++;

}



int get(int i){

 int ans = 0;

 for(; i; i -= (i & (-i)))

    ans +=arb[i];

    return ans;

}





string s, t;



queue <int> q[30];



int main(){



 getline(cin,s);

 getline(cin,t);



 for(int i = 0; i < s.length(); i++)

   q[s[i]-'a'].push(i+1);



 int rs = 0;



 for(int i = 0; i < t.length(); i++)

 {

  if(q[t[i]-'a'].empty()) return(cout << -1, 0);

  int pos = q[t[i]-'a'].front(); q[t[i]-'a'].pop();

  rs += pos - i - 1 + get(s.length()) - get(pos);

  add(pos);

 }



 cout << rs;

 return (0);

}
