# include <cstdio>
# include <vector>
# include <queue>


using namespace std;



FILE *f = freopen("apm.in", "r", stdin);

FILE *g = freopen("apm.out", "w", stdout);



const int N_MAX = 200001;



struct vecin{

    int capat;

    int cost;



    vecin (int &a, int &b)

    {

        this -> capat= a;

        this -> cost= b;

    }

};



struct muchie{

    int capat1;

    int capat2;

    int cost;



    muchie(int &a, int &b, int &c)

    {

        this -> capat1 = a;

        this -> capat2= b;

        this -> cost= c;

    }



    const bool operator <(const muchie &other) const

    {

        return (this ->cost > other.cost);

    }

};



int n, m, sol;

int rez[N_MAX];

vector <vecin> G[N_MAX];

vector <vecin> solutie;

priority_queue <muchie> candidati;



int main()

{

    scanf("%d %d", &n, &m);



    for (int i=1; i<=m; i++)

    {

        int x, y, c;

        scanf("%d %d %d", &x, &y, &c);



        G[x].push_back(vecin(y,c));

        G[y].push_back(vecin(x,c));

    }

    rez[1] = true;

    sol = 1;



    for (vecin i : G[1])

        candidati.push(muchie (sol, i.capat, i.cost));



    sol = 0;



    while (!candidati.empty())

    {

        muchie v = candidati.top();

        candidati.pop();



        if (!rez[v.capat2])

        {

            int nod_nou = v.capat2;



            rez[nod_nou] = true;

            sol += v.cost;



            solutie.push_back(vecin(v.capat1, v.capat2));



            for (vecin i :G[nod_nou])

            {

                if (!rez[i.capat])

                {

                    candidati.push(muchie(nod_nou, i.capat, i.cost));

                }

            }

        }

    }



    printf("%d\n", sol);

    printf("%u\n", solutie.size());

    for (int i=0; i<solutie.size(); i++)

    {

        printf("%d %d\n", solutie[i].capat, solutie[i].cost);

    }

    return 0;

}
