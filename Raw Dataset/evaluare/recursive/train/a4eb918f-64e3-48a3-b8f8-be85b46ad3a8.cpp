#include<bits/stdc++.h>
using namespace std;



const int NMAX=100010;

char s[NMAX];

int ind;



int evaluare();

int termen();

int factor();



int expresie(){

    int ans=termen();

    while(s[ind]=='+' || s[ind]=='-'){

        int semn=1;

        if(s[ind++]=='-')

            semn=-1;

        ans=ans+semn*termen();

    }

    return ans;

}



int termen(){

    int ans=factor();

    while(s[ind]=='*' || s[ind]=='/'){

        if(s[ind]=='*'){

            ind++;

            ans*=factor();

        }

        else{

            ind++;

            ans/=factor();

        }

    }

    return ans;

}



int factor(){

    if(s[ind]=='\n' || s[ind]==EOF)

        return 0;

    if(s[ind]=='('){

        ind++;

        int ans=expresie();

        ind++;

        return ans;

    }

    int nr=0;

    while(isdigit(s[ind])){

        nr=nr*10+(s[ind]-'0');

        ind++;

    }

    return nr;

}



int main(){

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    cin>>s;

    printf("%d", expresie());

    return 0;

}
