#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in") ;

ofstream fout("inversmodular.out") ;



long long inv(int a,int b)

{

    return 1 < a ? b-inv(b%a,a)*b/a : 1 ;

}



int main()

{

    int a , b ;

    fin >> a >> b;

    fout << inv(a,b) ;

}
