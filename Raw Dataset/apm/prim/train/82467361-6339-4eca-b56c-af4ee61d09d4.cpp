#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>






using namespace std;



FILE *fin = fopen("apm.in", "r");

FILE *fout = fopen("apm.out", "w");



typedef pair <int, int> pi;



priority_queue < pi, vector <pi>, greater <pi> > pq;

vector <pi> graf[200005];



int n,m,x,y,c,cost[200005],tata[200005],nod,nod2,costmuch,ans,i;

bool inAPM[200005];



int main()

{

    fscanf(fin, "%d%d", &n,&m);

    for(i=1; i<=m; ++i)

    {

        fscanf(fin, "%d%d%d", &x,&y,&c);

        graf[x].push_back(make_pair(y, c));

        graf[y].push_back(make_pair(x, c));

    }





    for(i=1; i<=n; ++i)

        cost[i] = 1e9;



    pq.push(make_pair(0, 1));

    while(!pq.empty())

    {

        nod = pq.top().second;

        pq.pop();

        inAPM[nod] = true;



        for(i=0; i<graf[nod].size(); ++i)

        {

            nod2 = graf[nod][i].first;

            costmuch = graf[nod][i].second;



            if(!inAPM[nod2] and costmuch < cost[nod2])

            {

                cost[nod2] = costmuch;

                pq.push(make_pair(cost[nod2], nod2));

                tata[nod2] = nod;

            }

        }

    }



    for(i=1; i<=n; ++i)

        if(cost[i] < 1e9)

            ans += cost[i];



    fprintf(fout, "%d\n%d\n", ans, n-1);



    for(i=1; i<=n; ++i)

        if(tata[i])

            fprintf(fout, "%d %d\n", i,tata[i]);





    fclose(fin);

    fclose(fout);

    return 0;

}
