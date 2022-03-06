#include <bits/stdc++.h>


using namespace std;



const int NMAX = 100 + 5;

const int MMAX = 1000 + 5;



int N, M;

int x[2 * NMAX];

int a[MMAX], b[MMAX];



int main() {

    ifstream cin("party.in");

    ofstream cout("party.out");

    cin >> N >> M;

    for (int i = 1; i <= M; ++i) {

        cin >> a[i] >> b[i];

        --a[i], a[i] *= 2;

        --b[i], b[i] *= 2;

        int type;

        cin >> type;

        if (type == 1 || type == 3)

            b[i] ^= 1;

        if (type == 2 || type == 3)

            a[i] ^= 1;

    }

    for (int i = 1; i < 2 * N; i += 2)

        x[i] = true;



    while (true) {

        vector <int> clauses;

        for (int i = 1; i <= M; ++i)

            if (!(x[a[i]] || x[b[i]]))

                clauses.push_back(i);

        if (clauses.empty())

            break;

        const int where = clauses[rand() % clauses.size()];

        const int pos = rand() % 2 ? a[where] : b[where];

        x[pos] ^= 1, x[pos ^ 1] ^= 1;

    }

    vector <int> sol;

    for (int i = 0; i < 2 * N; i += 2)

        if (x[i])

            sol.push_back(i / 2 + 1);

    cout << sol.size() << endl;

    for (int i = 0; i < sol.size(); ++i)

        cout << sol[i] << '\n';

    return 0;

}
