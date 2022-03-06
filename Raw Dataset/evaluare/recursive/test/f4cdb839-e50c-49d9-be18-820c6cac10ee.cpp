#include <fstream>
#include <string.h>
using namespace std;

ifstream fi("evaluare.in");

ofstream fo("evaluare.out");

int i;

string A;

int produs();

int expresie();

int aduna()

{

    int rez=produs();

    while(A[i]=='+' or A[i]=='-')

    {

        if(A[i]=='+')

        {

            i++;

            rez=rez+produs();

        }

        else

        {

            i++;

            rez=rez-produs();

        }

    }

    return rez;

}

int produs()

{

    int rez=expresie();

    while(A[i]=='*' || A[i]=='/')

    {

        if(A[i]=='*')

        {

            i++;

            rez=rez*expresie();

        }

        else

        {

            i++;

            rez=rez/expresie();

        }

    }

    return rez;

}

int expresie()

{

    int rez=0;

    if(A[i]=='(')

    {

        i++;

        rez=aduna();

        i++;

    }

    else

    {

        while(A[i]>='0' && A[i]<='9')

        {

            rez=rez*10+(A[i]-'0');

            i++;

        }

    }

    return rez;

}

int main()

{

    fi>>A;

    fo<<aduna();

    return 0;

}
