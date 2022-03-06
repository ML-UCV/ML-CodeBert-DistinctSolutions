#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void buildLPS(vector<int> &lps, string a){
    lps.reserve(a.length());
    for (int i = 0; i < a.length(); ++i) {
        lps.push_back(0);
    }
    for (int i = 1, j = 0; i < a.length(); ++i) {
        if(a[i] == a[j]) lps[i] = ++j;
        else if(j) j = lps[j - 1], --i;
        else lps[i] = 0;
    }
}

void kmp(vector<int> &matches, vector<int> lps, string a, string b){
    for (int i = 0, j = 0; j < b.length();) {
        if(a[i] != b[j]){
            if(i == 0) ++j;
            else i = lps[i - 1];
        }else{
            ++i, ++j;
            if(i == a.size()){
                matches.push_back(j - i);

                i = lps[i - 1];
            }
        }
    }
}

int main() {
    ifstream f("strmatch.in");
    ofstream g("strmatch.out");
    string a, b;
    f>>a>>b;
    vector<int> matches;
    vector<int> lps;
    buildLPS(lps, a);
    kmp(matches, lps, a, b);
    int l = matches.size();
    if(1000 < matches.size())
        l = 1000;
    g<<matches.size()<<'\n';
    for (int i = 0; i < l; ++i) {
        g<<matches[i]<<' ';
    }
    return 0;
}
