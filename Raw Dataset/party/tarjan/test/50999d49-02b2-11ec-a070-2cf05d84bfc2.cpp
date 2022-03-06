#include <bits/stdc++.h>
using namespace std;

struct queries {

  int a, b, c;

};

ifstream in("party.in");

ofstream out("party.out");

vector < queries > q;

vector < int > ans;

bool T[105];

bool modify() {

  int ok = false;

  for (auto it : q) {

    if (it.c == 0) {

      if (!T[it.a] && !T[it.b]) {

        bool p = rand() % 2;

        T[it.a] = p;

        T[it.b] = !p;

        ok = true;

      }

    }

    if (it.c == 1) {

      if (!T[it.a] && T[it.b]) {

        T[it.b] = 0;

        ok = true;

      }

    }

    if (it.c == 2) {

      if (T[it.a] && !T[it.b]) {

        T[it.a] = 0;

        ok = true;

      }

    }

    if (it.c == 3) {

      if (T[it.a] && T[it.b]) {

        bool p = rand() % 2;

        T[it.a] = p;

        T[it.b] = !p;

        ok = true;

      }

    }

  }

  return ok;

}

int main() {

  int n, m;

  in >> n >> m;

  while(m--) {

    int a, b, c;

    in >> a >> b >> c;

    q.push_back({a, b, c});

  }

  while(modify());

  for (int i = 1; i <= n; i++) {

    if (T[i]) {

      ans.push_back(i);

    }

  }

  out << ans.size() << "\n";

  for (auto it : ans) out << it << "\n";

  return 0;

}
