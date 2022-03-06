#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>


using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");



struct punct

{

    long long x,y;

};



bool cmp_x(punct A,punct B)

{

    return A.x<B.x;

}



bool cmp_y(punct A,punct B)

{

    return A.y<B.y;

}



long long calc_dist(punct A,punct B)

{

    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);

}



long long search_dist_min(vector<punct> &P,int left,int right)

{

    long long mn=calc_dist(P[left],P[left+1]);

    for(int i=left; i<right; i++)

        for(int j=i+1; j<=right; j++)

            {



                if(calc_dist(P[i],P[j])<mn) mn=calc_dist(P[i],P[j]);

            }

    return mn;

}



long long sol(vector<punct> &P,int left,int right)

{

    if(right-left<=3)

        return search_dist_min(P,left,right);



    int mid=(right+left)/2;

    long long dist_left=sol(P,left,mid);

    long long dist_right=sol(P,mid+1,right);

    long long dist_min=min(dist_left,dist_right);



    long long val=P[mid].x;

    vector<punct>pct_closest;



    for(int i=left; i<=right; i++)

        if(abs(P[i].x-val)<dist_min)

            pct_closest.push_back(P[i]);

    sort(pct_closest.begin(),pct_closest.end(),cmp_y);



    if(pct_closest.size()>=8)

        {

            for(int i=0; i<=(int)pct_closest.size()-8; i++)

                for(int j=i+1; j<=i+7; j++)

                    dist_min=min(calc_dist(pct_closest[i],pct_closest[j]),dist_min);

        }

    else

        {

            for(int j=1; j<(int)pct_closest.size(); j++)

                dist_min=min(calc_dist(pct_closest[0],pct_closest[j]),dist_min);

        }



    return dist_min;

}



int main()

{

    vector<punct>pct;

    int n;

    fin>>n;

    for(int i=0; i<n; i++)

        {

            punct p;

            fin>>p.x>>p.y;

            pct.push_back(p);

        }



    sort(pct.begin(),pct.end(),cmp_x);

    fout<<fixed<<setprecision(6)<<(sqrt((long double)sol(pct,0,n-1)));



    return 0;



}
