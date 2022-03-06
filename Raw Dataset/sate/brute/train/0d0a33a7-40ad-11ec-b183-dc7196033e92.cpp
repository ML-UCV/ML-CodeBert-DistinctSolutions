#include <fstream>

using namespace std;

ifstream in("sate.in");

ofstream out("sate.out");

int N, M, x, y, s[30003], a[100030], b[100030], d[100030];

int main()

{

    in >> N >> M >> x >> y;

    s[x] = 1;

    for (int i = 1; i <= M; i++)

        in >> a[i] >> b[i] >> d[i];

    while (!s[y])

    {

        for (int i = 1; i <= M; i++)

        {

            if (s[a[i]] && !s[b[i]])
                s[b[i]] = s[a[i]] + d[i];

            else if (!s[a[i]] && s[b[i]])
                s[a[i]] = s[b[i]] - d[i];
        }
    }

    out << s[y] - 1 << "\n";

    return 0;
}
