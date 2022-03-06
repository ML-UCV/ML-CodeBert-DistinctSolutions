#include <bits/stdc++.h>

using namespace std;

class Reader {
  public:
    Reader(const string& filename):
            m_stream(filename),
            m_pos(kBufferSize - 1),
            m_buffer(new char[kBufferSize]) {
        next();
    }

    Reader& operator>>(int& value) {
        value = 0;
        while (current() < '0' || current() > '9')
            next();
        while (current() >= '0' && current() <= '9') {
            value = value * 10 + current() - '0';
            next();
        }
        return *this;
    }

  private:
    const int kBufferSize = 32768;

    char current() {
        return m_buffer[m_pos];
    }

    void next() {
        if (!(++m_pos != kBufferSize)) {
            m_stream.read(m_buffer.get(), kBufferSize);
            m_pos = 0;
        }
    }

    ifstream m_stream;
    int m_pos;
    unique_ptr<char[]> m_buffer;
};

Reader fin("sate.in");
ofstream fout("sate.out");

const int NMAX = 30005;
vector < pair<int,int> > v[NMAX];
int a[NMAX],d[NMAX];
bool ver[NMAX];
queue <int> q;

int main()
{
    int n,m,x,y,x1,y1,cost;
    fin >> n >> m >> x >> y;
    for(int i=1;i<=m;i++)
    {
        fin >> x1 >> y1 >> cost;
        v[x1].push_back(make_pair(y1,cost));
        v[y1].push_back(make_pair(x1,-cost));
    }
    ver[x]=true;
    q.push(x);
    while(!q.empty())
    {
        int nod=q.front();
        q.pop();
        for(int i=0;i<v[nod].size();i++){
            int vecin=v[nod][i].first;
            int cost2=v[nod][i].second;
            if(ver[vecin]==false){
                ver[vecin]=true;
                q.push(vecin);
                d[vecin]=d[nod]+cost2;
            }
        }
        if(ver[y]==true) break;
    }
    fout << d[y];
    return 0;
}
