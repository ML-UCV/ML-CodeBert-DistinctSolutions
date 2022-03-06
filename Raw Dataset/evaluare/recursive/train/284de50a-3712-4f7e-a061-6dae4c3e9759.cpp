#include <fstream>
#include <string>
using namespace std;

ifstream f ("evaluare.in");
ofstream g ("evaluare.out");

char termeni[100003];
char *p=termeni;
long oi();
long paranteze();
long pm () {
    long r = oi();
    while (*p=='+' || *p=='-') {
        if (*p=='+') {
            ++p;
            r+=oi();
        } else if (*p=='-') {
            ++p;
            r-=oi();
        }
    }
    return r;
}

long oi() {
    long r = paranteze();
    while (*p=='*' || *p=='/') {
        if (*p=='*') {
            ++p;
            r*=paranteze();
        } else if (*p=='/') {
            ++p;
            r/=paranteze();
        }
    }
    return r;
}

long paranteze() {
    long r = 0;
    if (*p=='(') {
        ++p;
        r=pm();
        ++p;
    } else {
        while ( *p>='0' && *p<='9' ) {
            r = r*10 + *p - '0';
            ++p;
        }
    }
    return r;
}

int main(int argc, const char * argv[]) {
    f>>termeni;
    g<<pm();
    return 0;
}
