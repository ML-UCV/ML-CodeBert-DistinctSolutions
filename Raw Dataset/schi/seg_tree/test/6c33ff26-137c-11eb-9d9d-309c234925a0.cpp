#include <fstream>
#include <iostream>
#include <array>

template<int len>
class AINT {
    std::array<int, (len << 2) + 1> t;

private:
    void _update(int p, int st, int dr, int poz) {
        if (st == dr) {
            t[p] = !t[p];
            return;
        }

        int m = (st + dr) / 2;
        if (poz <= m) {
            _update(2 * p, st, m, poz);
        } else {
            _update(2 * p + 1, m + 1, dr, poz);
        }
        t[p] = t[2 * p] + t[2 * p + 1];
    }

    int _query(int p, int st, int dr, int x) {
        if (st == dr) {
            return st;
        }

        int m = (st + dr) / 2;
        if (t[2 * p] >= x) {
            return _query(2 * p, st, m, x);
        } else {
            return _query(2 * p + 1, m + 1, dr, x - t[2 * p]);
        }
    }

public:
    inline void update(int n, int poz) {
        _update(1, 1, n, poz);
    }

    inline int query(int n, int x) {
        return _query(1, 1, n, x);
    }
};

AINT<30000> aint;
std::array<int, 30001> input;
std::array<int, 30001> result;

int main() {
    std::ifstream fin("schi.in");
    std::ofstream fout("schi.out");
    int n;

    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> input[i];
        aint.update(n, i);
    }

    for (int i = n; i >= 1; i--) {
        int poz = aint.query(n, input[i]);
        result[poz] = i;
        aint.update(n, poz);
    }

    for (int i = 1; i <= n; i++) {
        fout << result[i] << '\n';
    }
    return 0;
}
