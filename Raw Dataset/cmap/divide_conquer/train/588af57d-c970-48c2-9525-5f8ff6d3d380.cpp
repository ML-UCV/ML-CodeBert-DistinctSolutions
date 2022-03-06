#include <stdio.h>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cmath>


using namespace std;



FILE *fin = fopen("cmap.in", "r");

FILE *fout = fopen("cmap.out", "w");



pair <int,int> v[100005],aux[100005];



int n,i;



double dist(pair <int,int> x, pair <int,int> y)

{

    return 1.0*sqrt(1.0*1LL*(x.first-y.first)*(x.first-y.first) + 1LL*(x.second-y.second)*(x.second-y.second));

}



bool cmp(pair <int,int> x, pair <int,int> y)

{

    return x.second <= y.second;

}



double solve(int left, int right)

{

    int i,j,k,mid,t,xmij;

    double ans = 1e12,dst,ddr,dmin;



    if(right-left+1 <= 3)

    {

        sort(v+left, v+right+1, cmp);



        for(i=left; i<=right-1; ++i)

            for(j=i+1; j<=right; ++j)

                ans = min(ans, dist(v[i],v[j]));



        return ans;

    }

    else

    {

        mid = (left+right) /2;

        xmij = v[mid].first;

        dst = solve(left, mid);

        ddr = solve(mid+1, right);



        dmin = min(dst,ddr);



        i = left;

        j = mid+1;

        k = 0;

        while(i<=mid and j<=right)

            if(v[i].second < v[j].second)

                aux[++k] = v[i++];

            else

                aux[++k] = v[j++];



        while(i<=mid)

            aux[++k] = v[i++];

        while(j<=right)

            aux[++k] = v[j++];



        t = 0;

        for(i=1,j=left; i<=k; ++i,++j)

        {

            v[j] = aux[i];

            if(1.0*fabs(xmij - aux[i].first) <= dmin)

                aux[++t] = aux[i];

        }



        ans = dmin;

        for(i=1; i<=t; ++i)

            for(j=i+1; j<=t && j<=i+7; ++j)

                ans = min(ans, dist(aux[i],aux[j]));

        return ans;

    }

}



int main()

{

    fscanf(fin, "%d", &n);

    for(i=1; i<=n; ++i)

        fscanf(fin, "%d%d", &v[i].first,&v[i].second);



    sort(v+1, v+n+1);



    fprintf(fout, "%.8lf", solve(1,n));



    fclose(fin);

    fclose(fout);

    return 0;

}
