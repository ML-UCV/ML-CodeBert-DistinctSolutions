#include <bits/stdc++.h>
using namespace std;



string problem = "cmmdc";

ifstream fin (problem + ".in");

ofstream fout(problem + ".out");







int gcd(int a,int b)

{

    if(!b)

        return a;

    return gcd(b,a % b);

}



int main()

{

    int a,b;

    fin >> a >> b;

    if(gcd(a,b) == 1)

    {

        fout << 0 << "\n";

        return 0;

    }

    fout << gcd(a,b);

}
