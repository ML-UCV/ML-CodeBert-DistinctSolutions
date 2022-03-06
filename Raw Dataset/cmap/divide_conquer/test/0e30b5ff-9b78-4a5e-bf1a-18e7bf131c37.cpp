#include <bits/stdc++.h>


using namespace std;



int n;

vector <pair<int, int>> V;



void citire(const char* fileName)

{

    ifstream in (fileName);

    in >> n;

    int x, y;

    for (int i = 0; i < n; ++i)

    {

        in >> x >> y;

        V.push_back ({x, y});

    }



    in.close();

}



long long dist2 (pair<int, int> p1, pair<int, int> p2)

{

    return (long long) (p1.first - p2.first) * (p1.first - p2.first) + (long long) (p1.second - p2.second) * (p1.second - p2.second);

}



long long solutie (int st, int dr)

{

    if (dr - st == 1)

        return dist2 (V[st], V[dr]);



    else if (dr - st == 2)

        return min(dist2(V[st], V[st + 1]), min(dist2(V[st], V[st + 2]), dist2(V[st + 1], V[st + 2])));



    int mij = (st + dr) / 2;



    long long d = min(solutie (st, mij), solutie (mij + 1, dr));



    vector<pair<int, int>> M;



    int delta = (int) (ceil (sqrt (d)));



    for (int i = st; i <= dr; i++)

        if (abs(V[i].first - V[mij].first) <= delta)

            M.push_back(V[i]);



    sort (M.begin(), M.end(), [](pair <int, int> p1, pair <int, int> p2) -> bool {

        return p1.second < p2.second;

    });



    for (int i = 0; i < M.size(); i++)

        for (int j = i + 1; j <= i + 7 && j < M.size(); j++)

            d = min(d, dist2(M[i], M[j]));



    return d;

}



int main()

{

    citire("cmap.in");



    sort(V.begin(), V.end());



    ofstream out ("cmap.out");

    out << fixed << setprecision(6) << sqrt (solutie (0, n-1)) << '\n';

    out.close();



    return 0;

}
