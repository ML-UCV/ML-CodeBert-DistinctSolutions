#include<fstream>
#include<vector>
using namespace std;
class InputReader {
private:
    FILE *inputFile;
    static const int SIZE = 1 << 16;
    char buffer[SIZE]; int cursor;

    inline void advance(void) {
        if (++cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, sizeof(char), inputFile);
        }
    }

    inline char current(void) {
        return buffer[cursor];
    }
public:
    InputReader(const char* fileName) : cursor(0) {
        inputFile = fopen(fileName, "r");
        fread(buffer, SIZE, 1, inputFile);
    }

    ~InputReader(void) {
        fclose(inputFile);
    }

    template <class type>
    InputReader &operator >>(type &value) {
        value = 0;
        while (current() < '0' or current() > '9')
            advance();
        while (current() >= '0' and current() <= '9') {
            value = value * 10 + current() - '0';
            advance();
        }
        return *this;
    }
} in("sate.in");
ofstream out("sate.out");
int a,b,c,n,m,x,y,v[30001],go,st,dr,i,hz[30001],distanta[30001];
vector< pair<int,int> >h[30001];
int main(){
    in >> n >> m >> x >> y;
    for( i = 1; i <= m; i ++ ){
        in >> a >> b >> c;
        h[a].push_back( make_pair( b,c ) );
        h[b].push_back( make_pair( a,c ) );
    }
    v[1] = x;
    hz[x] = 1;
    for( st = 1, dr = 1; st <= dr; st ++ ){
        for( i = 0; i < h[v[st]].size(); i ++ ){
            if( v[st] < h[v[st]][i].first )
                distanta[ h[v[st]][i].first ] = distanta[v[st]] + h[v[st]][i].second;
            else
                distanta[ h[v[st]][i].first ] = distanta[v[st]] - h[v[st]][i].second;

            if( hz[ h[v[st]][i].first ] == 0 ){
                hz[ h[v[st]][i].first ] = 1;
                dr++;
                v[dr] = h[v[st]][i].first;
            }
        }
    }
    out<<distanta[y];
    return 0;
}
