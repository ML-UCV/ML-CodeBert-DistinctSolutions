#include <fstream>
#include <algorithm>




using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");





struct muchie{

    int x, y, c;



     bool operator<(const muchie &other) const {

        if(c != other.c)

            return c < other.c;

        if(y != other.y)

            return y < other.y;

        return x < other.x;

    }





};





struct graph{

    int t;

    int d;

}gr[200005];
int n, m, cmin;

int tati[200005];

muchie ms[400005], sol[200005];





int rad_act;

void rad(int x)

{

    if(gr[x].t == x)

    {

        rad_act = x;

        return;

    }

    rad(gr[x].t);

    gr[x].t = rad_act;

}
bool findSameR(int x, int y)

{

    rad(x);

    int radOfX = rad_act;

    rad(y);

    int radOfY = rad_act;

    if(radOfX == radOfY)

        return 0;

    else return 1;

}
void read()

{

    f>>n>>m;

    for(int i=0; i<m; ++i)

        f>>ms[i].x>>ms[i].y>>ms[i].c;

    sort(ms, ms+m);

}







void initTati()

{

    for(int i=1; i<=n; ++i)

        gr[i].t = i;

}



void unionOf(int x, int y)

{

    rad(x);

    int aux = rad_act;

    rad(y);



    if(gr[aux].d == gr[rad_act].d)

    {

        gr[aux].t = rad_act;

        gr[aux].d++;

    }

    else if(gr[aux].d < gr[rad_act].d)

        gr[rad_act].t = aux;

    else{

        gr[aux].t = rad_act;

    }

}



void solve()

{

    initTati();

    int chosen = 0;

    for(int i=0; i<m && chosen < n-1; ++i)

        if(findSameR(ms[i].x, ms[i].y))

        {

            cmin += ms[i].c;

            sol[chosen++] = ms[i];

            unionOf(ms[i].x, ms[i].y);

        }

}



void write()

{

    g<<cmin<<'\n'<<n-1<<'\n';

    for(int i=0; i<n-1; ++i)

        g<<sol[i].x<<" "<<sol[i].y<<'\n';;

}
int main()

{

    read();

    solve();

    write();

    return 0;

}
