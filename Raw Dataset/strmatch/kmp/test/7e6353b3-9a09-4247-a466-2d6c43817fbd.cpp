#include <iostream>
#include <fstream>
#include <vector>




using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int phi[2*2000000 +10], ans;

vector <int> sol;

string s1, s2, s;



int main()

{

    f >> s1 >> s2;

    s = s1 + '%' + s2;

    int n1 = s1.size(), n = s.size(), j = 0, i = 1;

    while(i < n)

        { if(s[j] == s[i]) phi[i] = j + 1, i++, j++;

            else

                { if(j > 0) j = phi[j-1];

                    else i++;

                }

        }

    for(int i=0; i<n; i++)

        if(phi[i] == n1)

            { ans++;

                if(ans <= 1000) sol.push_back(i - 2 * n1);

            }

    g << ans << '\n';

    for(int i=0; i<sol.size(); i++) g << sol[i] << ' ';

    g << '\n';

    return 0;

}
