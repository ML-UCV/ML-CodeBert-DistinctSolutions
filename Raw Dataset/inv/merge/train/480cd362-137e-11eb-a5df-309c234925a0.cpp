#include <bits/stdc++.h>




using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

vector<int>v;

int n;

long long ans;

void Citire()

{

    int i,x;

    fin>>n;

    v.push_back(0);

    for(i=1;i<=n;++i)

    {

        fin>>x;

        v.push_back(x);

    }

}

void Divide(int left,int right)

{

    if(left<right)

    {

        int mid=(left+right)/2;

        Divide(left,mid);

        Divide(mid+1,right);

        vector <int> a;

        int pos1=left,pos2=mid+1;

        while(pos1<=mid&&pos2<=right)

        {

            if(v[pos1]<=v[pos2])

            {

                ans=(ans+pos2-mid-1)%9917;

                a.push_back(v[pos1]);

                pos1++;

            }

            else {

                a.push_back(v[pos2]);

                pos2++;

            }

        }

        while(pos1<=mid)

        {

             ans=(ans+pos2-mid-1)%9917;

            a.push_back(v[pos1++]);

        }

        while(pos2<=right)a.push_back(v[pos2++]);

        for(int i=left;i<=right;++i)v[i]=a[i-left];

    }

}

int main()

{

    Citire();

    Divide(1,n);

    fout<<ans;

    return 0;

}
