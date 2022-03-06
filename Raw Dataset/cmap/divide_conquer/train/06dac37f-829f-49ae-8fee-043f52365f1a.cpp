#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>


using namespace std;



bool cmpX(pair<int, int> &a, pair<int, int> b)

{

    return a.first < b.first;

}

bool cmpY(pair<int, int> &a, pair<int, int> b)

{

    return a.second < b.second;

}



double dist(pair<int, int> &a, pair<int, int> &b)

{

    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));

}



double nSquaredSol(vector<pair<int, int>> &coordonate)

{

    double minDist = numeric_limits<double>::max();

    for (int i = 0; i < coordonate.size(); i++)

    {

        for (int j = i + 1; j < coordonate.size(); j++)

        {

            double d = dist(coordonate[i], coordonate[j]);

            if (d != 0)

                minDist = min(minDist, d);

        }

    }

    return minDist;

}



double getMinDistFromStrip(vector<pair<int, int>> &strip, double d)

{

    for (int i = 0; i < strip.size(); i++)

    {

        for (int j = i + 1; j < strip.size() && strip[j].second - strip[i].second < d; j++)

        {

            d = min(d, dist(strip[i], strip[j]));

        }

    }

    return d;

}



void showVect(vector<pair<int, int>> &vec)

{

    for (pair<int, int> &p : vec)

    {

        cout << p.first << " " << p.second << "\n";

    }

    cout << "\n";

}



double solve(vector<pair<int, int>> &sortatX, vector<pair<int, int>> &sortatY)

{

    if (sortatX.size() <= 11)

    {

        return nSquaredSol(sortatX);

    }



    pair<int, int> midPoint = sortatX[sortatX.size() / 2];



    vector<pair<int, int>> sortatX_st;

    vector<pair<int, int>> sortatX_dr;



    vector<pair<int, int>> sortatY_st;

    vector<pair<int, int>> sortatY_dr;



    for (int i = 0; i < sortatY.size(); i++)

    {

        if (sortatX[i].first <= midPoint.first)

        {

            sortatX_st.push_back(sortatX[i]);

        }

        else

        {

            sortatX_dr.push_back(sortatX[i]);

        }

        if (sortatY[i].first <= midPoint.first)

        {

            sortatY_st.push_back(sortatY[i]);

        }

        else

        {

            sortatY_dr.push_back(sortatY[i]);

        }

    }



    double distSt = solve(sortatX_st, sortatY_st);

    double distDr = solve(sortatX_dr, sortatY_dr);



    double d = min(distSt, distDr);



    vector<pair<int, int>> strip;

    for (int i = 0; i < sortatY.size(); i++)

    {

        if (abs(sortatY[i].first - midPoint.first) < d)

        {

            strip.push_back(sortatY[i]);

        }

    }



    return min(d, getMinDistFromStrip(strip, d));

}



double nLognSol(vector<pair<int, int>> &coordonate)

{

    vector<pair<int, int>> sortatX(coordonate);

    vector<pair<int, int>> sortatY(coordonate);

    sort(sortatX.begin(), sortatX.end(), cmpX);

    sort(sortatY.begin(), sortatY.end(), cmpY);



    return solve(sortatX, sortatY);

}



ifstream fin("cmap.in");

ofstream fout("cmap.out");



int main()

{
    int n;

    fin >> n;

    vector<pair<int, int>> coordonate(n);

    for (int i = 0; i < n; i++)

    {

        int x, y;

        fin >> x >> y;

        coordonate[i].first = x;

        coordonate[i].second = y;

    }



    double solutie = nLognSol(coordonate);

    fout << fixed;

    fout.precision(6);

    fout << solutie;



    return 0;

}
