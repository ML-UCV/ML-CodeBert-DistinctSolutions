#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char s[100005];

int pozitie(int ss, int dd, char c1, char c2)

{

    int ct=0;

    for(int i=dd; i>=ss; i--)

    {

        if(s[i]=='(')

            ct++;

        if(s[i]==')')

            ct--;

        if(ct==0&&(s[i]==c1||s[i]==c2))

            return i;

    }

    return -1;

}



int eval(int st, int dr)

{

    int p=pozitie(st, dr, '+', '-');

    if(p==-1)

        p=pozitie(st, dr, '/', '*');

    if(p==-1)

        if(s[st]=='(')

            return eval(st+1, dr-1);

    if(p==-1)

        {

            int nr=0;

            for(int i=st; i<=dr; i++)

                nr=nr*10+(s[i]-'0');

                return nr;

        }

    switch(s[p])

    {

    case '+':

        return (eval(st, p-1)+eval(p+1, dr));

        break;

    case '-':

        return (eval(st, p-1)-eval(p+1, dr));

        break;

    case '*':

        return (eval(st, p-1)*eval(p+1, dr));

        break;

    case '/':

        return (eval(st, p-1)/eval(p+1, dr));

        break;

    }

}



int main()

{

    f.getline(s, 100005);

    int lgs=strlen(s);

    g<<eval(0, lgs-1);

    return 0;

}
