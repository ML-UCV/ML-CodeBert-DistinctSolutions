#include<bits/stdc++.h>


using namespace std;



ifstream f ("schi.in");

ofstream g ("schi.out");



constexpr int NMAX = 30005;



struct nod {

    nod *st, *dr;

    int prior;

    int val;

    int sz;

};



nod nil;



int ans[NMAX], ask[NMAX];



nod *mod_fiu (nod *T, int care, nod *fiu) {

    if (care == 0) T->st = fiu;

    else T->dr = fiu;



    T->sz = T->st->sz + 1 + T->dr->sz;



    return T;

}



nod *join (nod *st, nod *dr) {

    if (st == &nil) return dr;

    if (dr == &nil) return st;



    if (st->prior >= dr->prior) {

        return mod_fiu(st, 1, join(st->dr, dr));

    }

    else {

        return mod_fiu(dr, 0, join(st, dr->st));

    }

}



pair <nod*, nod*> split (nod *T, int K) {

    if (T == &nil) return {&nil, &nil};



    if (T->st->sz >= K) {

        auto t = split(T->st, K);



        return {t.first, mod_fiu(T, 0, t.second)};

    }

    else {

        auto t = split(T->dr, K - T->st->sz - 1);



        return {mod_fiu(T, 1, t.first), t.second};

    }

}



int Acces (nod *T, int poz) {

    auto t = split(T, poz+1);

    auto t_ = split(t.first, poz);



    T = join(join(t_.first, t_.second), t.second);



    return t_.second->val;

}



nod *Adaug (nod *T, int val, int poz) {

    auto t = split(T, poz);



    nod *now = new nod;

    now->st = &nil;

    now->dr = &nil;

    now->prior = rand();

    now->sz = 1;

    now->val = val;



    T = join(join(t.first, now), t.second);



    return T;

}



nod *Sterg (nod *T, int poz) {

    auto t = split(T, poz+1);

    auto t_ = split(t.first, poz);



    T = join(t_.first, t.second);



    return T;

}



int main () {

    srand(time(NULL));

    int N;



    f >> N;



    nod *T = &nil;



    for (int i = 1; i <= N; ++ i ) {

        f >> ask[i];



        T = Adaug(T, i, i-1);

    }



    for (int i = N; i >= 1; -- i ) {

        int val = Acces(T, ask[i]-1);

        T = Sterg(T, ask[i]-1);



        ans[val] = i;

    }



    for (int i = 1; i <= N; ++ i ) {

        g << ans[i] << '\n';

    }



    return 0;

}
