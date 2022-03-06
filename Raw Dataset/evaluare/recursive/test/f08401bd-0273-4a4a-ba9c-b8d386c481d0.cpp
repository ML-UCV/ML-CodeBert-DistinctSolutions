#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const string file = "evaluare";
const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, inf = 2147483647;

int p;
string s;

int factor();
int termen();

int eval()
{
    int x = factor();
    while(s[p] == '+' || s[p] == '-'){
        if(s[p] == '+'){
            ++p;
            x += factor();
        }else{
            ++p;
            x -= factor();
        }
    }
    return x;
}

int factor()
{
    int x = termen();
    while(s[p] == '*' || s[p] == '/'){
        if(s[p] == '*'){
            ++p;
            x *= termen();
        }else{
            ++p;
            x /= termen();
        }
    }
    return x;
}

int termen()
{
    if(s[p] == '('){
        ++p;
        int x = eval();
        ++p;
        return x;
    }
    int x = 0;
    while(s[p] >= '0' && s[p] <= '9'){
        x = x*10+s[p]-'0';
        ++p;
    }
    return x;
}

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> s;
    s += "#";
    fout << eval() << "\n";
    return 0;
}
