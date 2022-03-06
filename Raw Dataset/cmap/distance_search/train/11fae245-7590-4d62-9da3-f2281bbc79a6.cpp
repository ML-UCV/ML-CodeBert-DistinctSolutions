#include <bits/stdc++.h>






using namespace std;



pair <int,int> v[100001];

double distanta(pair <int,int> n, pair <int,int> m)

{

    pair <double,double> a = {n.first,n.second},b = {m.first,m.second};

    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));

}

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

set <pair <int,int> > s;

int main()

{

    InParser cin("cmap.in");

    ofstream cout("cmap.out");

    ios_base::sync_with_stdio(false);

    int n,i;

    cin >> n;

    for(i = 1; i <= n; i++)

    {

        cin >> v[i].first >> v[i].second;



    }

    double minim = (double)(1LL << 60);

    sort(v + 1,v + n + 1);

    int j = 1;

    for(i = 1; i <= n; i++)

    {

        int cv = sqrt(ceil(minim));

        while(v[i].first - v[j].first >= minim)

        {

            s.erase({v[j].second,v[j].first});

            j++;

        }

        auto it1 = s.lower_bound({v[i].second - cv, v[i].first});

        auto it2 = s.upper_bound({v[i].second + cv, v[i].first});



        for (auto it = it1; it != it2; ++it)

        {

            int dx = v[i].first - it->second;

            int dy = v[i].second - it->first;

            minim = min(minim, 1.0 * dx * dx + 1.0 * dy * dy);

        }

        s.insert({v[i].second, v[i].first});

    }

    cout << fixed << setprecision(6) << sqrt(minim);

    return 0;

}
