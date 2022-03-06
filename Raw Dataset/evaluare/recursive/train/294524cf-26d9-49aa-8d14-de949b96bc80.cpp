#include <fstream>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

int i;

char s[100003];

int expresie();

int factor();

int termen();

int main(){

    fin.getline(s,100001);

    fout<<expresie();

    return 0;

}

int expresie(){

    int r=termen();

    while(s[i]=='+' || s[i]=='-'){

        if(s[i]=='+')

            i++,r+=termen();

        else i++,r-=termen();

    }

    return r;

}

int termen(){

    int r=factor();

    while(s[i]=='*' || s[i]=='/'){

        if(s[i]=='*')

            i++,r*=factor();

        else i++,r/=factor();

    }

    return r;

}

int factor(){

    int r=0;

    if(s[i]=='('){

        i++;

        r=expresie();

        i++;

    }

    else while(s[i]>='0' && s[i]<='9')

        r=r*10+s[i++]-'0';

    return r;

}
