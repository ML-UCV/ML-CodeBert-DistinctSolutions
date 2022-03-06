#include <bits/stdc++.h>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



const int NMAX = 1e5 + 5;



int N, K;



char S[NMAX], *p;



static inline void Read ()

{

    f.tie(NULL);



    f >> (S + 1);



    p = (S + 1);



    return;

}



static inline int Eval();

static inline int Termen();

static inline int Factor();



static inline int Eval ()

{

    int ans = 0;



    ans = Termen();



    while(*p == '+' || *p == '-')

    {

        if(*p == '+')

        {

            ++p;



            ans += Termen();

        }

        else

        {

            ++p;



            ans -= Termen();

        }

    }



    return ans;

}



static inline int Termen ()

{

    int ans = 0;



    ans = Factor();



    while(*p == '*' || *p == '/')

    {

        if(*p == '*')

        {

            ++p;



            ans *= Factor();

        }

        else

        {

            ++p;



            ans /= Factor();

        }

    }



    return ans;

}



static inline int Factor ()

{

    int ans = 0;



    if(*p == '(')

    {

        ++p;



        ans = Eval();



        ++p;

    }

    else

    {

        while(isdigit(*p))

            ans = ans * 10 + ((*p) - '0'), ++p;

    }



    return ans;

}



int main()

{

    Read();



    g << Eval() << '\n';



    return 0;

}
