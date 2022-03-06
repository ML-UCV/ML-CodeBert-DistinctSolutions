#include<bits/stdc++.h>
using namespace std;


string s;
int act;

int Expresie();

int Factor()
{
    return Expresie();
}

int Termen()
{
    int ans = Factor();
    while (s[act] == '*' || s[act] == '/') {
        char operatie = s[act];
        act++;
        int val = Factor();
        if (operatie == '*')
            ans *= val;
        else if (operatie == '/')
            ans /= val;
        else
            assert(false);
    }
    return ans;
}

int Expresie()
{
    if (s[act] >= '0' && s[act] <= '9') {
        int n = 0;
        while (s[act] >= '0' && s[act] <= '9') {
            n = 10 * n + s[act] - '0';
            act++;
        }
        return n;
    }
    assert(s[act] == '(');
    act++;

    int ans = Termen();
    while (s[act] != ')') {
        char operatie = s[act];
        act++;
        int val = Termen();
        if (operatie == '+')
            ans += val;
        else if (operatie == '-')
            ans -= val;
        else
            assert(false);
    }
    assert(s[act] == ')');
    act++;
    return ans;
}

int main()
{
    ifstream cin("evaluare.in");
    ofstream cout("evaluare.out");
    cin >> s;
    s = "(" + s + ")";
    int ans = Expresie();
    cout << ans << '\n';
    return 0;
}
