#include <bits/stdc++.h>
std::ifstream input (std::string("strmatch")+".in");

std::ofstream output(std::string("strmatch")+".out");



int N, M;

char A[2000005], B[2000005];

int count;

std::vector <int> sol;

void addToSol(int idx) {

    ++ count;

    if (sol.size() < 1000) sol.push_back(idx);

}



int LPS[2000005];

void computeLPS(char S[], int N) {

    int len = 0;

    for (int i=2; i<=N; ++i) {

        while (len != 0 && S[len+1] != S[i])

            len = LPS[len];

        if (S[len+1] == S[i]) ++ len;

        LPS[i] = len;

    }

}

void KMP() {

    computeLPS(A, N);

    int len = 0;

    for (int i=1; i<=M; ++i) {

        while (len != 0 && A[len+1] != B[i])

            len = LPS[len];

        if (A[len+1] == B[i]) ++ len;

        if (len == N) addToSol(i-len);

    }

}



int main()

{

    input >> (A+1) >> (B+1);

    N = strlen(A+1);

    M = strlen(B+1);

    KMP();

    output << count << '\n';

    for (auto &it:sol) output << it << ' ';



    return 0;

}
