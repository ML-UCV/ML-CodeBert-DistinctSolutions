#include <fstream>
#include <vector>
#include <cstring>
using namespace std;



char s[50005], S[50005];

int lgt, sol, aib[50005], P[50005], poz[26];

vector<int> v[26];



inline int abs(int a)

{

    if(a < 0) return -a;

    return a;

}



int query(int poz)

{

    int sol = 0;

    for(int x = poz; x; x -= (x & (-x)))

        sol += aib[x];

    return sol;

}



void update(int poz)

{

    for(int x = poz; x <= lgt; x += (x & (-x)))

        aib[x]++;

}



int main()

{

    ifstream in("swap.in"); in.getline(s + 1, 50005); in.getline(S + 1, 50005); in.close();

    lgt = strlen(s + 1);

    for(int i = 1; i <= lgt; i++) v[s[i] - 'a'].push_back(i);

    ofstream out("swap.out");

    for(int i = 1; i <= lgt; i++)

    {

        if(v[S[i] - 'a'].size() != poz[S[i] - 'a'])

            P[v[S[i] - 'a'][poz[S[i] - 'a']++]] = i;

        else

        {

            out<<"-1";

            out.close();

            return 0;

        }

    }

    for(int i = 1; i <= lgt; i++)

    {

        sol += query(lgt) - query(P[i]);

        update(P[i]);

    }

    out<<sol; out.close();

    return 0;

}
