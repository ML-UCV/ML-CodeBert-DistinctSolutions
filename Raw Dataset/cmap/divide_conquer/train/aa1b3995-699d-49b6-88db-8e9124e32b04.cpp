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



long long distanta (pair<int, int> A, pair<int, int> B)

{

    return (long long)(A.first - B.first) * (A.first - B.first) + (long long)(A.second - B.second) * (A.second - B.second);

}



bool cmp (pair<int, int> A, pair<int, int> B)

{

    return A.second < B.second;

}



long long di (int st, int dr, vector <pair<int, int>> &PCT)

{

    if(dr - st == 1)

    {

        return distanta (PCT[st], PCT[dr]);



    }

    else if(dr - st == 2)

    {

        long long dist1 = distanta (PCT[st], PCT[st+1]);

        long long dist2 = distanta (PCT[st], PCT[st+2]);

        long long dist3 = distanta (PCT[st+1], PCT[st+2]);



        long long minim = dist1;

        if(dist2 < minim)

            minim = dist2;

        if(dist3 < minim)

            minim = dist3;

        return minim;





    }



    int m = (st + dr) / 2;

    long long dist = min (di(st, m, PCT), di(m + 1, dr, PCT));

    int delta = (int) (ceil(sqrt(dist)));



    vector<pair<int,int>> temp;

    for(unsigned i = st; i <= dr; i++)

        if(abs(PCT[i].first - PCT[m].first) <= delta)

            temp.push_back(PCT[i]);

    sort(temp.begin(), temp.end(), cmp);



    for(unsigned i = 0; i < temp.size(); i++)

        for(unsigned j = i + 1; j <= i + 7 && j < temp.size(); j++)

            dist = min(dist, distanta (temp[i], temp[j]));



    return dist;

}



int main()

{

    int n;

    vector <pair<int, int>> PCT;



    citire(n, PCT);

    sort(PCT.begin(), PCT.end());



    ofstream g("cmap.out");

    g << fixed << setprecision(6) << sqrt(di(0, n - 1, PCT));

    g.close();



    return 0;

}
