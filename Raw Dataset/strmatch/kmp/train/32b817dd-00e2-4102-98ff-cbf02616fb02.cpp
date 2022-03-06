#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>




using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int n, phi[4000000 +10];

string s1, s2, s;

vector <int> sol;



int main()

{

    f >> s1 >> s2;

    s = s1 + '&' + s2;

    n = s.size();

    int i=1, j=0;

    while(i < n)

        { if(s[i] == s[j]) phi[i] = j+1, i++, j++;

            else

                { if(j > 0) j = phi[j-1];

                    else i++;

                }

        }

    for(int i=0; i<n; i++) if(phi[i] == s1.size()) sol.push_back(i-2*s1.size());

    int m = sol.size();

    m = min(m, 1000);

    g << sol.size() << '\n';

    for(int i=0; i<m; i++) g << sol[i] << ' ';

    g << '\n';

    return 0;

}
