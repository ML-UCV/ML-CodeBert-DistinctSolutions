#include <bits/stdc++.h>




using namespace std;



class InParser {

private:

 FILE *fin;

 char *buff;

 int sp;



 char read_ch() {

  ++sp;

  if (sp == 4096) {

   sp = 0;

   fread(buff, 1, 4096, fin);

  }

  return buff[sp];

 }



public:

 InParser(const char* nume) {

  fin = fopen(nume, "r");

  buff = new char[4096]();

  sp = 4095;

 }



 InParser& operator >> (int &n) {

  char c;

  while (!isdigit(c = read_ch()) && c != '-');

  int sgn = 1;

  if (c == '-') {

   n = 0;

   sgn = -1;

  } else {

   n = c - '0';

  }

  while (isdigit(c = read_ch())) {

   n = 10 * n + c - '0';

  }

  n *= sgn;

  return *this;

 }



 InParser& operator >> (long long &n) {

  char c;

  n = 0;

  while (!isdigit(c = read_ch()) && c != '-');

  long long sgn = 1;

  if (c == '-') {

   n = 0;

   sgn = -1;

  } else {

   n = c - '0';

  }

  while (isdigit(c = read_ch())) {

   n = 10 * n + c - '0';

  }

  n *= sgn;

  return *this;

 }

};



int n, m;

int dp[250005][20], lg2[250005];



void calcLog()

{

    for (int i = 1; i < 250005; i++)

        lg2[i] = lg2[i / 2] + 1;

}



void calcDp()

{

    for (int k = 1; k <= lg2[n]; k++)

    {

        for (int nod = 1; nod <= n; nod++)

            if (dp[nod][k - 1] == 0)

                dp[nod][k] = 0;

            else

                dp[nod][k] = dp[dp[nod][k - 1]][k - 1];

    }



}



inline int p2(int x)

{

    return (1 << x);

}



int Query(int nod, int p)

{

    int nodAns = nod;



    for (int i = 0; i <= lg2[p]; i++)

    {

        if (p & p2(i))

            nodAns = dp[nodAns][i];

    }



    return nodAns;

}



int main()

{

    InParser fin("stramosi.in");

    ofstream fout ("stramosi.out");



    fin >> n >> m;

    for (int i = 1; i <= n; i++)

        fin >> dp[i][0];



    calcLog();

    calcDp();



    for (int i = 1; i <= m; i++)

    {

        int q, p;

        fin >> q >> p;

        fout << Query(q, p) << "\n";

    }

    return 0;

}
