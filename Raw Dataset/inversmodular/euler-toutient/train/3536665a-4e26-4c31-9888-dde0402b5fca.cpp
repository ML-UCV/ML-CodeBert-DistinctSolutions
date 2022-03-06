#include <bits/stdc++.h>






using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



int a , n;



inline int Lgput(int x , int p)

{

    int s = 1;

    while(p)

    {

        if(p & 1)

            s = 1LL * s * x % n;

        p /= 2;

        x = 1LL * x * x % n;

    }

    return s;

}



inline int Fi(int x)

{

    int fi = n , d = 2;

    while(d * d <= x && x > 1)

    {

        if(x % d == 0)

        {

            fi = fi / d * (d - 1);

            while(x % d == 0)

                x /= d;

        }

        d++;

    }

    if(x > 1)

        fi = fi / x * (x - 1);

    return fi;

}



int main()

{

    int p;

    fin >> a >> n;

    p = Fi(n);

    fout << Lgput(a , p - 1) << "\n";

    fin.close();

    fout.close();

}
