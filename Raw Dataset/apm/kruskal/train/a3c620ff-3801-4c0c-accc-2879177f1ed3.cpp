#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int nmax = 200069;

int n , m ;

int par[nmax] , nr[nmax];

long long r;

int cont;

int x[nmax] , y[nmax];

struct muchie

{

    int x;

    int y;

    int c;

};



muchie v[nmax];







inline void readInput()

{

    f>>n>>m;

    for(int i=1 ; i <= m ; i++)

    {

        f>>v[i].x>>v[i].y>>v[i].c;

    }

}



bool comp(muchie a , muchie b)

{

    if(a.c < b.c)

    {

        return true;

    }

    else

    {

        if(a.c == b.c)

        {

            if(a.x < b.x) return true;

            else if( a.x == b.x)

            {

                if(a.y< b.y) return true;

            }

        }

    }

    return false;

}



void uneste(int x, int y)

{

    int x2=x;

    int y2=y;

    while(x2!=par[x2])

    {

        x2=par[x2];

    }

    while(y2!=par[y2])

    {

        y2=par[y2];

    }

    if(nr[x2]<nr[y2])

    {

        swap(x,y);

        swap(x2,y2);

    }

    if(x2!=y2)

    {

        nr[x2]+=nr[y2];

        par[y2]=x2;

    }

    while(x!=x2)

    {

        int aux=par[x];

        par[x]=x2;

        x=aux;

    }

    while(y!=x2)

    {

        int aux=par[y];

        par[y]=x2;

        y=aux;

    }

}



bool Parinte(int x, int y)

{

    int x2=x;

    int y2=y;

    while(x2!=par[x2])

    {

        x2=par[x2];

    }

    while(y2!=par[y2])

    {

        y2=par[y2];

    }



    while(x!=x2)

    {

        int aux=par[x];

        par[x]=x2;

        x=aux;

    }

    while(y!=y2)

    {

        int aux=par[y];

        par[y]=y2;

        y=aux;

    }

    if(par[x2]==par[y2])

    {

        return true;

    }

    return false;

}



inline void Solution()

{

    sort(v + 1 , v + m + 1 , comp);



    for(int i=1 ;i<=n;i++)

    {

        nr[i] = 1;

        par[i] = i;

    }

    for(int i = 1; i<= m && cont < n-1; i++)

    {

        if(Parinte(v[i].x , v[i].y) == false)

        {

            uneste(v[i].x , v[i].y);

            r += v[i].c;

            cont++;

            x[cont] =v[i].x;

            y[cont] = v[i].y;

        }

    }

}



inline void Afisare()

{

    g<<r<<"\n";

    g<<cont<<"\n";

    for(int i=1 ;i<=cont;i++) g<<y[i]<<" "<<x[i]<<"\n";

}



int main()

{

    readInput();

    Solution();

    Afisare();

    return 0;

}
