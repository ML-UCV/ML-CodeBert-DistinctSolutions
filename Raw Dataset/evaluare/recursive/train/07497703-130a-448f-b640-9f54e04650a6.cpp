#include <bits/stdc++.h>


using namespace std;

char s[100005];

int i;

int expresie();

int factor() {

   int ret=0;

   if (s[i]=='(') {

        ++i;

        ret=expresie();

        ++i;

        return ret;

    }



    while (s[i]>='0' && s[i]<='9')

        ret=ret*10+s[i]-'0',++i;

    return ret;

}

int termen() {

   int ret=factor();

   while (s[i]=='*' || s[i]=='/') {

        if (s[i]=='*') ++i,ret*=factor();

        else ++i,ret/=factor();

   }

     return ret;

}

int expresie() {

    int ret=termen();

    while (s[i]=='+' || s[i]=='-') {

        if (s[i]=='+') ++i,ret+=termen();

        else ++i,ret-=termen();

    }



    return ret;

}

int main()

{

    ifstream f("evaluare.in");

    ofstream g("evaluare.out");

    f.get(s,100005);

    g<<expresie()<<'\n';



    return 0;

}
