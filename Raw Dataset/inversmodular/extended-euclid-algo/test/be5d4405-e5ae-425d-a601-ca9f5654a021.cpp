#include <bits/stdc++.h>


using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");
void invers_modular(long long int a , long long int b ,long long int & x ,long long int & y)

{

    if(b == 0)

    {

        x = 1, y = 1;

    }

    else

    {

        long long int x1 , y1;

        invers_modular(b , a % b , x1 , y1);

        x = y1;

        y = x1 - a / b * y1;

    }

}



int main()

{

    long long int a , n , x , y;

    fin >> a >> n;

    invers_modular(a, n , x ,y);

    while(x < 0)

        x += n;

    fout << x;

    return 0;

}
