#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");







long long n,k,a,b;

double dminr;



double dist(pair <long long, long long> A, pair <long long, long long> B)

{

    double d;

    long long v;

    v=((long long)(A.first-B.second)*(long long)(A.first-B.second)+(long long)(A.second-B.first)*(long long)(A.second-B.first));

    d=sqrt((double)v);

    return d;

}



vector <pair <long long, long long> > PX;

set <pair <long long, long long> > SY;

set <pair <long long, long long> > :: iterator it,cit;





int main()

{



    fin>>n;

    for (long long i=1;i<=n;i++)

    {

        long long x,y;

        fin>>x>>y;

        PX.push_back(make_pair(x,y));

    }

    sort(PX.begin(),PX.end());

    dminr=10000000.0;

    k=0;

    SY.insert(make_pair(PX[0].second,PX[0].first));

    for (long long i=1;i<n;i++)

    {



        while (1)

        {

            if (k==i)

                break;

            if (PX[i].first-PX[k].first>dminr)

            {

                SY.erase(make_pair(PX[k].second,PX[k].first));

                k++;

            }

            else

                break;

        }



        SY.insert(make_pair(PX[i].second,PX[i].first));

        it=SY.lower_bound(make_pair(PX[i].second,PX[i].first));

        cit=it;



        if (cit!=SY.begin())

        {

            cit--;

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



            }

        }

        if (cit!=SY.begin())

        {

            cit--;

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



            }

        }

        if (cit!=SY.begin())

        {

            cit--;

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



            }

        }

        if (cit!=SY.begin())

        {

            cit--;

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



            }

        }



        cit=it;

        cit++;

        if (cit!=SY.end())

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



                cit++;

            }

        if (cit!=SY.end())

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



                cit++;

            }

        if (cit!=SY.end())

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



                cit++;

            }

        if (cit!=SY.end())

            if (dist(PX[i],*cit)<dminr)

            {

                dminr=dist(PX[i],*cit);



                cit++;

            }

    }



    fout<<setprecision(6)<<fixed<<dminr;

    return 0;

}
