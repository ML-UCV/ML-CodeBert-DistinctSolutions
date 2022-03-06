#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef unsigned long long ull; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef vector<pii> vii; typedef vector<pll> vll;

template<class T> std::istream& operator>>(std::istream& stream, vector<T> &v) { for (T& t: v) { stream >> t; } return stream; } template <class T> std::ostream& operator<<(std::ostream& stream, const vector<T> &v) { for (const T& t : v) { stream << t << ' '; } return stream; } template <class T, class U> std::istream& operator>>(std::istream& stream, pair<T, U>& p) { return stream >> p.first >> p.second; } template <class T, class U> std::ostream& operator<<(std::ostream& stream, const pair<T, U>& p) { return stream << p.first << ' ' << p.second << ' '; }

template<typename T> void read(T& t) { cin >> t; } template<typename T, typename... TArgs> void read(T& t, TArgs&&... args) { read(t); read(forward<TArgs>(args)...); } template <typename T> void readc(T& t); template<> void readc(int& v) { scanf("%d", &v); } template<> void readc(unsigned int& v) { scanf("%u", &v); } template<> void readc(char& v) { scanf(" %c", &v); } template<> void readc(long long& v) { scanf("%lld", &v); } template<> void readc(unsigned long long& v) { scanf("%llu", &v); } template<> void readc(float& v) { scanf("%f", &v); } template<> void readc(double& v) { scanf("%lf", &v); } template<size_t sz> void readc(char (&str)[sz]) { scanf("%s", str); } template<> void readc(char*& str) { scanf("%s", str); } template<typename E, typename U> void readc(pair<E, U>& v) { readc(v.first); readc(v.second); } template<typename E> void readc(vector<E>& v) { for (E& e : v) readc(e); } template<typename T, typename... TArgs> void readc(T& t, TArgs&&... args) { readc(t); readc(forward<TArgs>(args)...); }

template <typename T> void printc(T t); template<> void printc(int v) { printf("%d ", v); } template<> void printc(unsigned int v) { printf("%u ", v); } template<> void printc(char v) { printf("%c ", v); } template<> void printc(long long v) { printf("%lld ", v); } template<> void printc(unsigned long long v) { printf("%llu ", v); } template<> void printc(float v) { printf("%f ", v); } template<> void printc(double v) { printf("%lf ", v); } template<> void printc<char *>(char *str) { printf("%s ", str); } template<> void printc<const char *>(const char *str) { printf("%s ", str); } template<typename E, typename U> void printc(const pair<E, U>& v) { printc(v.first); printc(v.second); } template<typename E> void printc(const vector<E>& v) { for (const E& e : v) printc(e); } template<typename T, typename... TArgs> void printc(const T& t, TArgs&&... args) { printc(t); printc(forward<TArgs>(args)...); }

template <typename T> void __DEBUG_BASE(const T& t) { cout << t; } template <typename T, typename... TArgs> void __DEBUG_BASE(const T& t, TArgs&&... args) { __DEBUG_BASE(t); cout << ", "; __DEBUG_BASE(forward<TArgs>(args)...); } template <typename... TArgs> void __DEBUG_IMPL(TArgs&&... args) { __DEBUG_BASE(forward<TArgs>(args)...); }

char lower(char ch) { if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a'; return ch; } char upper(char ch) { if (ch >= 'a' && ch <= 'z') return ch - 'a' + 'A'; return ch; } array<char, 5> VOWELS = {'a','e','i','o','u'}; bool isvowel(char ch) { return find(VOWELS.begin(), VOWELS.end(), lower(ch)) != VOWELS.end(); }; bool isupper(char ch) { return ch >= 'A' && ch <= 'Z'; } bool islower(char ch) { return ch >= 'a' && ch <= 'z'; }







constexpr int mxN = 1e5 + 3;
char s[mxN], *ptr = s;

int eval();

int read_num() {
    int res = 0;
    while (isdigit(*ptr)) {
        res = res * 10 + (*ptr - '0');
        ++ptr;
    }
    return res;
}

int nxt() {
    int mult = 1;
    if (*ptr == '-') mult = -1, ++ptr;
    if (*ptr == '+') ++ptr;
    if (*ptr == '(') {
        ++ptr;
        return mult * eval();
    }
    return mult * read_num();
}

int eval() {
    int res = 0;
    int i;
    int nx;
    char sign;
    while (*ptr && *ptr != ')') {
        i = nxt();
        while (*ptr == '*' || *ptr == '/') {
            sign = *ptr;
            ++ptr;
            nx = nxt();
            if (sign == '*') {
                i *= nx;
            } else {
                i /= nx;
            }
        }
        res += i;
    }
    if (*ptr == ')') ++ptr;
    return res;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    freopen("evaluare" ".in", "r", stdin); freopen("evaluare" ".out", "w", stdout);
    scanf("%100000s", s);
    printf("%d\n", eval());
}
