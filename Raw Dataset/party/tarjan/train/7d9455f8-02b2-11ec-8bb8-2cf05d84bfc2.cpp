# include <fstream>
# include <vector>
using namespace std ;

struct var { vector < int > V, X, C, D; };

bool greedy_label( vector<var> & v, vector<int> & g, int ii, int b) {
  int n=v.size()-1, qi=1, qo=0, x, y, k, s;
  vector < int > qu(n); qu[0]=ii; g[ii]=b;
  while ( qo<qi ) { x=qu[qo]; ++ qo;
    if (0 == g[x]) { k=v[x].C.size();
      for (s=0; k>s; ++s) { y=v[x].C[s];if (1==g[y]) {return false;}
        if (2==g[y]) { g[y]=0; qu[qi++]=y; } } k=v[x].V.size();
      for (s=0; k>s; ++s) { y=v[x].V[s];if (0==g[y]) {return false;}
        if (2==g[y]) { g[y]=1; qu[qi++]=y; } }
    } else { k=v[x].X.size();
      for (s=0; k>s; ++s) { y=v[x].X[s];if (1==g[y]) {return false;}
        if (2==g[y]) { g[y]=0; qu[qi++]=y; } } k=v[x].D.size();
      for (s=0; k>s; ++s) { y=v[x].D[s];if (0==g[y]) {return false;}
        if (2==g[y]) { g[y]=1; qu[qi++]=y; } }
    }
  }
  return true;
}

int
main ( ) {
  ifstream is ("party.in");
  int n,m,i,x,y,z; is>>n>>m;
  vector < var > v(1+n);
  for ( i=0; m>i; ++i ) {
    is >> x >> y >> z ;
    if (0==z) { v[x].V.push_back(y); v[y].V.push_back(x); } if (1==z) { v[x].C.push_back(y); v[y].D.push_back(x); }
    if (2==z) { v[y].C.push_back(x); v[x].D.push_back(y); } if (3==z) { v[x].X.push_back(y); v[y].X.push_back(x); }
  }
  vector < int > f(1+n,2);
  for ( i=1; n>=i; ++i ) {
    if ( (2 == f[i]) && (0 < v[i].X.size()) ) {
      vector < int > g(f);
      if (greedy_label(v,g,i,1)) { f=g;
      } else { g=f; (void) greedy_label(v,g,i,0);
      }
    }
  }
  ofstream os ("party.out");
  x=0; for ( i=1; n>=i; ++i ) { if ( 0!=f[i] ) { ++x; } }
  os << x << endl; for ( i=1; n>=i; ++i ) { if ( 0!=f[i] ) { os << i << endl; } }
}
