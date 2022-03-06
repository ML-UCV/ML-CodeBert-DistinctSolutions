#include <bits/stdc++.h>
int N, M;

std::vector <std::pair <long double, int> > ADC[1505];



inline void AddEdge(int x, int y, long double w) {

    ADC[x].push_back({log(w), y});

    ADC[y].push_back({log(w), x});

}



bool Equal(long double x, long double y) {

    return std::abs(x-y) < 1e-9L;

}



std::ifstream In("dmin.in");

std::ofstream Out("dmin.out");



std::priority_queue <std::pair <long double, int>, std::vector <std::pair <long double, int> >, std::greater <std::pair <long double, int> >> PQ;

long double Dist[1505];

int DP[1505];



void Dijkstra() {

    for (int i=1; i<=N; ++i)

        Dist[i] = std::numeric_limits<long double>::infinity();

    Dist[1] = 0;

    DP[1] = 1;

    PQ.push({0, 1});



    std::pair <long double, int> Top;

    while (!PQ.empty()) {

        Top = PQ.top();

        PQ.pop();



        if (!Equal(Top.first, Dist[Top.second])) continue;

        for (auto Edge:ADC[Top.second]) {

            if (Equal(Dist[Edge.second], Dist[Top.second] + Edge.first))

                DP[Edge.second] += DP[Top.second];

            else if (Dist[Edge.second] > Dist[Top.second] + Edge.first)

                Dist[Edge.second] = Dist[Top.second] + Edge.first,

                DP[Edge.second] = DP[Top.second],

                PQ.push({Dist[Edge.second], Edge.second});



            DP[Edge.second] %= 104659;

        }

    }

}



void Citire() {

    In >> N >> M;

    for (int i=0, x, y, w; i<M; ++i)

        In >> x >> y >> w, AddEdge(x, y, (long double)(w));

}



void Rezolvare() {

    Dijkstra();

    for (int i=2; i<=N; ++i)

        Out << DP[i] << ' ';

}



int main()

{

    Citire();

    Rezolvare();



    return 0; }
