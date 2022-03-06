#include <bits/stdc++.h>
using namespace std;



const int SPQR = 50005,

SIGM = 26;



int n;



vector<int> aps[SIGM];

char sr1[SPQR],

sr2[SPQR];

int aib[SPQR],

gnm[SIGM];



inline int lsb(int arg) {

    return arg&-arg;

}



inline int cod(int arg) {

    return arg - 'a';

}



inline void update(int pos, int val) {

    while(pos < SPQR) {

        aib[pos]+= val;

        pos+= lsb(pos);

    }

}



inline int query(int pos) {

    int ant = 0;



    while(pos > 0) {

        ant+= aib[pos];

        pos-= lsb(pos);

    }



    return ant;

}



void ave(void) {

    int lst[SIGM];



    memset(lst, 0xFF, sizeof(lst));

    for(int i=1; i<=n; ++i)

        aps[cod(sr2[i])].push_back(i);

}



void caesar(int &ant) {

    int f1[SIGM],

    f2[SIGM];

    int pos;



    ant = 0;

    memset(f1, 0x00, sizeof(f1));

    memset(f2, 0x00, sizeof(f2));



    for(int i=1; i<=n; ++i) {

        ++ f1[ cod(sr1[i]) ];

        ++ f2[ cod(sr2[i]) ];

    }



    for(int i=0; i<SIGM; ++i) {

        if(f1[i] != f2[i]) {

            ant = -1;

            return;

        }

    }



    for(int i=1; i<=n; ++i) {

        pos = aps[ cod(sr1[i]) ][ gnm[cod(sr1[i])] ];

        ant+= pos + query(pos) - i;

        update(1, 1);

        update(pos+1, -1);

        ++ gnm[ cod(sr1[i]) ];

    }

}



int main(void) {

    ifstream fi("swap.in");

    ofstream fo("swap.out");

    int ant;



    fi>>(sr1 + 1)>>(sr2 + 1);

    n = strlen(sr1 + 1);



    ave();

    caesar(ant);



    fo<<ant<<'\n';



    fi.close();

    fo.close();

    return 0;

}
