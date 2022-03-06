#include <bits/stdc++.h>


using namespace std;
string s;



int eval2(int &i);

int eval1(int &i);

int eval(int &i) {

    int nr = eval1(i);

    while(s[i] == '+' or s[i] == '-')

        nr += s[i] == '+' ? eval1(++i) : -eval1(++i);

    return nr;

}

int eval1(int &i) {

    int nr = eval2(i);

    while(s[i] == '*' or s[i] == '/')

        nr = s[i] == '*' ? nr * eval2(++i) : nr / eval2(++i);

    return nr;

}

int eval2(int &i) {

    int nr = 0;

    if (s[i] == '(') {

        nr = eval(++i);

        i++;

    }

    else

        while(s[i] and strchr("0123456789", s[i]))

            nr = nr * 10 + s[i++] - '0';

    return nr;

}

int main() {



    freopen("evaluare.in", "r", stdin );

    freopen("evaluare.out", "w", stdout);



    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    cin >> s;

    int k = 0;

    cout << eval(k);



    return 0;



}
