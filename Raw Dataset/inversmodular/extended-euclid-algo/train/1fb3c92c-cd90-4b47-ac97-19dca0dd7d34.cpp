#include <bits/stdc++.h>






using namespace std;



int a , n;



int euclid(int A , int B , int &X , int &Y)

{

    if(B == 0)

    {

        X = 1;

        Y = 0;

        return A;

    }



    int X0 , Y0;

    int D = euclid(B , A % B , X0 , Y0);



    X = Y0;

    Y = X0 - A / B * Y0;



    return D;

}



int invmod()

{

    int X , Y;

    euclid(a , n , X , Y);



    if(X < 0)

        return X + n;



    return X;

}



signed main()

{



  ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) , freopen("inversmodular.in" , "r" , stdin) , freopen("inversmodular.out" , "w" , stdout);





    cin >> a >> n;

    cout << invmod();



    return 0;

}
