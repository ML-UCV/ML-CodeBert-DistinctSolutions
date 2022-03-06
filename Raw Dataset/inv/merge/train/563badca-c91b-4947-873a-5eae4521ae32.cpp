#include<fstream>


using namespace std;



int n;

int x[100005];

int s[100007];

int d[100006];



int merge_bine(int st,int mid,int dr)

{

    int i,j;

    long long sol=0;

    int nrs=mid-st+1;

    int nrd=dr-mid;

    for(i=1;i<=nrs;i++) s[i]=x[st+i-1];

    for(i=1;i<=nrd;i++) d[i]=x[mid+i];

    s[nrs+1]=0x7fffffff;

    d[nrd+1]=0x7fffffff;

    i=1; j=1;

    for(int k=st;k<=dr;k++)

    {

        if(s[i]<=d[j]) x[k]=s[i++];

        else

        {

            x[k]=d[j++];

            if(i!=nrs+1)

            {

                sol+=nrs+1-i;

                if(sol>9917) sol-=9917;

            }

        }

    }

    return sol;

}



int inversions(int st,int dr)

{

    if(st==dr) return 0;

    int mid=st+(dr-st)/2;

    long long sol=0;

    sol+=inversions(st,mid);

    sol+=inversions(mid+1,dr);

    sol+=merge_bine(st,mid,dr);

    sol%=9917;

    return sol;

}



int main()

{

    ifstream t1("inv.in");

    ofstream t2("inv.out");

    t1>>n;

    for(int i=1;i<=n;i++) t1>>x[i];

    t2<<inversions(1,n);

    return 0;

}
