#include <bits/stdc++.h>






using namespace std;



void citire (int &n, vector <pair<int, int>> &PCT)

{

    ifstream f("cmap.in");

    f >> n;

    for(int i = 0; i < n; i++)

    {

        int first, second;

        f >> first >> second;

        PCT.push_back (make_pair (first, second));

    }

    f.close();

}



double distanta (pair<int, int> A, pair<int, int> B)

{

    double a = A.first - B.first;

    double b = A.second - B.second;

    return sqrt(pow(a, 2) + pow(b, 2));

}



bool cmp1 (const pair<int, int> &A, const pair<int, int> &B)

{

    return A.first < B.first;

}

bool cmp2 (const pair<int, int> &A, const pair<int, int> &B)

{

    return A.second < B.second;

}



double di (int st, int dr, vector <pair<int, int>> &PCT, vector <pair<int, int>> &PCTsortateY)

{

    if(dr - st == 1)

        return INT_MAX;

    else if(dr - st == 2)

    {

        if (PCTsortateY[st].second > PCTsortateY[st + 1].second)

            swap(PCTsortateY[st], PCTsortateY[st + 1]);

        return distanta(PCT[0], PCT[1]);

    }



    int m = (st + dr) / 2;

    double dist = min (di(st, m, PCT, PCTsortateY), di(m, dr, PCT, PCTsortateY));



    vector<pair<int,int>> temp(dr - st);

    merge(PCTsortateY.begin() + st, PCTsortateY.begin() + m, PCTsortateY.begin() + m, PCTsortateY.begin() + dr, temp.begin(), cmp2);

    copy(temp.begin(), temp.begin() + (dr - st), PCTsortateY.begin() + st);



    vector<pair<int,int>> temp2;

    for(unsigned i = st; i < dr; i++)

        if(abs(PCTsortateY[i].first - PCT[m].first) <= dist)

            temp2.push_back(PCTsortateY[i]);



    for(unsigned i = 0; i < temp2.size(); i++)

        for(unsigned j = i + 1; j < temp2.size() && temp2[j].second - temp2[i].second <= dist; j++)

            dist = min(dist, distanta (temp2[i], temp2[j]));



    return dist;

}



int main()

{

    int n;

    vector <pair<int, int>> PCT;



    citire(n, PCT);

    sort(PCT.begin(), PCT.end(), cmp1);

    vector <pair<int, int>> PCTsortateY = PCT;



    ofstream g("cmap.out");

    g << fixed << setprecision(6) << di(0, n, PCT, PCTsortateY);

    g.close();



    return 0;

}
