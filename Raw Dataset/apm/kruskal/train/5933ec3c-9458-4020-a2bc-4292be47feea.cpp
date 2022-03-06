#include <fstream>
#include <vector>
#include <queue>




std::ifstream in("apm" ".in");

std::ofstream out("apm" ".out");
const int

N = 100000,

M = 4*N;



struct Arc {int b, cost;};

struct Muchie {int a, b, cost;};

std::ostream& operator << (std::ostream& stream, Muchie& muchie)

{return stream << muchie.a+1 << ' ' << muchie.b+1 << '\n';}



int n;



namespace disjunct

{

    int set[N];



    void reset()

    {for (int i = 0; i < n; i++) set[i] = -1;}



    int rad(int x)

    {

        std::vector<int> drum;

        while (set[x] >= 0)

        {

            drum.push_back(x);

            x = set[x];

        }

        for (auto y: drum)

            set[y] = x;

        return x;

    }



    void uneste(int rad_a, int rad_b)

    {

        if (set[rad_a] > set[rad_b])

            std::swap(rad_a, rad_b);

        set[rad_a] += set[rad_b];

        set[rad_b] = rad_a;

    }

}



namespace apm

{

    Arc tata[N];

    int rank[N], suma;

    std::vector<Muchie> muchii;



    struct CompMuchie

    {inline bool operator () (Muchie& a, Muchie& b) {return a.cost > b.cost;}};



    void reset()

    {for (int i = 0; i < n; i++) {tata[i].b = -1; rank[i] = 0;}}



    void eval(std::vector<Arc>* vecini, int radacina)

    {

        std::priority_queue

        <Muchie, std::vector<Muchie>, CompMuchie> inventar;



        auto push_vecini = [vecini, &inventar](Muchie muchie)

        {for (auto arc: vecini[muchie.b]) if (arc.b != muchie.a) inventar.push({muchie.b, arc.b, arc.cost});};



        push_vecini({-1, radacina, -1});





        while (!inventar.empty())

        {

            Muchie muchie = inventar.top();

            inventar.pop();



            int

            rad_a = disjunct::rad(muchie.a),

            rad_b = disjunct::rad(muchie.b);



            if (rad_a != rad_b)

            {

                disjunct::uneste(rad_a, rad_b);

                push_vecini(muchie);

                muchii.push_back(muchie);

                suma += muchie.cost;

                tata[muchie.b] = {muchie.a, muchie.cost};

                rank[muchie.b] = rank[muchie.a] + 1;

            }

        }

    }

}
std::vector<Arc> vecini[N];



int main()

{

    int m;

    in >> n >> m;



    while (m--)

    {

        int a, b, cost;

        in >> a >> b >> cost;

        a--, b--;

        vecini[a].push_back({b, cost});

        vecini[b].push_back({a, cost});

    }



    disjunct::reset();

    apm::reset();



    apm::eval(vecini, 0);



    out << apm::suma << '\n' << n - 1 << '\n';

    for (auto muchie: apm::muchii)

        out << muchie;

}
