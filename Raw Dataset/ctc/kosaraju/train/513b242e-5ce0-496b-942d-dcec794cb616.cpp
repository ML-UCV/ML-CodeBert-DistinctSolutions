#include <fstream>


const int NMAX = 100000;



struct nod {

    int x;

    nod* next;

};



nod* G[NMAX + 1],

   * GT[NMAX + 1],

   * CTC[NMAX + 1];



int N, M, nrc, nr, post[NMAX + 1];

bool viz[NMAX + 1];



std::ifstream f("ctc.in");

std::ofstream g("ctc.out");



void add(nod*& cap_lst, int nod_add) {

    nod* p;

    p = new nod;

    p->x = nod_add;

    p->next = cap_lst;

    cap_lst = p;

}



void citireGraf() {

    f >> N >> M;

    while (M--) {

        int x, y;

        f >> x >> y;

        add(G[x], y);

        add(GT[y], x);

    }

}



void DFS(int vf){

    viz[vf] = 1;

    for (nod* p = G[vf]; p != NULL; p = p->next)

        if (!viz[p->x])

            DFS(p->x);

    post[++nr] = vf;

}



void DFSt(int vf) {

    viz[vf] = 0;

    add(CTC[nrc], vf);

    for (nod* p = GT[vf]; p != NULL; p = p->next)

        if (viz[p->x])

            DFSt(p->x);

}





void componentectc()

{

    int i;

    for (int i = 1; i <= N; i++)

        if (viz[i] == 0)

            DFS(i);



    for(i=N;i>=1;i--)

        if (viz[post[i]] == 1) {

            nrc++;

            DFSt(post[i]);

        }

}



void afis() {

    g << nrc << '\n';

    for (int i = 1; i <= nrc; i++) {

        for (nod* p = CTC[i]; p != NULL; p = p->next)

            g << p->x << ' ';

        g << '\n';

    }

}



int main()

{

    citireGraf();

    componentectc();

    afis();

    return 0;

}
