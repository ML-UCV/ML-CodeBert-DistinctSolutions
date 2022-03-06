#include <bits/stdc++.h>




using namespace std;



class Parser {

  private:

    static const int SIZE = 1e5;

    char str[SIZE];



    int ptr;

    FILE *fin;



    char getChar() {

        if (ptr == SIZE) {

            fread(str, sizeof(char), SIZE, fin);

            ptr = 0;

        }

        return str[ptr++];

    }



    int getInt() {

        char chr = getChar();

        while (!isdigit(chr) && chr != '-')

            chr = getChar();



        int sgn = +1;

        if (chr == '-') {

            sgn = -1;

            chr = getChar();

        }



        int nr = 0;

        while (isdigit(chr)) {

            nr = nr * 10 + chr - '0';

            chr = getChar();

        }

        return nr * sgn;

    }



  public:

    Parser(const char* str) :

        ptr(SIZE), fin(fopen(str, "r")) { }



    ~Parser() {

        fclose(fin);

    }



    friend Parser& operator>>(Parser& in, int& nr) {

        nr = in.getInt();

        return in;

    }

};



Parser fin("stramosi.in");

ofstream fout("stramosi.out");



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



const int DMAX = 25e4+10;



int dp[DMAX][20];



int n,m;



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int i,j;

    int node,put,p,cate;



    fin>>n>>m;

    for(i=1;i<=n;i++)

        fin>>dp[i][0];



    for(i=1;i<=17;i++)

        for(j=1;j<=n;j++)

            dp[j][i]=dp[dp[j][i-1]][i-1];

    while(m--){

        fin>>node>>p;

        for(i=17;i>=0;i--)

            if((1<<i)<=p){

                p-=(1<<i);

                node=dp[node][i];

            }

        fout<<node<<'\n';

    }



    return 0;

}
