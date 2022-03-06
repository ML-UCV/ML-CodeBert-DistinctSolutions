#include <bits/stdc++.h>


using namespace std;



typedef long long int lint;



const int NMAX = 100 + 5;

const int MMAX = 1000 + 5;



int N, M;

int x[NMAX];

bool is_neg[MMAX][2];

int who[MMAX][2];



bool eval_clause(bool is_neg_a, bool is_neg_b, int a, int b) {

    bool a_prim = x[a];

    if (is_neg_a) {

        a_prim = !x[a];

    }

    bool b_prim = x[b];

    if (is_neg_b) {

        b_prim = !x[b];

    }

    return a_prim || b_prim;

}



int main() {

    ifstream cin("party.in");

    ofstream cout("party.out");



    cin >> N >> M;

    for (int i = 1; i <= M; ++i) {

        cin >> who[i][0] >> who[i][1];

        int type;

        cin >> type;

        if (type == 0) {

        } else if (type == 1) {

            is_neg[i][1] = 1;

        } else if (type == 2) {

            is_neg[i][0] = 1;

        } else {

            is_neg[i][0] = 1;

            is_neg[i][1] = 1;

        }

    }



    bool done = false;

    while (!done) {

        done = true;

        vector <int> clauses;

        for (int i = 1; i <= M; ++i) {

            if (!eval_clause(is_neg[i][0], is_neg[i][1], who[i][0], who[i][1])) {

                clauses.push_back(i);

                done = false;

            }

        }

        if (!done) {

            random_shuffle(clauses.begin(), clauses.end());

            const int where = clauses[0];

            if (rand() % 2) {

                x[who[where][0]] ^= 1;

            } else {

                x[who[where][1]] ^= 1;

            }

        }

    }



    vector <int> sol;

    for (int i = 1; i <= N; ++i) {

        if (x[i]) {

            sol.push_back(i);

        }

    }



    cout << sol.size() << endl;

    for (int i = 0; i < sol.size(); ++i) {

        cout << sol[i] << '\n';

    }

    return 0;

}
