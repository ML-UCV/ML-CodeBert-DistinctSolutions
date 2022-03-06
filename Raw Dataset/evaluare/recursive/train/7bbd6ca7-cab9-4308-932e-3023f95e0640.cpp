#include <fstream>


using namespace std;

ifstream cin("evaluare.in");

ofstream cout("evaluare.out");

char s[1000005],*p;

int eval();

int termen();

int factor();

int eval() {

    int r = termen();

    while(*p=='+'||*p=='-') {

        if(*p=='+') {

            p++;

            r+=termen();

        }

        else {

            p++;

            r-=termen();

        }

    }

    return r;

}

int termen() {

    int r=factor();

    while(*p=='*'||*p=='/') {

        if(*p=='*') {

            p++;

            r*=factor();

        }

        else {

            p++;

            r/=factor();

        }

    }

    return r;

}

int factor() {

    int r=0;

    if(*p=='(') {

        p++;

        r=eval();

        p++;

       }

    else

    while(*p>='0'&&*p<='9') {

        r=r*10+*p-'0';

        p++;

    }

    return r;

}

int main()

{

    cin.getline(s,100005);

    p=s;

    cout<<eval();

    return 0;

}
