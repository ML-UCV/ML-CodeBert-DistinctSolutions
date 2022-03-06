#include <fstream>
#include <vector>
using namespace std;
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

int main() {
    string s, t;
    fin >> s >> t;
    string aux = s + '#' + t;
    vector<int> pi(aux.size());
    int k = 0;
    for (int i = 1; i < aux.size(); ++i) {
        while (k && aux[i] != aux[k]) k = pi[k - 1];
        if (aux[i] == aux[k]) k++;
        pi[i] = k;
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = s.size() + 1; i < aux.size(); ++i)
        if (pi[i] == s.size() && ++cnt <= 1000) ans.push_back(i - 2 * s.size());
    fout << cnt << '\n';
    for (int pos : ans) fout << pos << ' ';
    return 0;
}
