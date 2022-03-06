#include <bits/stdc++.h>


using namespace std;
ifstream f("inv.in");
ofstream g("inv.out");
int n;
int v[100005];

int Merge(int v[], int l, int m, int r)
{
  int i, j, k, res;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for(i = 0;i < n1;++i)
    L[i] = v[l + i];
  for(int j = 0;j < n2;++j)
    R[j] = v[j + m + 1];
  i = j = res = 0;
  k = l;
  while(i < n1 && j < n2)
  {
    if(L[i] <= R[j])
      v[k++] = L[i++];
    else
    {
      v[k++] = R[j++];
      res += n1 - i;
      res %= 9917;
    }
  }
  while(i < n1)
    v[k++] = L[i++];
  while(j < n2)
    v[k++] = R[j++];
  return res;
}

int MergeSort(int v[], int l, int r)
{
  if(l < r)
  {
    int res = 0;
    int m = (l + r) >> 1;
    res = (res + MergeSort(v, l, m)) % 9917;
    res = (res + MergeSort(v, m + 1, r)) % 9917;
    res = (res + Merge(v, l, m, r)) % 9917;
    return res;
  }
  else
    return 0;
}

void Read()
{
  f>>n;
  for(int i = 0;i < n;++i)
    f>>v[i];
}

int main()
{
  Read();
  g<<MergeSort(v, 0, n - 1);
  return 0;
}
