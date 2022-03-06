#include <fstream>
#include <vector>

using namespace std;

vector < pair <int,int> > v[30001];
bool viz[30001];
char s[1001];

ifstream in ("sate.in");
ofstream out ("sate.out");

int n,m,st,fin;

void read()
{   in>>n>>m>>st>>fin;
    in.get();
    int x, y, c, nr, cnt;
    for (int k = 1; k <= m; ++k)
    {   cnt = 0;
        in.getline(s, 1001);
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                nr = 0;
                cnt++;
                while (s[i] >= '0' && s[i] <= '9') {
                    nr = nr * 10 + s[i] - '0';
                    ++i;
                }
                if (cnt == 1) x = nr;
                if (cnt == 2) y = nr;
                if (cnt == 3) c = nr;
            }
        }
        v[x].push_back({y,c});
        v[y].push_back({x,c});
    }
}

void drum(int nod,int dist)
{
  viz[nod]=1;
  if (nod==fin)
  {
    out<<dist;
  }
  else
  {
    int nod1,d;
    for (int i=0;i<v[nod].size();i++)
    {
      nod1=v[nod][i].first;
      d=v[nod][i].second;
      if (viz[nod1]==0&&nod1<nod)
        drum(nod1,dist-d);
      else if (viz[nod1]==0&&nod1>nod)
        drum(nod1,dist+d);
    }
  }
}

int main()
{
    read();
    drum(st,0);
    return 0;
}
