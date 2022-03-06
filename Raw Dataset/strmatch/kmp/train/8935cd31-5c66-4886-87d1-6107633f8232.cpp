#include <fstream>
#include <cstring>
#include <queue>

using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");

string a, b;
int p[2000004], j, s;
queue<int> q;

void getP() {
    for (int i = 2; i < a.length(); i++) {
        while (j && a[j + 1] != a[i])
            j = p[j];
        if (a[j + 1] == a[i])
            j++;
        p[i] = j;
    }
}

int main() {
    f >> a >> b;
    a = "0" + a;
    b = "0" + b;

    getP();

    j = 0;
    for (int i = 1; i < b.length(); i++) {
        while (j && a[j + 1] != b[i])
            j = p[j];
        if (a[j + 1] == b[i])
            j++;
        if (j == a.length()-1) {
            q.push(i-a.length()+1);
            j = p[j];
        }
    }

    g << q.size() << '\n';
    s = min((int)q.size(), 1000);
    for (int i = 1; i <= s; i++) {
        g << q.front() << ' ';
        q.pop();
    }

    f.close();
    g.close();
    return 0;
}
