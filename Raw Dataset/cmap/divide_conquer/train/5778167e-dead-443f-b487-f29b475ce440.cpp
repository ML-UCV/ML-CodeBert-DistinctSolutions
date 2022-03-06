#include <iostream>
#include <fstream>#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;





struct punct

{

    int x = 0;

    int y = 0;

};



double distEuclid(punct a, punct b)

 {

    double x = a.x - b.x;

    double y = a.y - b.y;

    double dist;



    dist = pow(x, 2) + pow(y, 2);

    dist = sqrt(dist);



    return dist;

}



bool cmpDupaX(const punct& a, const punct& b)

{

    return a.x < b.x;

}



bool cmpDupaY(const punct& a, const punct& b)

{

    return a.y < b.y;

}





double distMinPunctePlanRec(vector <punct> & puncte, int st, int dr, vector<punct> &puncteY)

{

    if (dr - st == 1)

    {

        return 2147483647;

    }



    if (dr - st == 2)

    {

        if (puncteY[st].y > puncteY[st + 1].y)

            swap(puncteY[st], puncteY[st + 1]);

        return distEuclid(puncte[0], puncte[1]);

    }



    int m = (st + dr) / 2;

    double distStanga = distMinPunctePlanRec(puncte, st, m, puncteY);

    double distDreapta = distMinPunctePlanRec(puncte, m, dr, puncteY);

    double distMinStDr = min(distStanga, distDreapta);





    vector <punct> puncteAux(dr - st);

    merge(puncteY.begin() + st, puncteY.begin() + m, puncteY.begin() + m, puncteY.begin() + dr, puncteAux.begin(), cmpDupaY);

    copy(puncteAux.begin(), puncteAux.begin() + (dr - st), puncteY.begin() + st);





    vector <punct> banda;

    for (int i = st; i < dr; ++i)

    {

        if (abs(puncteY[i].x - puncte[m].x) <= distMinStDr)

            banda.push_back(puncteY[i]);

    }





    double distMinOverall = distMinStDr;

    for (int i = 0; i<banda.size(); ++i)

        for (int j = i + 1; j < banda.size() && banda[j].y - banda[i].y <= distMinStDr; ++j)

        {

            double distCur = distEuclid(banda[i], banda[j]);

            if (distCur < distMinOverall)

                distMinOverall = distCur;

        }



    return distMinOverall;

}



void distMinPunctePlan()

{

    ifstream f("cmap.in");

    ofstream g("cmap.out");

    int n;

    f >> n;



    vector <punct> puncte(n);



    for (int i = 0; i < n; ++i)

    {

        f >> puncte[i].x;

        f >> puncte[i].y;

    }



    sort(puncte.begin(), puncte.end(), cmpDupaX);



    vector <punct> puncteY = puncte;



    g << fixed;

    g << setprecision(6) << distMinPunctePlanRec(puncte, 0, puncte.size(), puncteY) << "\n";

}



int main()

{

    distMinPunctePlan();

    return 0;

}
