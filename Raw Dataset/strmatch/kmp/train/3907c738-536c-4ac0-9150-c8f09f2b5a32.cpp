#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");
string word, sir;
int N, M;
int lps[2000020];
void createLPS() {
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < M) {
        if (word[i] == word[len]) {
            ++len;
            lps[i] = len;
            ++i;
        }
        else {
            if (len == 0) {
                lps[i] = 0;
                ++i;
            }
            else {
                len = lps[len - 1];
            }
        }
    }
}
int main()
{
    vector<int> v;
    fin >> word >> sir;
    N = sir.length();
    M = word.length();
    createLPS();
    int i = 0, j = 0;
    while (i < N) {
        while (i < N && j < M && word[j] == sir[i]) {
            ++j;
            ++i;
            if (j == M) {
                v.push_back(i - j);
            }
        }
        if (i < N && j <= M) {
            if (j) {
                j = lps[j - 1];
            }
            else
                ++i;
        }
    }
    fout << v.size() << "\n";
    for (int i = 0; i < min((int)v.size(), 1000); ++i) {
        fout << v[i] << " ";
    }
    return 0;
}
