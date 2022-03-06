#include <bits/stdc++.h>




using namespace std;



const int mxn = 100 * 1000 + 10, md = 9917;



int arb[ 4 * mxn ];



pair< int, int > sir[ mxn ];

int sol[ mxn ];



int n;



void update(int nod, int st, int sf, int poz){

    arb[ nod ]++;

    arb[ nod ] %= md;

    if(st < sf){

        int mid = (st + sf) / 2;

        if(mid >= poz)

            update(2 * nod, st, mid, poz);

        else

            update(2 * nod + 1, mid + 1, sf, poz);

    }

}



int query(int nod, int st, int sf, int poz){

    if(poz <= st)

        return arb[ nod ];

    else if(sf < poz)

        return 0;

    int mid = (st + sf)/2;

    return (query(2 * nod, st, mid, poz) + query(2 * nod + 1, mid + 1, sf, poz)) % md;

}



int main()

{

    ifstream cin("inv.in");

    ofstream cout("inv.out");

    cin>> n;

    for(int i = 0, x; i < n; i++){

        cin>> x;

        sir[ i ] = make_pair(x, i);

    }

    sort(sir, sir + n);

    int s = 0;

    for(int i = 0; i < n; i++){

        s += query(1, 0, n - 1, sir[ i ].second);

        s %= md;

        update(1, 0, n - 1, sir[ i ].second);

    }

    cout<< s;

    return 0;

}
