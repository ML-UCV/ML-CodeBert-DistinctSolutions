#include <bits/stdc++.h>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");





int lps[2000005];

char s1[2000005], s2[2000005];



int ans1 = 0;

vector < int > ans2;



void make_lps(){

 int j = 0;

 for(int i = 1; s1[i] != '\0'; ++i){

  if(s1[i] == s1[j]){

   lps[i] = ++j;

  }else if(j != 0){

   j = lps[j-1];

   i--;

  }

 }

}



void solve(){

 int j = 0;

 for(int i = 0; s2[i] != '\0'; ++i){

  if(s1[j] == s2[i]){

   j++;

   if(s1[j] == '\0'){

    ans1++;

    if(ans1 <= 1000)ans2.push_back(i-j+1);

    j = lps[j-1];

   }

  }else if(j != 0){

   j = lps[j-1];

   i--;

  }

 }

}



int main(){



 f >> s1 >> s2;

 make_lps();

 solve();



 g << ans1 << '\n';

 for(int a=0;a<ans2.size();a++) {

        g << ans2[a] << " ";

 }

 return 0;

}
