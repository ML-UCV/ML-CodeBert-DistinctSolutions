#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector < pair < int , int > > P;

long long CALCULATE_DISTANCE( pair < int, int> a, pair< int, int> b) {

    return (long long) (a.first-b.first) * (a.first-b.first)+ (long long) (a.second - b.second) * (a.second - b.second);

}

bool cmp(pair<int,int> a, pair<int,int>b)

{

    return a.second < b.second;

}

long long FIND_CLOSEST_PAIR(int left, int right) {

    if((right-left)==1)

        return CALCULATE_DISTANCE(P[right],P[left]);

    if((right-left)==2){

        long long minimum=CALCULATE_DISTANCE(P[left],P[left+1]);

        if(CALCULATE_DISTANCE(P[left],P[right])<minimum)

            minimum=CALCULATE_DISTANCE(P[left],P[right]);

        if(CALCULATE_DISTANCE(P[left+1],P[right])<minimum)

            minimum=CALCULATE_DISTANCE(P[left+1],P[right]);

        return minimum;

    }

    int median = (right+left)/2;

    long long closest_value = min(FIND_CLOSEST_PAIR(left, median), FIND_CLOSEST_PAIR(median+1, right));

    vector < pair < int , int > > Y;

    for(int i=left;i<=right;i++)

        if(abs(P[i].first-P[median].first)<=(int)(ceil(sqrt(closest_value))))

            Y.push_back(std::make_pair(P[i].first,P[i].second));

    sort(Y.begin(),Y.end(),cmp);

    for(unsigned int i=0;i<Y.size();i++)

        for(unsigned j=i+1;(j<=i+7)&&(j<Y.size());j++)

            closest_value = min(closest_value, CALCULATE_DISTANCE(Y[i],Y[j]));

    return closest_value;

}

int main(){

    ifstream f("cmap.in");

    ofstream g("cmap.out");

    unsigned int n;

    f>>n;

    for(unsigned int i=0;i<n;i++){

        int x,y;

        f>>x>>y;

        P.push_back(std::make_pair(x,y));

    }

    std::sort( P.begin() , P.end());

    g<<fixed<<setprecision(6)<<sqrt(FIND_CLOSEST_PAIR(0,n-1));

    f.close();

    g.close();

}
