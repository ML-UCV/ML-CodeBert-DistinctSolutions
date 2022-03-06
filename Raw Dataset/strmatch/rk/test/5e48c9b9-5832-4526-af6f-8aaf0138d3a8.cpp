#include <fstream>
#include <string.h>
#include <vector>


using namespace std;

ifstream fi("strmatch.in");

ofstream fo("strmatch.out");

const int lmax=2e6, mod1=1e5+7, mod2=1e5+21, baza=75;

char T[lmax+5], P[lmax+5];

int lgt, lgp, putere1=1, putere2=1, codp1, codp2, rhash1, rhash2, cnt;

vector <int> sol;



int cod(char c)

{

    return (c-'0');

}



int main()

{

    fi>>P>>T;

    lgp=strlen(P);

    lgt=strlen(T);



    for(int i=1; i<=lgp-1; i++)

    {

        putere1=(putere1*baza)%mod1;

        putere2=(putere2*baza)%mod2;

    }



    for(int i=0; i<lgp; i++)

    {

        codp1=(codp1*baza+cod(P[i]))%mod1;

        codp2=(codp2*baza+cod(P[i]))%mod2;

        rhash1=(rhash1*baza+cod(T[i]))%mod1;

        rhash2=(rhash2*baza+cod(T[i]))%mod2;

    }



    if(rhash1==codp1 && rhash2==codp2)

    {

        cnt++;

        sol.push_back(0);

    }



    for(int i=lgp; i<lgt; i++)

    {

        rhash1=(((rhash1-putere1*cod(T[i-lgp]))%mod1+mod1)*baza%mod1+cod(T[i]))%mod1;

        rhash2=(((rhash2-putere2*cod(T[i-lgp]))%mod2+mod2)*baza%mod2+cod(T[i]))%mod2;







        if(rhash1==codp1 && rhash2==codp2)

        {

            cnt++;

            if(cnt<=1000)

                sol.push_back(i-lgp+1);

        }

    }



    fo<<cnt<<"\n";

    for(auto p:sol)

        fo<<p<<" ";



    fi.close();

    fo.close();

    return 0;

}
