#include <bits/stdc++.h>


using namespace std;



ifstream fin("cmap.in");
ofstream fout("cmap.out");

struct point
{
 int x, y;
};

point v[100001], v2[100001], v3[100001];
int n;


bool compare(point a, point b)
{
 if (a.x < b.x)
  return true;
 if (a.x > b.x)
  return false;
 return true;
}

bool compare2(point a, point b)
{
 if (a.y < b.y)
  return true;
 if (a.y > b.y)
  return false;
 return true;
}

long long dist(point a, point b)
{
 return ((long long)a.x-(long long)b.x)*((long long)a.x-(long long)b.x)+((long long)a.y-(long long)b.y)*((long long)a.y-(long long)b.y);
}


long long solve(int lower, int upper)
{
 if (lower == upper)
  return 9e18;

 if (upper - lower == 1)
  return dist(v[lower], v[upper]);

 int mid = lower + (upper - lower) / 2, i, j;
 long long res1 = solve(lower, mid);
 long long res2 = solve(mid+1, upper);
 if (res1 > res2)
  res1 = res2;

 i = lower; j = mid + 1;
 double l = (double)v[mid].x + (v[mid+1].x - v[mid].x) / 2.0;

 for (int k = i; k <= j; k++)
  v2[k] = v[k];
 sort(v2 + i, v2 + j + 1, compare2);

 int c = 0;
 for (int k = i; k <= j; k++)
  if (fabs((double)v2[k].x - l) <= res1)
  {
   c++;
   v3[c] = v2[k];
  }
 for (int k = 1; k <= c; k++)
 {
  for (int l = 1; l <= 7; l++)
  {
   if (k + l <= c)
   {
    if (res1 > dist(v3[k], v3[k+l]))
     res1 = dist(v3[k], v3[k+l]);
   }
  }
 }

 return res1;
}

int main()
{
 int i;
 fin >> n;
 for (i = 1; i <= n; i++)
  fin >> v[i].x >> v[i].y;
 fin.close();
 sort(v + 1, v + n + 1, compare);

 long long res = solve(1, n);
 fout << fixed << setprecision(6) << sqrt(res) << '\n';
 fout.close();
 return 0;
}
