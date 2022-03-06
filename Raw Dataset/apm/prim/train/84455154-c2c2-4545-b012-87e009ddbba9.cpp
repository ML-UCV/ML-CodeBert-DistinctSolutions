#include <fstream>
#include <vector>
using namespace std;



ifstream cin("apm.in");

ofstream cout("apm.out");



const int DIM = 200001, INF = 10000;

vector<int> a[DIM], c[DIM];

struct afis

{



    int nx, ny;



} af[DIM];

int h[DIM], d[DIM], poz[DIM], pred[DIM];

bool viz[DIM];

int nh, n, kt = 1;

long long S;



void urca(int p);

void sterge(int p);

void coboara(int p);

void adauga(int val);

void prim(int x0);



int main()

{



    int m;

    cin >> n >> m;



    for(int i = 1; i <= m; ++i)

    {

        int x, y, cost;

        cin >> x >> y >> cost;



        a[x].push_back(y);

        a[y].push_back(x);

        c[x].push_back(cost);

        c[y].push_back(cost);

    }



    prim(1);

    cout << S << '\n' << n - 1 << '\n';



    for(int i = 1; i < n; ++i)

        cout << af[i].nx << ' ' << af[i].ny << '\n';

    return 0;

}



void prim(int x0)

{

    int x;

    for(int i = 1; i <= n; ++i)

    {

        d[i] = INF;

        h[i] = i;

        poz[i] = i;

    }



    d[x0] = 0;

    urca(poz[x0]);

    nh = n;



    while(nh > 0)

    {

        x = h[1];



        viz[x] = true;

        if(nh < n)

        {

            af[kt].nx = x;

            af[kt].ny = pred[x];



            S += d[x];

            kt++;

        }



        sterge(1);

        for(int i = 0; i < a[x].size(); ++i)

        {

            int y = a[x][i];

            if(viz[y]) continue;



            int cost = c[x][i];

            if(pred[x] != y && cost < d[y])

            {

                d[y] = cost;

                pred[y] = x;

                urca(poz[y]);

            }

        }

    }

}



void urca(int p)

{

    while(p > 1 && d[h[p]] < d[h[p / 2]])

    {

        swap(h[p], h[p / 2]);

        poz[h[p]] = p;

        poz[h[p / 2]] = p / 2;

        p /= 2;

    }

}



void coboara(int p)

{

    int fs = p * 2, fd = p * 2 + 1, bun = p;

    if(fs <= nh && d[h[fs]] < d[h[bun]])

    {

        bun = fs;

    }



    if(fd <= nh && d[h[fd]] < d[h[bun]])

    {

        bun = fd;

    }

    if(bun != p)

    {

        swap(h[bun], h[p]);

        poz[h[p]] = p;

        poz[h[bun]] = bun;

        coboara(bun);

    }

}



void adauga(int val)

{

    h[++nh] = val;

    urca(nh);

}



void sterge(int p)

{

    swap(h[p], h[nh--]);

    poz[h[p]] = p;

    poz[h[nh + 1]] = nh + 1;

    urca(p);

    coboara(p);

}
