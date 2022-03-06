#include <fstream>
#include <queue>
#include <vector>
#include <ctype.h>
#define i64 long long
using namespace std;
char const in [] = "sate.in";
char const out [] = "sate.out";
int const NM = 1e7 + 7 , NM2 = 30007;
struct code
{
    int cost , node;
};
vector <code> v [NM2];
queue <int> q;
i64 n , m , x , y , dp [NM2];
char buffer [NM + 7];
bool mark [NM2];
i64 best ;
int point ;
int parsebuff ()
{
    int value = 0;
    while(! isdigit (buffer [point]))
    {
        if(point  == NM )
        {
            point = 0;
            fread (buffer , 1 , NM , stdin);
        }
        ++ point;
    }
    while(isdigit (buffer [point]))
    {
        value = value * 10 + (buffer [point] - '0');
        if(point  == NM )
        {
            point = 0;
            fread (buffer , 1 , NM , stdin);
        }
        ++ point;
    }
    return value;
}
void buff ()
{

    freopen(in , "r" , stdin);
    freopen(out , "w" , stdout);
    fread (buffer , 1 , NM , stdin);
    n = parsebuff ();
    m = parsebuff ();
    x = parsebuff ();
    y = parsebuff ();
    int i;
    for(i = 1 ; i <= m ; ++ i)
    {
        int a , b , c;
        code curent;
        a = parsebuff ();
        b = parsebuff ();
        c = parsebuff ();
        curent . cost = c;
        curent . node = b;
        v [a] . push_back (curent);
        curent . cost = - c;
        curent . node = a;
        v [b] . push_back (curent);
    }
}
void bfs ()
{
    q . push (x);
    mark [x] = 1;
    while(q . size ())
    {
        int curent = q . front () , i , sz = v [curent] . size ();
        int minval = 1e9 + 1 , minadd;
        bool r = 0;
        int val = dp [curent];
        for(i = 0 ; i < sz ; ++ i)
            if(! mark [v [curent][i] . node])
            {
                q . push (v [curent][i] . node);
                mark [v [curent][i] . node] = 1;
                dp [v [curent][i] . node] += (v [curent][i] . cost + val);
            }
        q . pop ();
    }
    if(! mark [y])
        printf ("-1");
    else
        printf ("%d" , dp [y]);
}
int main()
{
    buff ();
    bfs ();
    return 0;
}
