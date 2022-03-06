#include <fstream>
#include <cstring>
using namespace std;

ifstream cin ("strmatch.in");

ofstream cout ("strmatch.out");

string s, s1, s2;

int pi[4000005];

int sol[1005];

int main()

{

    int n, m, i, cnt = 0;

    cin >> s1;

    cin >> s2;

    s = s1 + '#' + s2;

    for (i = 1; i < s.size(); i++)

    {

        int now = pi[i - 1];

        while (now && s[i] != s[now])

            now = pi[now - 1];

        if (s[i] == s[now])

            now++;

        pi[i] = now;

        if (pi[i] == s1.size())

        {

            cnt++;

            if (cnt < 1001)

            sol[cnt] = i - 2 * s1.size();

        }

    }

    cout << cnt << '\n';

    for (i = 1; i <= min(cnt, 1000); i++)

        cout << sol[i] << " ";

    return 0;

}
