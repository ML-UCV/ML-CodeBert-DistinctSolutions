#include <fstream>
#include <vector>
#define DIM 30010
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n,i,j,k,x,y,v[DIM],c[DIM],drum[DIM],m,d;
vector< pair<int,int> > L[DIM];
void bfs(int start, int componenta) {
	v[start]=componenta;
	c[1]=start;
	int st=1,dr=1;
	while (st<=dr) {
		int nod=c[st];
		for (i=0;i<L[nod].size();i++) {
			int vecin1=L[nod][i].first;
			int vecin2=L[nod][i].second;
			if (v[vecin1]==0) {
				c[++dr]=vecin1;
				drum[vecin1]=drum[nod]+vecin2;
				v[vecin1]=componenta;
			}
		}
		st++;
	}
}
int main() {
	fin>>n>>m>>x>>y;
	for (k=1;k<=m;k++) {
		fin>>i>>j>>d;
		L[i].push_back(make_pair(j,d));
		L[j].push_back(make_pair(i,0-d));
	}
	bfs(x,1);
	fout<<drum[y];
	return 0;
}
