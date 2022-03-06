#include <iostream>
#include <fstream>


using namespace std;



ifstream in ("inversmodular.in");

ofstream out("inversmodular.out");



namespace Maths{

    typedef long long LL;

    using Maths::LL;



    const LL mod=998244353;
    void modularInverseUtil(LL & cmmdc, LL &x, LL &y, LL a, LL b){

        if(b==0){

            cmmdc=a;

            x=1; y=0;

            return;

        }

        modularInverseUtil(cmmdc, x, y, b, a%b);

        LL x0=x;

        x=y;

        y=x0-y*(a/b);

    }

    inline LL expLog(LL x, LL put){

        LL prod=1;

        while(put){

            if(put&1)

                prod*=x, prod%=mod;

            put>>=1, x=(x*x)%mod;

        }

        return prod;

    }

    inline LL invMod(LL a, LL b=mod){

        LL x, y, cmdc;

        modularInverseUtil(cmdc, x, y, a, b);



        return (x<0) ? b+x%b : x%b;

    }
};

long long x, y;

int main()

{

    in>>x>>y;

    out<<Maths::invMod(x, y);

    return 0;

}
