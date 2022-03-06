#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("cmap.in"); ofstream fout("cmap.out");

vector <pair<long long , long long>> V(100100) , X , Y;
long long dist(pair<long long , long long>& x , pair<long long , long long>& y)
{
    return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}

long long cmap(int left , int right)
{
    if (left >= right - 1)
        return 10000000000000;
    else if (right - left == 2)
    {
        if (Y[left] > Y[left + 1])
            swap(Y[left], Y[left + 1]);
        return dist(X[left], X[left + 1]);
    }
    int mid = (left + right) / 2;
    long long ans = min(cmap(left , mid), cmap(mid , right));

    sort(Y.begin()+left , Y.begin()+right);
    int aux = 0;
    for (int i=left ; i<right ; i++)
        if (abs(Y[i].second - X[mid].first) <= ans)
        {
            V[aux] = Y[i];
            aux++;
        }
    for (int i=0 ; i<aux-1 ; i++)
        for (int j=i+1 ; j<aux && j-i<8 ; j++)
            ans = min(ans , dist(V[i], V[j]));

    return ans;
}

int main()
{
    int n;
    fin >> n;
    X.resize(n);
    Y.resize(n);
    for(auto &i : X)
        fin >> i.first >> i.second;
    sort(X.begin(), X.end());
    for(int i=0 ; i<n ; i++)
        Y[i] = make_pair(X[i].second, X[i].first);
    fout << fixed << setprecision(6) << sqrt(cmap(0, n)) << "\n";
    return 0;
}
