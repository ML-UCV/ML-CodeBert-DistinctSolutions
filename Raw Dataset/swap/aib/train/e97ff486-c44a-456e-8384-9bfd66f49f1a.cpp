#include<fstream>
#include<string>
#include<vector>
using namespace std;



string s,t;

vector<int> v[30];

int a[50001],aib[50001],i,n;

long long sum;



void update(int k,int val)

{

 int i;

 for (i=k;i<=n;i=(i | (i-1))+1)

  aib[i]+=val;

}



int query(int k)

{

 int i,s=0;

 for (i=k;i>0;i=i & (i-1))

  s+=aib[i];

 return s;

}



int main()

{

 ifstream f("swap.in");

 ofstream g("swap.out");

 f >> s >> t;

 n=s.length();

 for (i=1;i<=26;i++)

  v[i].push_back(0);

 for (i=0;i<n;i++)

  v[t[i]-'a'+1].push_back(i+1);

 for (i=0;i<n;i++)

  if (v[s[i]-'a'+1][0]<v[s[i]-'a'+1].size()-1)

   a[i+1]=v[s[i]-'a'+1][++v[s[i]-'a'+1][0]];

  else

  {

   g << -1;

   return 0;

  }

 for (i=n;i>=1;i--)

 {

  sum+=query(a[i]);

  update(a[i],1);

 }

 g << sum;

 return 0;

}
