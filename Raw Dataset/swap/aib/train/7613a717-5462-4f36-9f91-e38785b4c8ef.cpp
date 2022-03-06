#include <fstream>
#include <queue>
#include <cstring>


using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



int i,sol,n,A[50001];

char s[50001],t[50001];

queue<int> L[30];



void update(int p)

{

    for (int i=p; i<=n; i+=(i&-i))

        A[i]++;

}



int query(int p)

{

    int sol = 0;

    for (int i=p; i>=1; i-=(i&-i))

        sol += A[i];

    return sol;

}



int main()

{

    fin >> s+1 >> t+1;

    n = strlen(t+1);

    for (i=1; t[i]!=0; i++)

        L[t[i]-'a'+1].push(i);

    for (i=1; s[i]!=0; i++)

    {

        if (L[s[i]-'a'+1].size() == 0)

        {

            fout << -1;

            return 0;

        }

        int x = L[s[i]-'a'+1].front();

        sol += x-1-query(x);

        update(x);

        L[s[i]-'a'+1].pop();

    }

    fout << sol;

    return 0;

}
