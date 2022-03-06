#include <bits/stdc++.h>




using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int nxt[2000005], ocr[2000005];

string s, c;



int main()

{

    fin >> s >> c;

    int n=s.size();

    int m=c.size();

    nxt[0]=0;

    int j=0;

    for(int i=1; i<n; i++)

    {

        while(j>0 && s[i]!=s[j])

            j=nxt[j-1];

        if(s[i]==s[j])

            j++;

        nxt[i]=j;

    }

    int nr=0;

    j=0;

    for(int i=0; i<m; i++)

    {

        while(j>0 && s[j]!=c[i])

            j=nxt[j-1];

        if(s[j]==c[i])

            j++;

        if(j==n)

            ocr[++nr]=i-n+1;

    }

    fout << nr << "\n";

    for(int i=1; i<=min(nr, 1000); i++)

        fout << ocr[i] << " ";

    return 0;

}
