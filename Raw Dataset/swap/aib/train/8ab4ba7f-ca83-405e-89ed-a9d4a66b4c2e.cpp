#include<fstream>
#include<vector>
#include<deque>
#include<cstring>






using namespace std;

typedef int var;



ifstream fin("swap.in");

ofstream fout("swap.out");



deque<var> IND['z'-'a' + 1];

var n;

var A[50001];



inline var zeros(var v) {

    return (v&(-v));

}



void adauga(var val, var ind) {

    for(;ind<=n; ind += zeros(ind)) {

        A[ind] += val;

    }

}





var afla(var ind) {

    var s = 0;

    for(;ind; ind -= zeros(ind)) {

        s += A[ind];

    }

    return s;

}



var aflaelem(var ind) {

    return afla(ind) - afla(ind-1);

}



char SIR[50001];

void citire() {

    var poz = 0;

    fin>>SIR;

    n = strlen(SIR);

    for(var i=0; i<n; i++) {

        IND[SIR[i]-'a'].push_back(++poz);

        adauga(1, poz);

    }



    char c;

    var sum = 0;

    fin>>SIR;

    if(strlen(SIR) != n) {fout<<-1; return;}

    for(var i=0; i<n; i++) {

        c = SIR[i];

        if(IND[c-'a'].empty()) {fout<<-1; return;}

        poz = IND[c-'a'].front();

        IND[c-'a'].pop_front();

        sum += afla(poz) - 1;



        adauga(-1, poz);

    }

    fout<<sum;

}



int main() {

    citire();

    return 0;

}
