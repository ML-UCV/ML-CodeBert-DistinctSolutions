#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int i,n;

char c[100005];



int expresie();

int factor();

int termen();



int main()

{

    fin >> c;

    n=strlen(c);

    i=0;

    fout << expresie();



    return 0;

}



int expresie()

{

    int s=factor();

    while (c[i]=='+' || c[i]=='-')

    {

        i++;

        if (c[i-1]=='+') s+=factor();

        else s-=factor();

    }

    return s;

}



int factor()

{

    int s=termen();

    while (c[i]=='*' || c[i]=='/')

    {

        i++;

        if (c[i-1]=='*') s*=termen();

        else s/=termen();

    }

    return s;

}



int termen()

{

    int s=0;

    if (c[i]=='(')

    {

        i++;

        s=expresie();

        i++;

    }

    else

    {

        while (c[i]>='0' && c[i]<='9')

        {

            s=s*10+(c[i]-'0');

            i++;

        }

    }

    return s;

}
