    #include <fstream>
    #include <iostream>
#include <utility>
#include <vector>
    std::ifstream in("apm" ".in");

    std::ofstream out("apm" ".out");
const int

N = 100000,

M = 400000,

C_MIN = -1000, C_MAX = 1000;



int n, m;



struct Muchie

{

    std::pair<int, int> incidente;

    int cost;



    inline bool operator <= (Muchie& alta)

    {return cost <= alta.cost;}



    inline bool operator < (int& alt_cost)

    {return cost < alt_cost;}

}

*muchii;







int pivot(int start, int end, Muchie& val)

{

    int piv = start;

    for (; start < end; start++)

        if (muchii[start] <= val)

            std::swap(muchii[piv++], muchii[start]);

    return piv;

}



void sorteaza(int start, int end)

{

    if (start == end)

        return;



    int piv = pivot(start, end, muchii[end - 1]);



    sorteaza(start, piv - 1);

    sorteaza(piv, end);

}







namespace arbore_partial

{

    int

    *set,

    nr_muchii,

    cost;



    Muchie* muchii;



    int radacina(int rad)

    {

        std::vector<int> drum;

        while (set[rad])

        {

            drum.push_back(rad);

            rad = set[rad] - 1;

        }

        for (int varf: drum)

        {

            set[varf] = rad + 1;

        }

        return rad;

    }



    void gestioneaza(Muchie& muchie)

    {

        int

        &a = muchie.incidente.first,

        &b = muchie.incidente.second,



        rad_a = radacina(a),

        rad_b = radacina(b);



        if (rad_a != rad_b)

        {

            set[rad_a] = rad_b + 1;

            muchii[nr_muchii++] = muchie;

            cost += muchie.cost;

        }

    }

}



using arbore_partial::gestioneaza;

using arbore_partial::radacina;







int main()

{

    in >> n >> m;

    muchii = new Muchie[m];



    for (int i = 0; i < m; i++)

    {

        int a, b, cost;

        in >> a >> b >> cost;

        a--, b--;

        muchii[i] = {{a, b}, cost};

    }



    sorteaza(0, m);

    arbore_partial::set = new int[n]();

    arbore_partial::muchii = new Muchie[n - 1];



    for (int i = 0; i < m; i++)

        gestioneaza(muchii[i]);



    delete[] muchii;

    delete[] arbore_partial::set;



    out

    << arbore_partial::cost << '\n'

    << n - 1 << '\n';



    for (int i = 0; i < n - 1; i++)

    {

        auto& incidente = arbore_partial::muchii[i].incidente;



        int

        &a = incidente.first,

        &b = incidente.second;



        out << a + 1 << ' ' << b + 1 << '\n';

    }



    delete[] arbore_partial::muchii;

}
