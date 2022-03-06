#include <fstream>


using namespace std;

char a[100010];

int i;



int expresie();

int factor();

int termen();



int main() {

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin>>a;

    fout<<expresie();

    return 0;

}



int expresie() {

    int r=termen();

    while (a[i]=='+'||a[i]=='-') {

        if (a[i]=='+') {

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

    int r=factor();

    while (a[i]=='*'||a[i]=='/') {

        if (a[i]=='*') {

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



int factor () {

    int r;

    if (a[i]=='(') {

        i++;

        r=expresie();

        i++;

    }

    else {

        r=0;

        while (isdigit(a[i])) {

            r=r*10+(a[i]-'0');

            i++;

        }

    }

    return r;

}
