#include <fstream>

#include <vector>



using namespace std;



ifstream fin("sate.in");

ofstream fout("sate.out");



int n,m,i,j,x,y,x1,y1,cost,sol,s,ok,v[30005],d[30005],c[30005];

vector< pair<int, int> > L[30005];

char S[1010];



int main()

{

    fin >> n >> m >> x >> y;

    for (i=1; i<=m; i++)

    {

        //fin >> x1 >> y1 >> cost;

        fin.get(); fin.get(S, 1005);

        x1 = y1 = cost = 0; j = 0;

        while (S[j] >= '0' && S[j] <= '9')

        {

            x1 = x1*10+(S[j]-'0');

            j++;

        }

        j++;

        while (S[j] >= '0' && S[j] <= '9')

        {

            y1 = y1*10+(S[j]-'0');

            j++;

        }

        j++;

        while (S[j] >= '0' && S[j] <= '9')

        {

            cost = cost*10+(S[j]-'0');

            j++;

        }

        L[x1].push_back(make_pair(y1, cost));

        L[y1].push_back(make_pair(x1, -cost));

    }

    int p = 1; int u = 1; c[1] = x; v[x] = 1;

    while (p <= u)

    {

        int nod = c[p];

        if (v[y])

            break;

        for (i=0; i<L[nod].size(); i++)

        {

            int vecin = L[nod][i].first; int cost = L[nod][i].second;

            if (!v[vecin])

            {

                v[vecin] = 1; c[++u] = vecin;

                d[vecin] = d[nod]+cost;

            }

        }

        p++;

    }

    fout << d[y];

    return 0;

}
