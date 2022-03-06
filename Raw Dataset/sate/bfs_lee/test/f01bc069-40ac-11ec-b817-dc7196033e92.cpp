#include <fstream>
#include <queue>
#include <iostream>
using namespace std;
ofstream fout("sate.out");

class InParser {

private:
	FILE *fin;
	char *buff;
	int sp;
	char read_ch() {
		++sp;
		if (sp == 4096) {
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
		return buff[sp];
	}
public:
	InParser(const char* nume) {
		fin = fopen(nume, "r");
		buff = new char[4096]();
		sp = 4095;
	}
	InParser& operator >> (int &n) {
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
};
//First destinatie second distanta
vector<pair<int,int>> graf[30005];
inline void addMuchie(int start,int ender,int d)
{
    graf[start].push_back({ender,d});
    graf[ender].push_back({start,d});
}
int n,m,x,y;
int distanta[30005];
inline int calculateDistance(int start,int ender)
{
    if(start<graf[start][ender].first)
    {
        return distanta[start]+graf[start][ender].second;
    }
    return distanta[start]-graf[start][ender].second;
}
queue<int> cue;
int bfs()
{
    cue.push(x);
    while(cue.size())
    {
        int frontC = cue.front();
        for(int i = 0;i<graf[frontC].size();i++)
        {
            int vdistanta = calculateDistance(frontC,i);
            if(distanta[graf[frontC][i].first]==0)
            {
                distanta[graf[frontC][i].first]=vdistanta;
                cue.push(graf[frontC][i].first);
                if(distanta[y]!=0)
                    return distanta[y];
            }
        }
        cue.pop();
    }
    return distanta[y];
}
int temp1,temp2,temp3;
int main()
{
    InParser fin("sate.in");
    fin>>n>>m>>x>>y;
    if(x>y)
        swap(x,y);
    while(m--)
        fin>>temp1>>temp2>>temp3,addMuchie(temp1,temp2,temp3);
    fout<<bfs();
    return 0;
}
