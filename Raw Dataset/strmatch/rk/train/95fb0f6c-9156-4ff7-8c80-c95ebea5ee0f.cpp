#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e9 + 7;

const int M3 = 1e9 + 21;

const int P = 73;

ifstream in("strmatch.in");

ofstream out("strmatch.out");

struct hashh {

  long long h1, h3;

};

hashh hashA, hashB;

bool verif() {

  if (hashA.h1 == hashB.h1 && hashA.h3 == hashB.h3) {

    return true;

  }

  return false;

}

vector < int > ans;

int main() {

  string a, b;

  long long P1 = 1, P2 = 1, P3 = 1;

  hashA.h1 = hashA.h3 = hashB.h1 = hashB.h3 = 0;

  in >> a >> b;

  for (int i = 1; i <= a.size() - 1; i++) {

    P1 = (P1 * P) % M1;

    P3 = (P3 * P) % M3;

  }

  if (a.size() > b.size()) {

    out << "0\n";

    return 0;

  }

  for (int i = 0; i < a.size(); i++) {

    hashA.h1 = (hashA.h1 * P + a[i]) % M1;

    hashA.h3 = (hashA.h3 * P + a[i]) % M3;

    hashB.h1 = (hashB.h1 * P + b[i]) % M1;

    hashB.h3 = (hashB.h3 * P + b[i]) % M3;

  }

  if (verif()) {

    ans.push_back(0);

  }

  for (int i = a.size(); i < b.size(); i++) {

    hashB.h1 = (hashB.h1 - ((b[i - a.size()] * P1) % M1) + M1);

    hashB.h3 = (hashB.h3 - ((b[i - a.size()] * P3) % M3) + M3);

    hashB.h1 = (hashB.h1 * P + b[i]) % M1;

    hashB.h3 = (hashB.h3 * P + b[i]) % M3;

    if (verif()) {

      ans.push_back(i - a.size() + 1);

    }

  }

  out << ans.size() << "\n";

  for (int i = 0; i < min((int)ans.size(), 1000); i++) {

    out << ans[i] << " ";

  }

  return 0;

}
