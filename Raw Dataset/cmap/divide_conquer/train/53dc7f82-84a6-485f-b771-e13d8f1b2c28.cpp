#include <bits/stdc++.h>
namespace FastRead

{

    char buff[5000];long long lg = 0 , p = 0;

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



const long long N = 1e5 + 10;

const long long M = 1e9 + 7;

const long double PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



long long n;

pair < long long , long long > X[N] , Y[N] , aux[N];



long long dist(pair < long long , long long > a , pair < long long , long long > b)

{

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



void merge(long long l1 , long long r1 , long long l2 , long long r2)

{

    long long i1 = l1 , i2 = l2 , lg = 0;



    while(i1 <= r1 && i2 <= r2)

    {

        if(Y[i1] <= Y[i2])

            aux[++lg] = Y[i1++];

        else aux[++lg] = Y[i2++];

    }



    while(i1 <= r1)

        aux[++lg] = Y[i1++];



    while(i2 <= r2)

        aux[++lg] = Y[i2++];

}



void copy(long long l , long long r)

{

    for(long long i = l ; i <= r ; i++)

        Y[i] = aux[i - l + 1];

}



long long divide(long long l , long long r , pair < long long , long long > X[] , pair < long long , long long > Y[])

{

    if(l >= r)

        return LLONG_MAX;



    if(r - l + 1 <= 3)

    {

        sort(Y + l , Y + r + 1);



        long long optimal = LLONG_MAX;



        for(long long i = l ; i < r ; i++)

            for(long long j = i + 1 ; j <= r ; j++)

                optimal = min(optimal , dist(X[i] , X[j]));



        return optimal;

    }



    long long mid = (r + l) / 2;

    long long optimal = min( divide(l , mid , X , Y) , divide(mid + 1 , r , X , Y) );



    merge(l , mid , mid + 1 , r);

    copy(l , r);



    long long lg = 0;



    for(long long i = l ; i <= r ; i++)

        if(abs(Y[i].second - X[mid].first) <= optimal)

            aux[++lg] = Y[i];



    for(long long i = 1 ; i <= lg ; i++)

        for(long long j = i + 1 ; j <= lg && j - i + 1 <= 8 ; j++)

            optimal = min(optimal , dist(aux[i] , aux[j]));



    return optimal;

}



signed main()

{



  ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) , freopen("cmap.in" , "r" , stdin) , freopen("cmap.out" , "w" , stdout);





    cin >> n;



    for(long long i = 1 ; i <= n ; i++)

        cin >> X[i].first >> X[i].second;



    sort(X + 1 , X + n + 1);



    for(long long i = 1 ; i <= n ; i++)

        Y[i] = {X[i].second , X[i].first};



    cout << fixed << setprecision(6) << sqrt(divide(1 , n , X , Y));



    return 0;

}
