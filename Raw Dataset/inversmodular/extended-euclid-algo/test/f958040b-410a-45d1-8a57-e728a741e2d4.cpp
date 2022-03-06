#include <fstream>
using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");

int A, n;

struct elem

{

    int div;

    int x0;

    int y0;

};

elem euclid_extins (int a, int b)

{

    if(b==0)

    {

        elem ultim;

        ultim.div=a; ultim.x0=1; ultim.y0=0;

        return ultim;

    }

    elem d=euclid_extins(b, a%b);



    elem nou;

    nou.x0=d.y0;

    nou.y0=d.x0-(a/b)*d.y0;

    nou.div=d.div;

    return nou;

}

int main()

{

    fin>>A>>n;

    elem rez=euclid_extins(A, n);

    int afis=rez.x0;

    if(afis>n) afis%=n;

    else while(afis<0) afis+=n;

    fout<<afis;

    return 0;

}
