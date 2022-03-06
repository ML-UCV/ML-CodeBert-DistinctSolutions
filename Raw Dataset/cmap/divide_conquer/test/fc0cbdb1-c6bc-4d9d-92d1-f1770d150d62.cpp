#include <bits/stdc++.h>




using namespace std;

fstream f1("cmap.in", ios::in);

fstream f2("cmap.out", ios::out);

int n;

long long rez=4000000000000000000;

struct punct

{

    long long x, y;

}p[100005], py[100005], aux[100005];

bool cmp1(punct a, punct b)

{

    return a.x< b.x;

}

bool cmp2(punct a, punct b)

{

    return a.y> b.y;

}

long long dist(punct a, punct b)

{

    return (a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y);

}

void citire()

{

    f1>>n;

    for(int i=1; i<=n; i++)

        f1>>p[i].x>>p[i].y;

    sort(p+1, p+n+1, cmp1);

}

void brut(int st, int dr)

{

    long long val;

    if(dr-st+1==1) return;

    for(int i=st; i<=dr; i++)

        for(int j=i+1; j<=dr; j++)

        {

            val=dist(p[i], p[j]);

            if(rez> val)

               rez=val;

        }

     for(int i=st; i<=dr; i++)

         py[i]=p[i];

     sort(py+st, py+dr+1, cmp2);

}

void interclasare(int st, int mijl, int dr)

{

    int i=st, j=mijl+1, k=0;

    while((i<=mijl)&&(j<=dr))

    {

        if(py[i].y>py[j].y) {k++; aux[k]=py[i]; i++;}

        else {k++; aux[k]=py[j]; j++;}

    }

    while(i<=mijl)

    {

        k++; aux[k]=py[i]; i++;

    }

    while(j<=dr)

    {

        k++; aux[k]=py[j]; j++;

    }

    for(j=1, i=st; j<=k; j++,i++)

        py[i]=aux[j];

}

void mij(int st, int mijl, int dr)

{

    long long val;

    int k=0;

    for(int i=st; i<=dr; i++)

        if(abs(py[i].x-py[mijl].x)<=rez)

    {

        k++; aux[k]=py[i];

    }

    for(int i=st; i<=dr; i++)

        for(int j=i+1; (j<=dr)&&(j-i)<=8; j++)

    {

        val=dist(py[i], py[j]);

        if(val< rez) rez=val;

    }

}

void solutie(int st, int dr)

{

    if(dr-st+1<=3) brut(st, dr);

    else

    {

        int mijl=(st+dr)/2;

        solutie(st, mijl);

        solutie(mijl+1, dr);

        interclasare(st, mijl, dr);

        mij(st, mijl, dr);

    }

}

int main()

{

    citire();

    solutie(1, n);

    f2<<fixed<<setprecision(10)<<sqrt(rez);

    return 0;

}
