#include <fstream>
#include <queue>
#include <cstring>


using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

queue <int> que[51];

char S[50001], S2[50001];

int i, x[50001], S_fr[51], S2_fr[51], sol, n, aib[50001];

void update(int pos){

    while(pos <= n){

        aib[pos]++;

        pos = pos + (pos & (-pos));

    }

}

int quary(int pos){

    int s = 0;

    while(pos >= 1){

        s = s + aib[pos];

        pos = pos - (pos & (-pos));

    }

    return s;

}

int main()

{ f >> (S + 1);

    f >> (S2 + 1);

    for(i = 1; S[i] != 0; i++){

        S_fr[S[i] - 'a' + 1]++;

        S2_fr[S2[i] - 'a' + 1]++;

    }

    for(i = 1; i <= 'z' - 'a' + 1; i++)

        if(S_fr[i] != S2_fr[i]){

            g << -1 ;

            return 0;

        }

    for(i = 1; S2[i] != 0; i++)

        que[S2[i] - 'a' + 1].push(i);

    for(i = 1; S[i] != 0; i++){

        x[i] = que[S[i] - 'a' + 1].front();

        que[S[i] - 'a' + 1].pop();

    }

    n = strlen(S + 1);

    for(i = 1; i <= n; i++){

        sol = sol + quary(n) - quary(x[i]);

        update(x[i]);

    }

    g << sol;

    return 0;

}
