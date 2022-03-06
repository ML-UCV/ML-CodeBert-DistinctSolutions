#include <bits/stdc++.h>


using namespace std;

int aint[4 * 30005], clasament[30005], val;
vector<int> v;

int query( int p, int st, int dr ) {
  if( st == dr ) {
    return st;
  }
  int mid = ( st + dr ) / 2;
  if( val <= aint[2*p] )
    return query(2*p,st,mid);
  else {
    val -= aint[2*p];
    return query(2*p+1,mid+1,dr);
  }
}

void update( int p, int st, int dr, int poz ) {
  if( st == dr ) {
    aint[p] = val;
    return ;
  }
  int mid = (st + dr) / 2;
  if( poz <= mid )
    update(2*p,st,mid,poz);
  else
    update(2*p+1,mid+1,dr,poz);
  aint[p] = aint[2*p] + aint[2*p+1];
}

int main() {
    ifstream fin("schi.in");
    ofstream fout("schi.out");
    int n, i, x;
    fin>>n;
    for( i = 1; i <= n; i ++ ) {
      fin>>x;
      v.push_back(x);
      val = 1;
      update(1,1,n,i);
    }
    reverse(v.begin(),v.end());
    for( i = 0; i < v.size(); i ++ ) {
      val = v[i];
      int poz = query(1,1,n);
      val = 0;
      update(1,1,n,poz);
      clasament[poz] = n - i;
    }
    for( i = 1; i <= n; i ++ )
      fout<<clasament[i]<<"\n";
    return 0;
}
