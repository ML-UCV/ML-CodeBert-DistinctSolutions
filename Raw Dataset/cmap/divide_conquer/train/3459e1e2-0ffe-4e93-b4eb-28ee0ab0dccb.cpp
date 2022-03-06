#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;



ifstream fin ("cmap.in");

ofstream fout ("cmap.out");



int n;

pair < int, int > V[100010];



class cmp

{

    public :

        bool operator () (const pair < int, int > &a, const pair < int, int > &b)

        {

            return (a.second < b.second);

        }

};



int Modul(const int &a)

{

 if (a < 0) return -a;

 return a;

}



long long Minim(const long long &a, const long long &b)

{

 if (a < b) return a;

 return b;

}



long long Euclid_Dist(const pair < int, int > &a, const pair < int, int > &b)

{

 return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);

}





long long Solve(int left, int right)

{

 if (right - left == 1)

 {

  return Euclid_Dist(V[left], V[right]);

 }

 else if (right - left == 2)

 {

  return Minim(Euclid_Dist(V[left], V[left + 1]), Minim(Euclid_Dist(V[left], V[left + 2]), Euclid_Dist(V[left + 1], V[left + 2])));

 }



 int middle = (left + right) >> 1;

 long long d = Minim(Solve(left, middle), Solve(middle + 1, right));

 vector < pair < int, int > > A;

 int un_d = int(sqrt(d) + 1);

 for (int i = left; i <= right; i ++)

 {

  if (Modul(V[i].first - V[middle].first) <= un_d)

  {

   A.push_back(V[i]);

  }

 }

 sort(A.begin(), A.end(), cmp());

 for (int i = 0; i < A.size(); i ++)

 {

  for (int j = i + 1; j <= i + 7 && j < A.size(); j ++)

  {

   d = Minim(d, Euclid_Dist(A[i], A[j]));

  }

 }

 return d;

}



int main()

{

 fin >> n;

 for (int i = 1; i <= n; i ++) fin >> V[i].first >> V[i].second;

 sort(V + 1, V + 1 + n);



 fout << fixed << setprecision(6) << sqrt(Solve(1, n)) << '\n';

 return 0;

}
