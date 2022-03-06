#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



struct solu{

    int k, l, d;

};



solu nepitagora(int a, int b){

    if(b == 0){

        return {1, 0, a};

    }

    solu idk = nepitagora(b, a%b);

    solu kdi = {idk.l, idk.k-(a/b)*idk.l, idk.d};

    return kdi;

}



int main()

{

    int a, b;

    fin >> a >> b;

    solu ba = nepitagora(a, b);

    while(ba.k < 0){

        ba.k += b;

    }

    fout << ba.k;

    return 0;

}
