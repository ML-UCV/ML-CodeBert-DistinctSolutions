#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>
#include <fstream>
using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n, q, logN;



int main()

{

 fin >> n >> q;



 logN = log2(n);



 vector<vector<int> > d(logN + 1, vector<int>(250001));



 for (int i = 1; i <= n; ++i)

  fin >> d[0][i];



 for (int pw = 1; pw <= logN; ++pw)

  for (int i = 1; i <= n; ++i)

   d[pw][i] = d[pw - 1][d[pw - 1][i]];



 for (int i = 0; i < q; i++)

 {

  int nod, x;



  fin >> nod >> x;



  for (int pw = logN; pw >= 0; --pw)

   if (((1 << pw) & x))

    nod = d[pw][nod];



  fout << nod << "\n";

 }

}
