#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
#include <set>






using namespace std;



ifstream cin("inv.in");

ofstream cout("inv.out");







typedef pair < int, int > pii;

typedef long long ll;

typedef long double ld;

typedef unsigned int ui;

typedef unsigned long long ull;



int sol = 0;

const int MOD = 9917;



void merge(int st, int mid, int dr, vector < int > &v) {



  int i = st, j = mid + 1;

  vector < int > aux(dr - st + 1);



  int cnt = 0, ind = 0;

  while (i <= mid and j <= dr) {

    if (v[i] <= v[j]) {

      aux[ind ++] = v[i ++];

    }

    else {

      aux[ind ++] = v[j ++];

      cnt += mid - i + 1;

    }

  }



  while (i <= mid) aux[ind ++] = v[i ++];

  while (j <= dr) aux[ind ++] = v[j ++];



  for (int i = st; i <= dr; ++ i) {

    v[i] = aux[i - st];

  }



  sol += cnt;

  sol %= MOD;

}



void mergeSort(int st, int dr, vector < int > &v) {



  if (st == dr) return;



  int mid = (st + dr) >> 1;



  mergeSort(st, mid, v);

  mergeSort(mid + 1, dr, v);



  merge(st, mid, dr, v);

}



int main() {
  ios::sync_with_stdio(false);

  cin.tie(0);cout.tie(0);



  int n;

  cin >> n;



  vector < int > v(n);

  for (auto &x : v) cin >> x;



  mergeSort(0, n - 1, v);

  cout << sol << '\n';

}
