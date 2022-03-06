#include <fstream>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");





char Expresie[100005], *p = Expresie;



long termen();

long factor();

long eval();



int main(){





    fin.getline(Expresie, 100005);





    fout << eval();



    fin.close();

    fout.close();

    return 0;

}
long eval(){

    long rezultat = termen();

    while( *p == '+' || *p == '-' ){

        switch ( *p ){

            case '+' :

                    ++p;

                    rezultat += termen();

                    break;

            case '-' :

                    ++p;

                    rezultat -= termen();

                    break;

        }

    }

    return rezultat;

}
long termen(){

    long rezultat = factor();

    while( *p == '*' || *p == '/' ){

        switch ( *p ){

            case '*' :

                    ++p;

                    rezultat *= factor();

                    break;

            case '/' :

                    ++p;

                    rezultat /= factor();

                    break;

        }

    }

    return rezultat;

}
long factor(){

    long rezultat = 0;

    if ( *p == '(' ){

            ++p;

            rezultat = eval();

            ++p;

    }else{

        while( *p >= '0' && *p <= '9'){

            rezultat = rezultat * 10 + *p - '0';

            ++p;

        }

    }

    return rezultat;

}
