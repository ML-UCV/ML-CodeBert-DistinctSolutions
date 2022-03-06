#include <fstream>


std::ifstream in ("schi.in");

std::ofstream out ("schi.out");



const int MAXN = 30000;

int v[MAXN + 1], aint[4*MAXN], rez[MAXN+1];



int query (int p, int st, int dr, int val){

  if(st == dr)

    return st;

  else{

    int m = (st + dr) / 2;

    if(aint[2*p] < val)

      return query(2*p + 1, m + 1, dr, val - aint[2*p]);

    else

      return query(2*p, st, m, val);

  }

}

void update (int p, int st, int dr, int poz){

  if(st == dr){

    aint[p] = 0;

  }

  else{

    int m = (st + dr) / 2;

    if(poz <= m)

      update(2*p, st, m, poz);

    else

      update(2*p + 1, m + 1, dr, poz);

    aint[p] = aint[2*p] + aint[2*p + 1];

  }

}

void build(int p, int st, int dr)

{

  if (st == dr)

    aint[p] = 1;

  else{

    int m = (st + dr) / 2;

    build(2*p, st, m);

    build(2*p + 1, m + 1, dr);

    aint[p] = aint[2*p] + aint[2*p + 1];

  }

}





int main()

{

    int N, loc;

    in >> N;

    for (int i = 1; i <= N; ++i)

        in >> v[i];

    build(1, 1, N);



    for (int i = N; i > 0; --i){

        loc = query(1, 1, N, v[i]);

        rez[loc] = i;

        update(1, 1, N, loc);

    }

    for (int i = 1; i <= N; ++i)

        out << rez[i] << '\n';

    return 0;

}
