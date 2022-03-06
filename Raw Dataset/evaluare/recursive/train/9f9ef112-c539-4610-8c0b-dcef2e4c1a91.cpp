#include <bits/stdc++.h>
using namespace std;

ifstream in("evaluare.in");

ofstream out("evaluare.out");

int sum_diff();

int prod_imp();

int term();

string s;

int ind;

int sum_diff()

{

    int k=prod_imp();

    while(ind<s.size() and (s[ind]=='+' or s[ind]=='-'))

    {

        if(s[ind]=='+')

            ++ind,k+=prod_imp();

        else ++ind,k-=prod_imp();

    }

    return k;

}

int prod_imp()

{

    int k=term();

    while(ind<s.size() and (s[ind]=='*' or s[ind]=='/'))

    {

        if(s[ind]=='*')

            ++ind,k*=term();

        else ++ind,k/=term();

    }

    return k;

}

int term()

{

    if(s[ind]=='(')

    {

        ++ind;

        int k=sum_diff();

        ++ind;

        return k;

    }

    int k=0;

    while(ind<s.size() and '0'<=s[ind] and s[ind]<='9')

        k=k*10+s[ind]-'0',++ind;

    return k;

}

int main()

{

    in>>s;

    out<<sum_diff()<<'\n';

    return 0;

}
