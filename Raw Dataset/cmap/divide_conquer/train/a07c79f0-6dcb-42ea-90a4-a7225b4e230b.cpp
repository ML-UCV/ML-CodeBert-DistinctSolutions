#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;


ifstream fin("cmap.in");
ofstream fout("cmap.out");

struct point
{
 double x, y;
};
vector<point>p;

double sqrtdist(point a, point b)
{
 return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}


bool ycmp(point a, point b)
{
 return a.y < b.y;
}

bool xcmp(point a, point b)
{
 if(a.x < b.x)
 {
  return 1;
 }
 if(a.x == b.x)
 {
  return ycmp(a, b);
 }
 return 0;
}


double closest_pair(int l, int r)
{
 double minVal = 1e16;

 if(r - l <= 2)
 {
  for(int i = l; i <= r; i++)
  {
   for(int j = i + 1; j <= r; j++)
   {
    if(minVal > sqrtdist(p[i], p[j]))
    {
     minVal = sqrtdist(p[i], p[j]);
    }
   }
  }
  return minVal;
 }


 int mid = (l + r)/2;
 minVal = min(closest_pair(l, mid), closest_pair(mid + 1, r));

 vector<point>y;
 for(int i = l; i <= r; i++)
 {
  double horizontal = (p[mid].x - p[i].x) * (p[mid].x - p[i].x);
  if(horizontal < minVal)
  {
   y.push_back(p[i]);
  }
 }

 sort(y.begin(), y.end(), ycmp);
 for (int i = 0; i < y.size(); i++)
  {
  point a = y[i];
  for (int j = i + 1; j < y.size(); j++)
  {
   if(j-i > 7)
   {
    break;
   }
   point b = y[j];
   if(minVal > sqrtdist(a, b))
   {
    minVal = sqrtdist(a, b);
   }
  }
 }

 return minVal;
}

int main()
{
 int n;
 fin >> n;

 for(int i = 0; i < n; ++i)
 {
  point a;
  fin >> a.x >> a.y;
  p.push_back(a);
 }
 fin.close();

 sort(p.begin(), p.end(), xcmp);

 fout << fixed << setprecision(7) << sqrt(closest_pair(0, n - 1));
 fout.close();

 return 0;

}
