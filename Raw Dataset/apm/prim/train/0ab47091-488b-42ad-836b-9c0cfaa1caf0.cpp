#include <fstream>
#include <vector>




std::ifstream in("apm" ".in");

std::ofstream out("apm" ".out");
const int

N = 200000,

M = 2*N,

C = 1000;



struct Arc {int b, cost;};

struct Muchie {int a, b, cost;};

inline bool operator < (Arc& a, Arc& b) {return a.cost < b.cost;}

inline bool operator < (Muchie& a, Muchie& b) {return a.cost < b.cost;}

inline std::istream& operator >> (std::istream& in, Muchie& m) {in >> m.a >> m.b >> m.cost; m.a--, m.b--; return in;}

inline std::ostream& operator << (std::ostream& out, Muchie& m) {return out << m.a+1 << ' ' << m.b+1 << '\n';}



namespace dj

{

    int set[N];



    void reset(int n)

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



    void uneste(int ra, int rb)

    {

        if (set[ra] > set[rb])

            std::swap(ra, rb);

        set[ra] += set[rb];

        set[rb] = ra;

    }

}



template class std::vector<int>;

template class std::vector<Muchie>;

template <typename Type>

struct heap

{

    std::vector<Type> vector;



    inline Type top()

    {return vector.front();}



    inline int _fiu0(int idx1) {return idx1 << 1;}

    inline int _fiu1(int idx1) {return (idx1 << 1)+1;}

    inline int _tata(int idx1) {return idx1 >> 1;}



    inline int fiu0(int idx) {return _fiu0(idx+1)-1;}

    inline int fiu1(int idx) {return _fiu1(idx+1)-1;}

    inline int tata(int idx) {return idx? _tata(idx+1)-1: 0;}



    void sink()

    {

        int i = 0, fiu;

        while (fiu0(i) < vector.size())

        {

            if (fiu1(i) >= vector.size() || vector[fiu0(i)] < vector[fiu1(i)])

                fiu = fiu0(i);

            else

                fiu = fiu1(i);

            if (vector[fiu] < vector[i])

            {

                std::swap(vector[fiu], vector[i]);

                i = fiu;

            }

            else

                break;

        }



    }



    void rise()

    {

        int i = vector.size() - 1;

        while (vector[i] < vector[tata(i)])

        {

            std::swap(vector[i], vector[tata(i)]);

            i = tata(i);

        }

    }



    void pop()

    {

        std::swap(vector.front(), vector.back());

        vector.pop_back();

        sink();

    }



    void push(Type val)

    {

        vector.push_back(val);

        rise();

    }

};



namespace apm

{

    Arc tata[N];

    int rank[N], cost;

    std::vector<Muchie> muchii;



    void prim(std::vector<Arc>* vecini, int radacina)

    {

        heap<Muchie> inventar;

        auto adauga_vecini = [&inventar, vecini](int a)

        {

            for (auto arc: vecini[a])

                if (arc.b != a)

                    inventar.push({a, arc.b, arc.cost});

        };

        adauga_vecini(radacina);

        while (inventar.vector.size())

        {

            Muchie muchie = inventar.top();

            inventar.pop();

            int ra = dj::rad(radacina), rb = dj::rad(muchie.b);

            if (ra != rb)

            {

                dj::uneste(ra, rb);

                muchii.push_back(muchie);

                cost += muchie.cost;

                tata[muchie.b] = {muchie.a, muchie.cost};

                rank[muchie.b] = rank[muchie.a] + 1;

                adauga_vecini(muchie.b);

            }

        }

    }



    void kruskal(std::vector<Muchie>& toate)

    {

        heap<Muchie> inventar;

        for (auto muchie: toate)

            inventar.push(muchie);

        while (inventar.vector.size())

        {

            Muchie muchie = inventar.top();

            inventar.pop();

            int ra = dj::rad(muchie.a), rb = dj::rad(muchie.b);

            if (ra != rb)

            {

                dj::uneste(ra, rb);

                muchii.push_back(muchie);

                cost += muchie.cost;

            }

        }

    }

}







std::vector<Muchie> muchii;

int main()

{

    int n, m;

    in >> n >> m;

    muchii.resize(m);

    for (auto& muchie: muchii)

        in >> muchie;

    dj::reset(n);

    apm::kruskal(muchii);

    out << apm::cost << '\n' << n - 1 << '\n';

    for (Muchie muchie: apm::muchii)

        out << muchie;

}
