#include <bits/stdc++.h>
using namespace std;





ifstream fin("strmatch.in");

ofstream fout("strmatch.out");





int main()

{

    string pattern;

    string text;



    fin >> pattern >> text;



    vector<int> PI(pattern.size() + 1);



    for(int i = 1, k = 0; i < (int)pattern.size(); ++i)

    {

        while(pattern[i] != pattern[k] && k > 0) k = PI[k - 1];



        if(pattern[i] == pattern[k]) ++k;



        PI[i] = k;

    }



    vector<int> answer;



    for(int i = 0, k = 0; i < (int)text.size(); ++i)

    {

        while(text[i] != pattern[k] && k > 0) k = PI[k - 1];



        if(text[i] == pattern[k]) ++k;



        if(k == (int)pattern.size())

        {

            answer.push_back(i - pattern.size() + 1);

        }

    }



    fout << answer.size() << '\n';



    for(int i = 0; i < min(1000, (int)answer.size()); ++i)

        fout << answer[i] << ' ';

}
