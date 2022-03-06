#include <iostream>
#include <fstream>
#include <vector>




using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int ans;

vector <int> sol;

string s1, s2, s;

int phi[2*2000000 +10];



int main()

{

    f >> s1 >> s2;

    s = s1 + '&' + s2;

    int n1 = s1.size(), n2 = s2.size(), n = s.size();

    int i = 1, j = 0;

    while(i < n)

        { if(s[i] == s[j]) phi[i] = j + 1, i++, j++;

            else

                { if(j > 0) j = phi[j-1];

                    else i++;

                }

        }

    for(int i=n1+1; i<n; i++)

        if(phi[i] == n1) ans++, sol.push_back({i-2*n1});

    g << ans << '\n';

    int m = min(1000, ans);

    for(int i=0; i<m; i++) g << sol[i] << ' ';

    g << '\n';

    return 0;

}
