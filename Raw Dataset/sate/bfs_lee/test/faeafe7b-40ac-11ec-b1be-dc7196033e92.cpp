#include <bits/stdc++.h>
using namespace std;

	
class InParser 
{
	
private:
	
	FILE *fin;
	
	char *buff;
	int sp;
	
	char read_ch() 
	{
		sp++;
	
		if(sp == 4096) 
		{
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
	
		return buff[sp];
	}
	
public:
	
	InParser(const char* nume) 
	{
		fin = fopen(nume, "r");
		
		buff = new char[4096]();
		sp = 4095;
	}
	
	InParser& operator >> (int &n) 
	{
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		
		n = c - '0';
	
		while (isdigit(c = read_ch())) 
			n = 10 * n + c - '0';
	
		return *this;
	}
};

ofstream out("sate.out");

const int DIM = 3e4 + 7;
const int INF = 1E9;

vector <pair <int, int> > v[DIM];

int pos[DIM];

int n, m, x, y, i;

queue <int> q;
int main()
{
	InParser fin("sate.in");
	
	fin >> n >> m >> x >> y;
	
	for(i = 1; i <= m; i++)
	{
		int x, y, d;
		fin >> x >> y >> d;
		
		v[x].push_back({y, d});
		v[y].push_back({x, -d});
	}
	
	for(int i = 1; i <= n; i++)
		pos[i] = INF;
	
	pos[x] = 0;
	
	q.push(x);

	while(pos[y] == INF)
	{
		int curr = q.front();
		
		q.pop();
		
		for(auto i : v[curr])
			if(pos[i.first] == INF)
			{
				pos[i.first] = pos[curr] + i.second;
				q.push(i.first);
			}
	}
	
	out << pos[y];

}