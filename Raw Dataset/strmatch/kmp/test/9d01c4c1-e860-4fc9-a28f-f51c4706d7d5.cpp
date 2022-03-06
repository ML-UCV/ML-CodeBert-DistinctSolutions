#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
constexpr auto NMAX = 1000;





std::ifstream fin ("strmatch.in");

std::ofstream fout ("strmatch.out");



int n, m, cnt;

std::string text, pattern;

std::vector <int> lps;

std::set <int> Store;





inline void Compute_LPS () {

 int len = 0, i = 1;



 while (i < m) {

  if (pattern[i] == pattern[len])

   ++ len, lps[i] = len, ++ i;

  else {

   if (len) len = lps[len - 1];

   else lps[i] = 0, ++ i;

  }

 }

}



inline void KMP_Search () {

 int i = 0, j = 0;

 n = (int)text.size (), m = (int)pattern.size ();

 lps.assign (m, 0);

 if (n < m) goto end;



 Compute_LPS ();

 while (i < n) {

  if (text[i] == pattern[j])

   ++ i, ++ j;

  if (j == m) {

   ++ cnt;

   if (n > NMAX) {

    if (cnt - 1 < NMAX)

     Store.insert (i - j);

   }

   else Store.insert (i - j);

   j = lps[j - 1];

  }

  else if (i < n && text[i] != pattern[j]) {

   if (j) j = lps[j - 1];

   else ++ i;

  }

 }

 end : ;

}





int main () {

 fin >> pattern >> text;

 KMP_Search ();

 fout << cnt << "\n";

 std::copy (Store.begin (), Store.end (), std::ostream_iterator <int> (fout, " "));



 fin.close (), fout.close ();

 return 0;

}
