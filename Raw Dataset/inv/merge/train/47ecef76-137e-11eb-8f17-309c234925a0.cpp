#include <fstream>


using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int n,a[100001],b[100001];

int inv=0;

void Divide(int left, int right)

{

    if(left==right) return;



 int mid=(left+right)/2;

 Divide(left,mid);

 Divide(mid+1,right);



 int x=left,y=mid+1,dim=left-1;

 while(x<=mid && y<=right)

  {

    if(a[x]<=a[y]) {dim++;b[dim]=a[x];x++;}

    else {dim++;b[dim]=a[y];inv=(inv+(mid-x+1)) % 9917;y++;}

  }

 while(y<=right) {dim++;b[dim]=a[y];y++;}

 while(x<=mid) {dim++;b[dim]=a[x];x++;}



  for(int i=left;i<=right;i++)

   a[i]=b[i];

}

int main()

{

  fin>>n;

  for(int i=1; i<=n; i++)

    fin>>a[i];



    Divide(1,n);

fout<<inv;

    return 0;

}
