#include <bits/stdc++.h>


using namespace std;



int main()

{

    ifstream fin("strmatch.in");

    ofstream fout("strmatch.out");



    string pattern , text;

    fin >> pattern >> text;



    vector<int> PI(pattern.size());



    for(int k = 0, i = 1; i < (int)pattern.size(); ++i)

    {

        while(k > 0 && pattern[i] != pattern[k]) k = PI[k - 1];

        if(pattern[i] == pattern[k]) ++k;

        PI[i] = k;

    }



    vector<int> answer;



    for(int k = 0, i = 0; i < (int)text.size(); ++i)

    {

        while(k > 0 && text[i] != pattern[k]) k = PI[k - 1];

        if(text[i] == pattern[k]) ++k;



        if(k == (int)pattern.size())

        {

            answer.push_back(i - k + 1);

        }

    }



    fout << answer.size() << '\n';



    for(int i = 0; i < min(1000, (int)answer.size()); ++i) fout << answer[i] << ' ';

}
