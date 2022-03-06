#include<fstream>
#include<cstring>


using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

char s1[50001], s2[50001];

unsigned short f1[50001],f2[50001],a[50001];

unsigned int m[27][50001];

int n;

void update (int p) {

    for (int i=p;i<=n;i+=(i&(-i)))

        a[i]++;

    return;

}

int query(int p) {

    int s=0;

    for (int i=n;i>=1;i-=(i&(-i)))

        s+=a[i];

    for (int i=p;i>=1;i-=(i&(-i)))

        s-=a[i];

    return s;

}

int sol;

int main() {

    fin >> s1+1;

    fin >> s2+1;

    n = strlen(s1+1);

    for (int i=1; i<=n; i++) {

        f1[s1[i]-'a'+1]++;

        f2[s2[i]-'a'+1]++;

        m[s1[i]-'a'+1][f1[s1[i]-'a'+1]]=i;

    }

    for (int i=1;i<=26; i++) {

        if (f1[i]!=f2[i]) {

            fout<<-1;

            return 0;

        }

        f2[i]=0;

    }

    for (int i=1; i<=n; i++) {

        f2[s2[i]-'a'+1]++;

        int x = m[s2[i]-'a'+1][f2[s2[i]-'a'+1]];

        update (x);

        sol+=query(x);

    }

    fout << sol;

    return 0;

}
