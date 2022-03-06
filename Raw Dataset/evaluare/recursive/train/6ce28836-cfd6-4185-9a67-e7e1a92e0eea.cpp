#include <fstream>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



const int NMAX = 1e5 + 5;



char S[NMAX], *p;



static inline int Eval ();

static inline int Termen ();

static inline int Factor ();



static inline int Eval ()

{

    int r = Termen();



    while(*p == '+' || *p == '-')

    {

        if(*p == '+')

        {

            ++p;



            r += Termen();

        }

        else

        {

            ++p;



            r -= Termen();

        }

    }



    return r;

}



static inline int Termen ()

{

    int r = Factor();



    while(*p == '*' || *p == '/')

    {

        if(*p == '*')

        {

            ++p;



            r *= Factor();

        }

        else

        {

            ++p;



            r /= Factor();

        }

    }



    return r;

}



static inline int Factor ()

{

    if(*p == '(')

    {

        ++p;



        int r = Eval();



        ++p;



        return r;

    }



    int r = 0, sign = 1;



    if(*p == '-')

    {

        sign = -1;



        ++p;

    }



    while(isdigit(*p))

    {

        r = r * 10 + (*p - '0');



        ++p;

    }



    return (r * sign);

}



int main()

{

    f.tie(NULL);



    f >> (S + 1);



    p = (S + 1);



    g << Eval() << '\n';



    return 0;

}
