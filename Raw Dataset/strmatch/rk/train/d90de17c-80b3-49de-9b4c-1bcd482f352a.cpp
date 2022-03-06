#include <bits/stdc++.h>

using namespace std;

class RollingHash {
private:
    int a{}, mod{};
    int max_power{1}, value{0};

public:
    RollingHash() = default;

    RollingHash(int a, int mod) : a(a), mod(mod) {}

    void init(const string &s) {
        for (int i = 0; i < s.length(); i++) {
            value = (value * a + s[i]) % mod;

            if (i) max_power = (max_power * a) % mod;
        }
    }

    void roll(char out, char in) {
        value = ((value - (out * max_power) % mod + mod) * a + in) % mod;
    }

    bool operator==(const RollingHash &other) const {
        return value == other.value;
    }
};

tuple<bool, vector<int>> rabin_karp(const string &pattern, const string &text) {
    const int a = 31;
    const int n1 = 100003, n2 = 100109;

    array<RollingHash, 2> hp{RollingHash(a, n1), RollingHash(a, n2)};
    array<RollingHash, 2> ht{RollingHash(a, n1), RollingHash(a, n2)};

    if (pattern.length() > text.length()) {
        return {false, {}};
    }

    for (int i = 0; i < 2; i++) {
        hp[i].init(pattern);
        ht[i].init(text.substr(0, pattern.length()));
    }

    vector<int> matches;

    if (hp[0] == ht[0] && hp[1] == ht[1])
        matches.push_back(0);

    for (int i = pattern.length(); i < text.length(); i++) {
        for (int k = 0; k < 2; k++)
            ht[k].roll(text[i - pattern.length()], text[i]);

        if (hp[0] == ht[0] && hp[1] == ht[1])
            matches.push_back(i - pattern.length() + 1);
    }

    return {true, matches};
}

int main() {
    ifstream in("strmatch.in");
    ofstream out("strmatch.out");

    string pattern, text;

    in >> pattern >> text;

    vector<int> matches;
    bool okay;

    tie(okay, matches) = rabin_karp(pattern, text);

    if (!okay) {
        out << 0;
        return 0;
    }

    out << matches.size() << '\n';

    int k = std::min(1000ul, matches.size());
    for (int i = 0; i < k; ++i)
        out << matches[i] << ' ';
}
