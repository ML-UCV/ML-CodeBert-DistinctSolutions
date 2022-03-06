#include <bits/stdc++.h>






using namespace std;



ifstream f("swap.in");

ofstream g("swap.out");



int N, M;

int bit[50005], a[50005], b[50005];

char S[50005];

queue<int> Q[26];



void update(int pos) {

   for (int i = pos; i <= N; i += i & (-i))

       bit[i]++;

}

int calc(int pos) {

   int sum = 0 ;

   for (int i = pos; i > 0; i -= i & (-i))

       sum += bit[i];

   return sum;

}

int main()

{

    f.get(S, 50005), f.get();

    N = strlen(S);

    for (int i = 1; i <= N; ++i)

        a[i] = S[i - 1] - 'a', Q[a[i]].push(i);



    f.get(S, 50005), f.get();

    M = strlen(S);

    for (int i = 1; i <= N; ++i)

        b[i] = S[i - 1] - 'a';

    if (N != M) {

        g << -1;

        return 0;

    }



    int ans = 0;

    for (int i = 1; i <= N; ++i)

    if (Q[b[i]].empty()) {

        g << -1;

        return 0;

    }

    else {

        int j = Q[b[i]].front();

        Q[b[i]].pop();

        ans += j - i + calc(N) - calc(j);

        update(j);

    }



       g << ans << '\n';



    return 0;

}
