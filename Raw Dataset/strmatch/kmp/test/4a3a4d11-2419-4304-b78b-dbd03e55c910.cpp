#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int N = 2000041;



int lps[N];

char s1[N], s2[N];



int ans1 = 0;

vector<int> ans2;



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



 fin >> s1 >> s2;



 make_lps();

 solve();



 fout << ans1 << "\n";

 for(auto a : ans2)fout << a << " ";

 return 0;

}
