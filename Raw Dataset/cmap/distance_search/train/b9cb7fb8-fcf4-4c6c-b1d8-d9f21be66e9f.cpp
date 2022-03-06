#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

struct punct{int x,y;}p[100010];

int i,j,n;

long long sol;

class InParser {



private:

    FILE *fin;

    char *buff;

    int sp;



    char read_ch() {

        ++sp;

        if (sp == 1048576) {

            sp = 0;

            fread(buff, 1, 1048576, fin);

        }

        return buff[sp];

    }



public:

    InParser(const char* nume) {

        fin = fopen(nume, "r");

        buff = new char[1048576]();

        sp = 1048576 -1;

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



    InParser& operator >> (long long &n) {

        char c;

        n = 0;

        while (!isdigit(c = read_ch()) && c != '-');

        long long sgn = 1;

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

inline long long dist(punct a,punct b) {return (long long)((long long)(a.x-b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y));}

struct cmp{inline bool operator ()(punct a,punct b){return a.x<b.x;}};



int main()

{

    InParser f("cmap.in");

    ofstream g("cmap.out");

    f>>n;

    for(i=0;i<n;i++)

    f>>p[i].x>>p[i].y;

    sort(p,p+n,cmp());

    sol=(1LL<<61);

    for(i=0;i<n;i++)

    for(j=i+1;j<=i+3 and j<n;j++) if(dist(p[i],p[j])<sol) sol=dist(p[i],p[j]);

    g<<setprecision(6)<<fixed;

    g<<sqrt((double)sol)<<"\n";

}
