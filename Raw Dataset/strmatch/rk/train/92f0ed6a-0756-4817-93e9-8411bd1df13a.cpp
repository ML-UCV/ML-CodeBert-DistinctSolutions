#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>





using namespace std;

class rollingHash{
private: long long key;
        long long maxpower;
        long long n;
public:
    long long val;
    bool operator== (const rollingHash &other) const {
        return (this->val == other.val && this->key == other.key && this->n == other.n);
    }
    void assignKeys(long long key, long long n){
        this->key = key;
        this->n = n;
    }
    void buildInitialHash(string x){
        this->val = 0;
        long long p = 1;
        for (int i = x.length() - 1; i >= 0; --i) {
            this->val = (this->val + ((p * x[i]) % this->n)) % this->n;
            this->maxpower = p;
            p = (p * this->key) % this->n;
        }
    }
    void rollHash(char out, char in){
        this->val = ((this->val - (out * this->maxpower) % this->n + this->n) * this->key + in) % this->n;
    }
};

int main() {
    ifstream f("strmatch.in");
    ofstream g("strmatch.out");
    string a, b;
    f>>a>>b;
    rollingHash h1a, h2a;
    h1a.assignKeys(31, 9153637);
    h2a.assignKeys(37, 9231329);
    h1a.buildInitialHash(a);
    h2a.buildInitialHash(a);
    vector<int> matches;
    rollingHash h1b, h2b;
    h1b.assignKeys(31, 9153637);
    h2b.assignKeys(37, 9231329);
    h1b.buildInitialHash(b.substr(0, a.length()));
    h2b.buildInitialHash(b.substr(0, a.length()));
    for (int i = a.length(); i < b.length(); ++i) {
        if(h1a == h1b && h2a == h2b) matches.push_back(i - a.length());
        h1b.rollHash(b[i - a.length()], b[i]);
        h2b.rollHash(b[i - a.length()], b[i]);
    }
    if(h1a == h1b && h2a == h2b) matches.push_back(b.length() - a.length());
    g<<matches.size()<<'\n';
    int l = matches.size();
    if(1000 < matches.size())
        l = 1000;
    for (int i = 0; i < l; ++i) {
        g<<matches[i]<<' ';
    }
    return 0;
}
