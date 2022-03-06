#include <fstream>
#include <vector>
using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

vector<int> sol;

vector<int> z(string s) {

int n = s.size();

vector<int> z(n);

int x = 0, y = 0;

for (int i = 1; i < n; i++) {

z[i] = max(0,min(z[i-x],y-i+1));

while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {

x = i; y = i+z[i]; z[i]++;

}

}

return z;

}

int main()

{

    string a,b;

    cin>>a>>b;

    b=a+'#'+b;

    vector<int> v=z(b);

    int rasp=0;

    for(int i=0;i<v.size();++i)

    if(v[i]==a.size())

    {

        rasp++;

        if(rasp<=1000)

            sol.push_back(i-a.size()-1);

    }

    cout<<rasp<<'\n';

    for(int i=0;i<sol.size();++i)

        cout<<sol[i]<<' ';

    return 0;

}
