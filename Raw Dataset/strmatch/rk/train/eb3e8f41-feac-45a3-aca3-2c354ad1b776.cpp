#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



typedef string::iterator sit;



class Roller{

public:

 int a, n;

 int ap = 1;

 int q = 0;

 Roller();

 Roller(int a, int n, sit lt, sit rt) : a(a), n(n){

  for(auto it = lt; it != rt; ++it){

   q *= a;

   q += *it;

   q %= n;



   if(it!=lt)ap *= a;

   ap %= n;

  }

 }

 void roll(char out, char in){

  q -= out*ap;

  q += n*128;

  q %= n;

  q *= a;

  q += in;

  q %= n;

 }

};



const int a = 31;

const int n1 = 1000003, n2 = 1000033;



string pattern, text;



int ans1 = 0;

vector<int> ans2;



int main(){



 fin >> pattern >> text;

 Roller rpattern[] = {Roller(a,n1,pattern.begin(),pattern.end()),Roller(a,n2,pattern.begin(),pattern.end())};

 Roller rtext[] = {Roller(a,n1,text.begin(),text.begin()+pattern.size()),Roller(a,n2,text.begin(),text.begin()+pattern.size())};



 if(rpattern[0].q == rtext[0].q && rpattern[1].q == rtext[1].q){

  ans1++;

  if(ans1 <= 1000)ans2.push_back(0);

 }



 for(int i = pattern.size(); i < text.size(); ++i){

  rtext[0].roll(text[i-pattern.size()], text[i]);

  rtext[1].roll(text[i-pattern.size()], text[i]);

  if(rpattern[0].q == rtext[0].q && rpattern[1].q == rtext[1].q){

   ans1++;

   if(ans1 <= 1000)ans2.push_back(i-pattern.size()+1);

  }

 }



 fout << ans1 << "\n";

 for(auto a : ans2)fout << a << " ";

 return 0;

}
