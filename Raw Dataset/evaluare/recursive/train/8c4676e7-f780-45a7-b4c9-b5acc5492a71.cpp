#include <fstream>
#include <cstring>


using namespace std;

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");

char s[100005];

int cautare (int st, int dr, char s1, char s2)

{

    int nivel=0;

    for(int i=dr; i>=st; i--)

    {

        if(s[i]=='(') nivel++;

        else if(s[i]==')') nivel--;

        else if(nivel==0 && (s[i]==s1 || s[i]==s2))

            return i;

    }

    return -1;

}

int evaluare (int st, int dr)

{

    int poz=cautare(st, dr, '+', '-');

    if(poz!=-1)

    {

        if(s[poz]=='+')

            return evaluare(st, poz-1)+evaluare(poz+1, dr);

        else

            return evaluare(st, poz-1)-evaluare(poz+1, dr);

    }

    poz=cautare(st, dr, '*', '/');

    if(poz!=-1)

    {

        if(s[poz]=='*')

            return evaluare(st, poz-1)*evaluare(poz+1, dr);

        else

            return evaluare(st, poz-1)/evaluare(poz+1, dr);

    }

    if(s[st]=='(')

        return evaluare(st+1, dr-1);

    int nr=0;

    for(int i=st; i<=dr; i++)

        nr=nr*10+(s[i]-'0');

    return nr;

}

int main()

{

    fin.getline(s, 100005);

    fout<<evaluare (0, strlen(s)-1);

    return 0;

}
