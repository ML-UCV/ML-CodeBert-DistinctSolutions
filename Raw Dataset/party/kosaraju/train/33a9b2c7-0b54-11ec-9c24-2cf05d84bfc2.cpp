#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

ifstream cin ("party.in");
ofstream cout ("party.out");

void do_dfspl (int cur_node, vector < vector < int > > &gr,
    vector < bool > &fol, stack < int > &stk) {

  fol[cur_node] = true;
  for (int x : gr[cur_node]) {
    if (fol[x]) {
      continue;
    }

    do_dfspl (x, gr, fol, stk);
  }

  stk.push (cur_node);
}

void do_dfsmin (int cur_node, vector < vector < int > > &gr,
    vector < bool > &fol, vector < int > &ctc, int &cur_ctc) {

  fol[cur_node] = true;
  ctc[cur_node] = cur_ctc;
  for (int x : gr[cur_node]) {
    if (fol[x]) {
      continue;
    }

    do_dfsmin (x, gr, fol, ctc, cur_ctc);
  }
}

int main () {

  ios::sync_with_stdio (false);
  cin.tie (0); cout.tie (0);

  int n, m;
  cin >> n >> m;

  const int SIZE = 2 * n + 1;

  vector < int > opp (SIZE);
  vector < vector < int > > gr (SIZE), inv (SIZE);

  for (int i = 1; i <= n; ++ i) {
    opp[i] = i + n;
    opp[i + n] = i;
  }

  int x, y, t;
  while (m --) {

    cin >> x >> y >> t;
    if (t == 1) {
      y = opp[y];
    }
    else if (t == 2) {
      x = opp[x];
    }
    else if (t == 3) {
      x = opp[x];
      y = opp[y];
    }

    gr[opp[x]].push_back (y);
    gr[opp[y]].push_back (x);
    inv[y].push_back (opp[x]);
    inv[x].push_back (opp[y]);
  }

  stack < int > stk;
  vector < bool > fol (SIZE);
  vector < int > ctc (SIZE);

  for (int i = 1; i < SIZE; ++ i) {
    if (fol[i]) {
      continue;
    }

    do_dfspl (i, gr, fol, stk);
  }

  fill (fol.begin (), fol.end (), false);

  int nr_of_ctc = 0;
  while (stk.size ()) {

    int cur = stk.top ();
    stk.pop ();

    if (fol[cur]) {
      continue;
    }

    ++ nr_of_ctc;
    do_dfsmin (cur, inv, fol, ctc, nr_of_ctc);
  }

  vector < int > lvl (nr_of_ctc + 1);
  vector < vector < int > > gr_ctc (nr_of_ctc + 1);

  for (int i = 1; i < SIZE; ++ i) {
    for (int x : gr[i]) {
      if (ctc[i] == ctc[x]) {
        continue;
      }

      ++ lvl[ctc[x]];
      gr_ctc[ctc[i]].push_back (ctc[x]);
    }
  }

  queue < int > q;
  vector < int > val (nr_of_ctc + 1, -1);
  vector < int > opp_ctc (nr_of_ctc + 1);

  for (int i = 1; i <= n; ++ i) {
    opp_ctc[ctc[i]] = ctc[opp[i]];
    opp_ctc[ctc[opp[i]]] = ctc[i];
  }

  for (int i = 1; i <= nr_of_ctc; ++ i) {
    if (lvl[i] == 0) {
      q.push (i);
    }
  }

  while (not q.empty ()) {

    int cur = q.front ();
    q.pop ();

    if (val[cur] != -1) {
      continue;
    }

    val[cur] = 0;
    val[opp_ctc[cur]] = 1;

    for (int x : gr_ctc[cur]) {
      if (-- lvl[x] == 0) {
        q.push (x);
      }
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; ++ i) {
    if (val[ctc[i]] == 1) {
      ++ cnt;
    }
  }

  cout << cnt << '\n';
  for (int i = 1; i <= n; ++ i) {
    if (val[ctc[i]] == 1) {
      cout << i << '\n';
    }
  }
}
