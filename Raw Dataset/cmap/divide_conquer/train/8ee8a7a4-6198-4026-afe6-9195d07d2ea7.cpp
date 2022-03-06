#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>


using namespace std;

ifstream in("cmap.in");
ofstream out("cmap.out");

double dist(pair<int,int> P1, pair<int,int> P2)
{
    return sqrt((double) (P1.first-P2.first)*(P1.first-P2.first) + (double) (P1.second-P2.second)*(P1.second-P2.second));
}

void mergePoints(vector<pair<int,int> > &Points,int left,int right)
{
    int middle = (left + right) / 2;
    int i,j,k;
    vector<pair<int,int> > auxPoints(right-left+1);

    i=left;
    j=middle+1;
    k=0;

    while (i <= middle && j<= right)
        if (Points[i].first < Points[j].first)
            auxPoints[k++] = Points[i++];
        else auxPoints[k++] = Points[j++];

    for (int q=i;q<=middle;q++)
        auxPoints[k++] = Points[q];
    for (int q=j;q<=right;q++)
        auxPoints[k++] = Points[q];

    for (int q=left;q<=right;q++)
        Points[q] = auxPoints[q-left];
}

double divide(int left, int right, vector<pair<int,int> > &Points, vector<pair<int,int> > &Points2)
{
    int middle = (left + right) / 2;
    double minDist = 0x3f3f3f3f;;
    vector<pair<int,int> > closePoints;

    if (right - left <= 2)
    {
        for (vector<pair<int,int> >::iterator it = Points.begin()+left; it != Points.begin()+right-1; it++)
            for (vector<pair<int,int> >::iterator it2 = it+1; it2 != Points.begin()+right; it2++)
                minDist = min(minDist,dist(*it,*it2));

        sort(Points2.begin()+left,Points2.begin()+right+1);
        return minDist;
    }

    minDist = min(divide(left,middle,Points,Points2),divide(middle,right,Points,Points2));
    mergePoints(Points2,left,right);

    closePoints.clear();
    for (vector<pair<int,int> >::iterator it = Points2.begin()+left; it != Points2.begin()+right+1; it++)
        if (abs((*it).second - Points[middle].first) < minDist)
            closePoints.push_back(*it);

    for (vector<pair<int,int> >::iterator it = closePoints.begin();it != closePoints.end();it++)
        for (vector<pair<int,int> >::iterator it2 = it+1; it2 != closePoints.end() && it2-it != 8;it2++)
            minDist = min(minDist,dist(*it,*it2));

    return minDist;
}

int main()
{
    int N;
    vector<pair<int,int> > Points,Points2;

    in>>N;
    for (int i=0;i<N;i++)
    {
        int x,y;

        in>>x>>y;
        Points.push_back(make_pair(x,y));
    }
    sort(Points.begin(),Points.end());

    for (vector<pair<int,int> >::iterator it = Points.begin();it != Points.end();it++)
        Points2.push_back(make_pair((*it).second,(*it).first));

    out<<setprecision(6)<<fixed<<divide(0,Points.size(),Points,Points2)<<'\n';

    in.close();
    out.close();
    return 0;
}
