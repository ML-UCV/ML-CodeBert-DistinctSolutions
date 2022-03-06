#include <bits/stdc++.h>

using namespace std;

vector<int> build_lps(const string &pattern, const string &text) {
    vector<int> lps(pattern.size());

    for (int i = 1, m = 0; i < pattern.size(); ++i) {
        if (pattern[i] == pattern[m])
            lps[i] = ++m;
        else if (m != 0)
            m = lps[m - 1], --i;
        else
            lps[i] = 0;
    }

    return lps;
}

vector<int> kmp(const string &pattern, const string &text) {
    const auto lps = build_lps(pattern, text);

    vector<int> matches;

    for (int i = 0, j = 0; j < text.size();) {
        if (pattern[i] != text[j]) {
            if (i == 0)
                ++j;
            else
                i = lps[i - 1];
        } else {
            ++i, ++j;

            if (i == pattern.size()) {
                matches.push_back(j - i);
                i = lps[i - 1];
            }
        }

    }

    return matches;
}

int main() {
    ifstream in("strmatch.in");
    ofstream out("strmatch.out");

    string pattern, text;
    in >> pattern >> text;

    auto matches = kmp(pattern, text);

    out << matches.size() << '\n';
    int k = min(1000ul, matches.size());
    for (int i = 0; i < k; ++i)
        out << matches[i] << ' ';
}
