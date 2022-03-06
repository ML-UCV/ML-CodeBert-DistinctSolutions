#include <cstdio>
#include <algorithm>
#include <cmath>




using namespace std;

struct punct{

    long long x;

    long long y;

};

punct v[100005],w[100005],t[100005];

int n;

long long modul (long long x){

    if (x<0)

        return -x;

    return x;

}

int cmp (punct a,punct b){

    if (a.x!=b.x)

        return a.x<b.x;

    return a.y<b.y;

}

long long calcul (punct i,punct j){

    return (i.x-j.x)*(i.x-j.x) + (i.y-j.y)* (i.y-j.y);

}

void interclas (int st,int mid,int dr){

    int i,j,poz;

    i=st;

    j=mid+1;

    poz=st-1;

    while (i<=mid && j<=dr){

        if (v[i].y<v[j].y || (v[i].y==v[j].y && v[i].x<v[j].x)){

            t[++poz]=v[i];

            i++;

        }

        else {

            t[++poz]=v[j];

            j++;

        }

    }

    while (i<=mid){

        t[++poz]=v[i];

        i++;

    }

    while (j<=dr){

        t[++poz]=v[j];

        j++;

    }

    for (i=st;i<=dr;i++)

        v[i]=t[i];

}

long long combin (int st,int dr,long long sol){

    int mid,elem,i,j;

    mid=(st+dr)/2;

    interclas (st,mid,dr);

    elem=0;

    for (i=st;i<=dr;i++){

        if (modul(v[mid].x-v[i].x)<=sol)

            w[++elem]=v[i];

    }

    for (i=1;i<elem;i++){

        for (j=1;j<=7 && i+j<=elem;j++)

            sol=min(sol,calcul(w[i],w[i+j]));

    }

    return sol;

}

long long rec (int st,int dr){

    long long sol;

    int i,j,mid;







    if (dr-st+1<=3){

        sol=calcul(v[st],v[st+1]);

        for (i=st;i<dr;i++)

            for (j=i+1;j<=dr;j++)

                sol=min(sol,calcul(v[i],v[j]));

        interclas (st,(st+dr)/2,dr);

    }

    else {

        mid=(st+dr)/2;

        sol=rec (st,mid);

        sol=min(sol,rec (mid+1,dr));

        sol=min(sol,combin (st,dr,sol));

    }



    return sol;

}

int main()

{

    FILE *fin=fopen ("cmap.in","r");

    FILE *fout=fopen ("cmap.out","w");

    int i;

    fscanf (fin,"%d",&n);

    for (i=1;i<=n;i++)

        fscanf (fin,"%lld%lld",&v[i].x,&v[i].y);

    sort (v+1,v+n+1,cmp);

    fprintf (fout,"%.6lf",(double)sqrt(rec (1,n)));

    return 0;

}
