#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "evaluare";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647;

int p;
string s;

int factor(), termen();

int eval()
{
    int r = factor();
    while(s[p] == '+' || s[p] == '-')
        if(s[p] == '+'){
            ++p;
            r += factor();
        }else{
            ++p;
            r -= factor();
        }
    return r;
}

int factor()
{
    int r = termen();
    while(s[p] == '*' || s[p] == '/')
        if(s[p] == '*'){
            ++p;
            r *= termen();
        }else{
            ++p;
            r /= termen();
        }
    return r;
}

int termen()
{
    int r = 0;
    if(s[p] == '('){
        ++p;
        r = eval();
        ++p;
    }else
        while(s[p] >= '0' && s[p] <= '9'){
            r = r*10 + s[p]-'0';
            ++p;
        }
    return r;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> s; s += "#";
    fout << eval();
    return 0;
}
