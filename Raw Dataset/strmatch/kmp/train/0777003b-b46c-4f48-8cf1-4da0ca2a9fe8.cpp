#include <fstream>
#include <cstring>
#include <vector>
#include <iostream>



std::ifstream f("strmatch.in");

std::ofstream g("strmatch.out");



void get_lps(const std::string& string, std::vector<int>& lps)

{

 unsigned int i = 0, j = 1;

 lps.resize(string.size());

 lps[0] = 0;

 while (j < string.size())

 {

  if (string[i] == string[j])

  {

   lps[j] = i + 1;

   i++;

   j++;

  }

  else

  {

   if (i == 0)

    lps[j++] = 0;

   else

    i = lps[i - 1];

  }

 }

}



int kmp(const std::string& string , const std::string& pattern, std::vector<int>& results)

{

 int matches = 0;

 unsigned int i = 0, j = 0;

 std::vector<int> lps;

 get_lps(pattern, lps);

 while (i < string.size())

 {

  if (string[i] == pattern[j])

  {

   i++;

   j++;

  }



  if (j == pattern.size())

  {

   if(matches < 1000)

    results.push_back(i - j);

   matches++;

   j = j != 0 ? lps[j - 1] : 0;

  }

  else

  if (i < string.size() && string[i] != pattern[j])

  {

   if (j == 0)

    i++;

   else

    j = lps[j - 1];

  }

 }

 return matches;

}





int main()

{

 std::string string, pattern;

 f >> pattern;

 f >> string;

 std::vector<int> matches;

 g << kmp(string, pattern, matches) << '\n';

 for (int i : matches)

  g << i << ' ';



}
