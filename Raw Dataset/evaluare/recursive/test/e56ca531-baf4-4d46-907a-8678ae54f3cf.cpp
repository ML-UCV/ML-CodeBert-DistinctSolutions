#include <bits/stdc++.h>


using namespace std;



int termen();

int factor();

int expresie();



const int N=(int)1e5+7;

char s[N];

int j;



int expresie()

{

        int r=termen();

        while(s[j]=='+' || s[j]=='-')

        {

                j++;

                if(s[j-1]=='-') r-=termen(); else r+=termen();

        }

        return r;

}



int termen()

{

        int r=factor();

        while(s[j]=='/' || s[j]=='*')

        {

                j++;

                if(s[j-1]=='*') r*=factor(); else r/=factor();

        }

        return r;

}



int factor()

{

        int sng=1;

        while(s[j]=='-') sng=-sng, j++;

        if(s[j]=='(')

        {

                j++;

                int r=expresie();

                j++;

                return r*sng;

        }

        int r=0;

        while('0'<=s[j] && s[j]<='9') r=10*r+(s[j]-'0'), j++;

        return r*sng;

}



int main()

{

        freopen("evaluare.in","r",stdin); freopen("evaluare.out","w",stdout);

        cin.getline(s,N); cout<<expresie()<<"\n";

}
