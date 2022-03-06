#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;
#define SatDist pair<int, int>
ifstream fin("sate.in");
ofstream fout("sate.out");
vector<SatDist> arr[100030];
int n, m, x, y, sat, _sat, dist;
queue<int> coada;
int vec[100000];

int nod;

int main(){
	//for(int i = 0; i < 100; i++)vec[i] = -1;
	memset(vec,-1,sizeof(vec));
	fin >> n >> m >> x >> y;
    for(int i = 0; i < m; i++){
        fin >> sat >> _sat >> dist;
        arr[sat].push_back({_sat, dist});
        arr[_sat].push_back({sat, dist});
    }
	
	//for(int i = 0; i < m; )
	
	
	vec[x] = 0;
	coada.push(x);
	while(!coada.empty()){
		nod = coada.front();
		for(int i = 0; i < arr[nod].size(); i++){
			if(vec[arr[nod][i].first] == -1){
				if(nod < arr[nod][i].first)
					vec[arr[nod][i].first] = vec[nod] + arr[nod][i].second;
				else 
					vec[arr[nod][i].first] = vec[nod] - arr[nod][i].second;
				coada.push(arr[nod][i].first);
			}
		}
		coada.pop();
	}
	
	fout << vec[y];
	fout.close();
	fin.close();
    return 0;
}
