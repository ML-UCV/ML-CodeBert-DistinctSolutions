#include <vector>
#include <fstream>


using std::vector;

std::ifstream fin("schi.in");

std::ofstream fout("schi.out");



class FenTree {

  private:

    int n;

    vector<int> bit;



    static inline int lsb(int x) {

        return x & (-x);

    }



  public:

    FenTree(int n) {

        this->n = n;

        bit.resize(n + 1);

    }



    void update(int pos, int val) {

        for (int i = pos; i <= n; i += lsb(i))

            bit[i] += val;

    }



    int query(int pos) {

        int sum = 0;

        for (int i = pos; i >= 1; i -= lsb(i))

            sum += bit[i];

        return sum;

    }



    int query(int left, int right) {

        return query(right) - query(left - 1);

    }



    int search(int val) {

        int md, lo = 0, hi = n + 1;

        while (hi - lo > 1) {

            md = (lo + hi) >> 1;

            if (query(md) < val)

                lo = md;

            else

                hi = md;

        }

        return query(hi) == val ? hi : -1;

    }

};



int main() {

    int n; fin >> n;

    vector<int> pos(n + 1);



    for (int i = 1; i <= n; i++)

        fin >> pos[i];



    FenTree bit(n);

    for (int i = 1; i <= n; i++)

        bit.update(i, 1);



    vector<int> sol(n + 1);

    for (int i = n; i >= 1; i--) {

        int ind = bit.search(pos[i]);

        bit.update(ind, -1);

        sol[ind] = i;

    }



    for (int i = 1; i <= n; i++)

        fout << sol[i] << '\n';



    fout.close();

    return 0;

}
