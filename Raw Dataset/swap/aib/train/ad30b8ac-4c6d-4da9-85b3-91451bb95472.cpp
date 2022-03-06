# include <fstream>
# include <queue>


using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

queue<int> d[27];

char a[50010],b[50010];

int v[50010],f[27],n,i;

long long s;

void update(int poz){

    for(int i=poz;i<=n;i+=(i&(-i)))

        v[i]++;

}

int query(int poz){

    int s=0;

    for(int i=poz;i>=1;i-=(i&(-i)))

        s+=v[i];

    return s;

}

int main () {

    fin>>a+1>>b+1;

    for(i=1;b[i]!=0;i++,n++)

        d[b[i]-'a'+1].push(i);

    for(i=1;i<=n;i++){

        if(d[a[i]-'a'+1].size()==0){

            fout<<"-1\n";

            return 0;

        }

        int el=d[a[i]-'a'+1].front();

        s+=el-1-query(el);

        update(el);

        d[a[i]-'a'+1].pop();

    }

    fout<<s<<"\n";

    return 0;

}
