#include <fstream>
#include <string>
#include <vector>




using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



void buildPi(vector <int> &pi, const string &pattern) {



 int jIdx = -1;

 pi[0] = -1;



 for (int idx = 1; idx < (int)pattern.size(); ++idx) {



  while (jIdx != -1 and pattern[jIdx + 1] != pattern[idx])

   jIdx = pi[jIdx];



  if (pattern[jIdx + 1] == pattern[idx])

   ++jIdx;

  pi[idx] = jIdx;

 }

}



int main() {



 string pattern, String;

 fin >> pattern >> String;



 vector <int> pi(pattern.size());

 buildPi(pi, pattern);



 vector <int> index;

 index.reserve(1000);



 int jIdx = -1;

 int matches = 0;



 for (int idx = 0; idx < (int)String.size(); ++idx) {



  while (jIdx != -1 and String[idx] != pattern[jIdx + 1])

   jIdx = pi[jIdx];



  if (String[idx] == pattern[jIdx + 1])

   ++jIdx;



  if (jIdx + 1 == (int)pattern.size()) {



   ++matches;

   jIdx = pi[jIdx];



   if (matches <= 1000)

    index.push_back(idx - pattern.size() + 1);

  }

 }



 fout << matches << '\n';

 for (const int &itm : index)

  fout << itm << ' ';

}
