#include <bits/stdc++.h>




using namespace std;







struct muchie{

    int nod1, nod2, cost;

};



vector <muchie> w, wsol;

int rad[400005];



bool comp(muchie A, muchie B){

    return A.cost < B.cost;

}



int radacina(int nod){



    if(rad[nod] == nod) return nod;



    return rad[nod] = radacina(rad[nod]);

}



void unesc(int nod1, int nod2){

    rad[radacina(nod1)] = radacina(nod2);

}



int main()

{

    ifstream fin("apm.in");

    ofstream fout("apm.out");

    int n, m, i, j;

    int sol = 0;

    muchie var;

    fin >> n >> m;

    for(i = 1; i <= m; ++i){

        fin >> var.nod1 >> var.nod2 >> var.cost;

        w.push_back(var);

    }



    for(i = 1; i <= n; ++i) rad[i] = i;



    sort(w.begin(), w.end(), comp);





    for(i = 0; i < m; ++i){



        if(radacina(w[i].nod1) != radacina(w[i].nod2)){

            unesc(w[i].nod1, w[i].nod2);

            sol += w[i].cost;

            wsol.push_back(w[i]);

        }



    }



    int help = wsol.size();

    fout << sol << '\n' << help << '\n';

    for(i = 0; i < help; ++i){

        fout << wsol[i].nod1 << ' ' << wsol[i].nod2 << '\n';

    }



    return 0;

}
