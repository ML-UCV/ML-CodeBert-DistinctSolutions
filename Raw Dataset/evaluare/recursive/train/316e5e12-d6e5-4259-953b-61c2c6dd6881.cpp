#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

char s[100005];

int cautas(int st, int dr, char s1, char s2)

{

    int nr=0;

    for(int i=dr; i>=st; i--)

    {

        if(s[i]==')')

            nr++;

        if(s[i]=='(')

            nr--;

        if(nr==0 && (s1==s[i] || s2==s[i]))

            return i;

    }

    return -1;

}

int num(int st, int dr)

{

    int numar=0;

    for(int i=st; i<=dr; i++)

        numar=numar*10+(s[i]-'0');

    return numar;



}

int solve(int st, int dr)

{

    int poz=cautas(st,dr,'+','-');

    if(poz!=-1)

    {

        int e1=solve(st,poz-1);

        int e2=solve(poz+1,dr);

        if(s[poz]=='+')

            return e1+e2;

        return e1-e2;

    }

    poz=cautas(st,dr,'*','/');

    if(poz!=-1)

    {

        int e1=solve(st,poz-1);

        int e2=solve(poz+1,dr);

        if(s[poz]=='*')

            return e1*e2;

        return e1/e2;

    }

    if(s[st]=='(' && s[dr]==')')

        return solve(st+1,dr-1);

    return num(st,dr);

}

int main()

{

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin.getline(s,100005);

    int n=strlen(s);

    fout<<solve(0,n-1);

    return 0;

}
