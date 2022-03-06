#include <bits/stdc++.h>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

int i;

char s[100010];

int expresie(),termen(),factor();

int main() {

    fin>>s;

    i=0;

    fout<<expresie();

    return 0;

}

int expresie() {

    int r;

    r=termen();

    while (s[i]=='+'||s[i]=='-') {

        if (s[i]=='+') {

            i++;

            r+=termen();

        }

        else {

            i++;

            r-=termen();

        }

    }

    return r;

}

int termen() {

    int r;

    r=factor();

    while (s[i]=='*'||s[i]=='/') {

        if (s[i]=='*') {

            i++;

            r*=factor();

        }

        else {

            i++;

            r/=factor();

        }

    }

    return r;

}

int factor() {

    int r;

    if (s[i]=='(') {

        i++;

        r=expresie();

        i++;

    }

    else {

        r=0;

        while (s[i]>='0'&&s[i]<='9')

            r=r*10+s[i++]-'0';

    }

    return r;

}
