#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <queue>






using namespace std;



ifstream in("swap.in");

ofstream out("swap.out");



const int NMAX = 5 * 1e4;

const int LIM = 1e5;

const int AMAX = 30;



string a, b;

long long res;

int aint[1 + 4 * NMAX];



queue < int > q[AMAX];



void add(int x) {

  for(int i = x; i <= LIM; i += (i & (-i)))

    aint[i]++;

}



int query(int x) {

  int res = 0;

  for(int i = x; i != 0; i -= (i & (-i)))

    res += aint[i];

  return res;

}



int main()

{

  in >> a >> b;



  for(int i = 0; i < a.size(); i++)

    q[a[i] - 'a'].push(i + 1);

  for(int i = 0; i < b.size(); i++) {

    if(q[b[i] - 'a'].empty()) {

      out << "-1\n";

      exit(EXIT_SUCCESS);

    } else {

      int from = q[b[i] - 'a'].front();

      q[b[i] - 'a'].pop();



      res += from - i - 1 + query(b.size()) - query(from);

      add(from);

    }

  }



  out << res << '\n';

  return 0;

}
