#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

ifstream cin("cmap.in");

ofstream cout("cmap.out");



int n,x,y;

vector<pair<int,int> > X;



long long sq(pair<int,int> &i,pair<int,int> &j){



    return 1LL*(i.first-j.first)*(i.first-j.first)+

            1LL*(i.second-j.second)*(i.second-j.second);



}



long long minDist(int s,int d){



    if(d-s<=2){



        long long D=4e18;

        for(int i=s;i<=d;i++)

            for(int j=i+1;j<=d;j++)

                D=min(D,sq(X[i],X[j]));



        return D;



    }



    int m=(s+d)/2;



    long long D1=minDist(s,m);

    long long D2=minDist(m,d);

    long long D=min(D1,D2);



    vector<pair<int,int> > Y(X.begin()+s,X.begin()+d+1);

    for(int i=0;i<Y.size();i++)

        swap(Y[i].first,Y[i].second);

    sort(Y.begin(),Y.end());



    vector<pair<int,int> > V;

    for(int i=0;i<Y.size();i++)

        if(abs(Y[i].second-X[m].first)<=D)

            V.push_back(Y[i]);



    for(int i=0;i<V.size();i++)

        for(int j=i+1;j<V.size() && j-i<6;j++)

            D=min(D,sq(V[i],V[j]));



    return D;



}



int main(){



    cin>>n;



    for(int i=1;i<=n;i++){



        cin>>x>>y;

        X.push_back(make_pair(x,y));



    }



    sort(X.begin(),X.end());



    cout<<setprecision(15)<<sqrt(minDist(0,n-1));



}
