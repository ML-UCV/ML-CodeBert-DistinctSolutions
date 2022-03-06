#include <bits/stdc++.h>
typedef std::pair <long long, long long> punct;



int N;

std::vector <std::pair <long long, long long> > X, Y, V(100005);



std::ifstream f("cmap.in");

std::ofstream g("cmap.out");



long long dist2(punct A, punct B) {

    return (A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second);

}



long long divetimp(int st=0, int dr=X.size(), std::vector <punct> &X=X, std::vector <punct> &Y=Y) {

    if(st>=dr - 1)

        return 4e18;

    if(dr-st == 2) {

        if(Y[st] > Y[st+1])

            std::swap(Y[st], Y[st+1]);

        return dist2(X[st], X[st+1]);

    }



    int m = (st+dr)/2;

    long long min = std::min(divetimp(st, m, X, Y), divetimp(m, dr, X, Y));



    std::merge(Y.begin()+st, Y.begin()+m, Y.begin()+m, Y.begin()+dr, V.begin());

    std::copy(V.begin(), V.begin() + (dr-st), Y.begin()+st);



    int ts = 0;

    for (int i=st; i<dr; i++) {

        if(abs(Y[i].second - X[m].first) <= min)

            V[ts++] = Y[i];

    }



    for(int i=0, j; i<ts; i++) {

        for(j=i+1; j<ts && j-i < 8; j++)

            min = std::min(min, dist2(V[j], V[i]));

    }



    return min;

}



void citire() {

    f >> N;

    int second, first;

    for (int i=1; i<=N; i++) {

        f >> second >> first;

        X.push_back({second, first});

    }

}

void rezolvare() {

    std::sort(X.begin(), X.end());

    for (int i=0; i<N; i++)

        Y.push_back(std::make_pair(X[i].second, X[i].first));



    g << std::fixed << std::setprecision(6) << sqrt(1.0 * divetimp()) << "\n";

}



int main()

{

    citire();

    rezolvare();



    return 0;

}
