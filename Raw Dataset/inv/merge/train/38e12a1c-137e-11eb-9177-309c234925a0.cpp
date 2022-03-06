#include <iostream>
#include<fstream>


using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int nr=0, v[100001], nou[100001];

void interclasare(int left, int mid, int right)

{

    int i=left;

    int j=mid+1;

    int k=0;

    while(i<=mid && j<=right)

    {

        if(v[i]<=v[j])

            nou[k++]=v[i++];

        else

        {

            nr+=mid-i+1;

            nr=nr%9917;

            nou[k++]=v[j++];

        }

    }



    while(i<=mid)

        nou[k++]=v[i++];

    while(j<=right)

        nou[k++]=v[j++];

    for(k=left;k<=right;k++)

        v[k]=nou[k-left];

}



void mergesort(int left, int right)

{

    if(left<right)

    {

        int m=(left+right)/2;

        mergesort(left, m);

        mergesort(m+1, right);

        interclasare(left, m, right);

    }

}

int main()

{ int n;

f>>n;

for(int i=0;i<n;i++)

    f>>v[i];

mergesort(0,n-1);

g<<nr;

    return 0;

}
