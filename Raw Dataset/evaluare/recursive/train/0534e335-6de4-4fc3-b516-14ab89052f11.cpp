#include    <fstream>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");







char Sequence[100000], *P = Sequence;



long Termen();

long Factor();



long Solve() {

    long result = Termen();



    while (*P == '+' || *P == '-')

        switch (*P) {

        case '+':

            P++;

            result += Termen();

            break;



        case '-':

            P++;

            result -= Termen();

            break;

        }



    return result;

}



long Termen() {

    long result = Factor();



    while (*P == '*' || *P == '/')

        switch (*P) {

        case '*':

            P++;

            result *= Factor();

            break;



        case '/':

            P++;

            result /= Factor();

            break;

        }



    return result;

}



long Factor() {

    long result = 0;



    if (*P == '(') {

            P++;

            result = Solve();

            P++;

        }

    else

        while (*P >= '0' && *P <= '9') {

            result = result * 10 + *P - '0';

            P++;

        }



    return result;

}



int main() {

    fin >> Sequence;

    fout << Solve();

}
