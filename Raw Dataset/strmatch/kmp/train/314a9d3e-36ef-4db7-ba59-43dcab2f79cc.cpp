#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



vector<int> sufix_and_prefix(string pattern) {

    vector<int> aux;

    aux.resize(pattern.size(), 0);



    int i = 0;

    int j = 1;



    while(j < pattern.size()){

        if(pattern[i] == pattern[j]) {

            aux[j] = i + 1;

            i++;

            j++;

        } else if(i != 0){

            i = aux[i - 1];

        } else {

            aux[j] = 0;

            j++;

        }

    }



    return aux;

}



vector<int> KMP(string s, string pattern, int& nr){

    vector<int> positions;

    vector<int> aux = sufix_and_prefix(pattern);

    int i = 0;

    int j = 0;

    while(i < s.size()) {

        if(s[i] == pattern[j]) {

            i++;

            j++;

        } else {

            if(j != 0) {

                j = aux [j - 1];

            } else {

                i++;

            }

        }

        if(j == pattern.size()) {

            nr++;

            j = aux[j-1];

            positions.push_back(i - pattern.size());

        }



    }



    return positions;

}

int main()

{

    string s;

    string pattern;

    f>>pattern>>s;

    int nr = 0;

    vector<int> result = KMP(s, pattern, nr);



    g<<nr<<'\n';

    if(result.size() > 1000)

        nr = 1000;

    else

        nr = result.size();

    for(int i = 0; i < nr; i++)

        g<<result[i]<<' ';



    f.close();

    g.close();

    return 0;

}
