#include <bits/stdc++.h>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");



char e[100005];

int i, lg;



int Expresie();

int Termen();

int Factor();



int main()

{

    fin.getline(e, 100005);

    fin.close();

    lg=strlen(e);

    fout<<Expresie();

    fout.close();

    return 0;

}



int Expresie()

{

    int sum=Termen();

    while (i<lg && (e[i]=='+' || e[i]=='-'))

        if (e[i]=='+') {i++; sum+=Termen();}

        else {i++; sum-=Termen();}

    return sum;

}



int Termen()

{

    int prod=Factor();

    while (i<lg && (e[i]=='*' || e[i]=='/'))

        if (e[i]=='*') {i++; prod*=Factor();}

        else {i++; prod/=Factor();}

    return prod;

}



int Factor()

{

    int semn=1, val=0;

    while (e[i]=='-') semn=-semn, i++;

    if (e[i]=='(')

    {

        i++; val=Expresie(); i++;

        return semn*val;

    }

    while (e[i]>='0' && e[i]<='9')

        val=val*10+(e[i]-'0'), i++;

    return semn*val;





}
