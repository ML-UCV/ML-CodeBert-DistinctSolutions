#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int EvalExpresie();



char e[100005];

int poz, lg;



int getVal(){

    int val = 0;

    while(e[poz] >= '0' && e[poz] <= '9')

        val = val * 10 + (e[poz] - '0'), ++poz;

    return val;

}



int EvalFactor(){

    int f;

    if(e[poz] == '('){

        ++poz;

        f = EvalExpresie();

        ++poz;

    }

    else

        f = getVal();

    return f;

}



int EvalTermen(){

    int f = EvalFactor();

    while(poz < lg){

        if(e[poz] == '*')

            ++poz, f *= EvalFactor();

        else if(e[poz] == '/')

            ++poz, f /= EvalFactor();

        else break;

    }

    return f;

}



int EvalExpresie(){

    int t = EvalTermen();

    while(poz < lg){

        if(e[poz] == '+')

            ++poz, t += EvalTermen();

        else if(e[poz] == '-')

            ++poz, t -= EvalTermen();

        else break;

    }



    return t;

}



int main()

{

    ios_base::sync_with_stdio(false);

    fin >> e;

    lg = strlen(e);



    fout << EvalExpresie() << '\n';

    return 0;

}
