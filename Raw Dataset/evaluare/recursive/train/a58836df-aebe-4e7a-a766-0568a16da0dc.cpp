#include <fstream>
using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");





char s[100010], *p=s;



int factor();

int numar();



int solve(){

    int r=factor();

    while(*p=='+'||*p=='-')

        switch(*p){

            case '+':

                p++;

                r+=factor();

                break;

            case '-':

                p++;

                r-=factor();

                break;

    }

    return r;

}



int factor(){

    int r=numar();

    while(*p=='*'||*p=='/')

        switch(*p){

            case '*':

                p++;

                r*=numar();

                break;

            case '/':

                p++;

                r/=numar();

                break;

        }

    return r;

}



int numar(){

    int r=0;

     if ( *p == '(' ) {

        ++p;

  r = solve();

  ++p;

     }else

        while(*p>='0'&&*p<='9'){

            r=r*10+(*p-'0');

            p++;

        }

    return r;

}



int main()

{

    cin.getline(s,100010);

    cout<<solve();

}
