#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz size()
using namespace std;
const int NR = 30001 ;
ofstream g("sate.out");
vector < pair < int , int > > v [ NR ] ;
int d [ NR ] , start ;


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
int bfs ( int q ){
    deque < int > c ;
    c.pb ( q ) ;
    d [ q ] = 1 ;
    while ( !c.empty() ){
        int nod = c.front() ;
        if ( nod == start )  return g << abs ( d [ nod ] - 1 ) << "\n" , 0 ;
        for ( size_t i = 0 ; i < v [ nod ].sz ; ++ i ){
            int vecin = v [ nod ][ i ].first ;
            int cost = v [ nod ][ i ].second ;
            if ( !d[ vecin ] )
            {
                if ( vecin > nod )  d[ vecin ] = d [ nod ] + cost ;
                else                d[ vecin ] = d [ nod ] - cost ;
                c.pb( vecin) ;
            }}c.pop_front();}}
int main (){
    InParser f ("sate.in") ;
    int n , m , stop ;
    f >> n >> m >> stop >> start ;
    while ( m -- ){
        int a , b , c ; f >> a >> b >> c ;
        v [ a ].pb( mp ( b , c ) ) ;
        v [ b ].pb( mp ( a , c ) ) ;}
    bfs ( stop ) ;}













