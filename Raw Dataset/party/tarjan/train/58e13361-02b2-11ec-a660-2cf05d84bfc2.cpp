#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



ifstream in("party.in");

ofstream out("party.out");



const int NMAX = 100;

const int MMAX = 1000;



struct Data {

  int x;

  int y;

  int z;

};



int n, m;

int p[1 + NMAX];

vector < int > sol;

Data v[1 + MMAX];



int main()

{

  in >> n >> m;

  fill(p + 1, p + n + 1, 1);



  for(int i = 1; i <= m; i++)

    in >> v[i].x >> v[i].y >> v[i].z;

  bool ok = false;



  while(ok == false) {

    ok = true;

    for(int i = 1; i <= m; i++) {

      Data &e = v[i];

      if(e.z == 0) {

        if(p[e.x] == 0 && p[e.y] == 0) {

          p[e.x] = p[e.y] = 1;

          ok = false;

          break;

        }

      }



      if(e.z == 1) {

        if(p[e.x] == 0 && p[e.y] != 0) {

          p[e.y] = 0;

          ok = false;

          break;

        }

      }



      if(e.z == 2) {

        if(p[e.y] == 0 && p[e.x] != 0) {

          p[e.x] = 0;

          ok = false;

          break;

        }

      }



      if(e.z == 3) {

        if(p[e.x] == 1 && p[e.y] == 1) {

          p[e.y] = 0;

          ok = false;

          break;

        }

      }

    }

  }



  for(int i = 1; i <= n; i++) {

    if(p[i] == 1)

      sol.push_back(i);

  }



  out << sol.size() << '\n';

  for(int i = 0; i < sol.size(); i++) {

    out << sol[i] << '\n';

  }



  in.close();

  out.close();

  return 0;

}
