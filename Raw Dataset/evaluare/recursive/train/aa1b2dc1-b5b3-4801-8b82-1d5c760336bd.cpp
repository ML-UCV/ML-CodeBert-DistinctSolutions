#include<bits/stdc++.h>


using namespace std;



string s;

int p;



int termen();

int fact();



int eval() {

    int nr=termen();

    while (p<s.size() && (s[p]=='+' || s[p]=='-')) {

        ++p;

        if (s[p-1]=='+') nr+=termen();

        else nr-=termen();

    }

    return nr;

}



int termen() {

    int r=fact();

    while (p<s.size() && (s[p]=='*' || s[p]=='/')) {

        ++p;

        if (s[p-1]=='*') r*=fact();

        else r/=fact();

    }

    return r;

}



int fact() {

    int nr=0;

    if (s[p]=='(') ++p, nr=eval(), ++p;

    else {

        while (p<s.size() && s[p]>='0' && s[p]<='9') {

            nr=nr*10+s[p]-'0';

            ++p;

        }

    }

    return nr;

}



int main() {

    ifstream cin("evaluare.in");

    ofstream cout("evaluare.out");

    cin>>s;

    cout<<eval();





    return 0;

}
