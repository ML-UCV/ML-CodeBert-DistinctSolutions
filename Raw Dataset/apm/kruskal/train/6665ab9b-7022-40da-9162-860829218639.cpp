#include <bits/stdc++.h>
namespace FastRead

{

    char buff[5000];int lg = 0 , p = 0;

    char nc()

    {

        if(lg == p){lg = fread(buff , 1 , 5000 , stdin);p = 0;if(!lg) return EOF;}

        return buff[p++];

    }

    template<class T>void read(T&x)

    {

        T sgn = 1; char c;while(!isdigit(c = nc()))if(c == '-')sgn = -1;

        x = c - '0';while(isdigit(c = nc()))x = x * 10 + c - '0';x *= sgn;

    }

}



using namespace FastRead;

using namespace std;



const int N = 4e5 + 10;

const int M = 1e9 + 7;

const long double PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int n , m , x , y , cost;

int root[N] , height[N];

vector < pair < int , int > > answer;



struct ceva

{

    int cost , x , y;

}a[N];



bool inline cmp(ceva a , ceva b)

{

    return a.cost < b.cost;

}



int find(int x)

{

    int R;



    for(R = x ; R != root[R] ; R = root[R]);



    for( ; root[x] != x ; )

    {

        int aux = root[x];

        root[x] = R;

        x = aux;

    }



    return R;

}



void unite(int rx , int ry)

{

    if(height[rx] < height[ry])

        root[rx] = ry;

    else if(height[rx] > height[ry])

        root[ry] = rx;

    else

    {

        ++height[ry];

        root[rx] = ry;

    }

}



signed main()

{



  ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) , freopen("apm.in" , "r" , stdin) , freopen("apm.out" , "w" , stdout);





    int i;



    cin >> n >> m;



    for(i = 1 ; i <= m ; i++)

    {

        cin >> x >> y >> cost;

        a[i] = {cost , x , y};

    }



    sort(a + 1 , a + m + 1 , cmp);



    for(i = 1 ; i <= n ; i++)

    {

        root[i] = i;

        height[i] = 1;

    }



    int sum = 0;



    for(i = 1 ; i <= m ; i++)

    {

        int rx = find(a[i].x);

        int ry = find(a[i].y);



        if(rx != ry)

        {

            sum += a[i].cost;

            answer.push_back({a[i].x , a[i].y});

            unite(rx , ry);

        }

    }



    cout << sum << '\n';

    cout << answer.size() << '\n';



    for(auto i : answer)

        cout << i.first << ' ' << i.second << '\n';



    return 0;

}
