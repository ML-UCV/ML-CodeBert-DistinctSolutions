#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



const int NMax = 1e5;



char S[NMax + 5], *p = S;



int Eval();



int Factor()

{

    int Sol = 0;



    if(*p == '(')

        ++p, Sol = Eval(), p++;

    else

    {

        while(isdigit(*p))

            Sol = Sol * 10 + *p - '0', p++;

    }

    return Sol;

}



int Termen()

{

    int Sol = Factor();



    while(*p == '*' || *p == '/')

    {

        if(*p == '*')

            p++, Sol *= Factor();

        else

            p++, Sol /= Factor();

    }

    return Sol;

}



int Eval()

{

    int Sol = Termen();



    while(*p == '+' || *p == '-')

    {

        if(*p == '+')

            p++, Sol += Termen();

        else

            p++, Sol -= Termen();

    }

    return Sol;

}



int main()

{

    fin >> S;



    fout << Eval() << '\n';



    fin.close();

    fout.close();



    return 0;

}
