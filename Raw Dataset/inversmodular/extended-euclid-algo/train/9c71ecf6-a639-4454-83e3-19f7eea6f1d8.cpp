#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
#include <map>
#include <math.h>

using namespace std;
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
typedef pair<int,int> p;
p euclid(int a , int b, int c)
{
    if(b == 0)
    {
        if(c%a)return make_pair(0, 0);
        else return make_pair(c/a, 0);
    }
    else
    {
        p rez = euclid(b, a%b, c);
        return make_pair(rez.second, rez.first - a/b * rez.second);
    }
}
int main() {
    int a , b;
    f>>a>>b;
    auto rez = euclid(a, b, 1);
    int r = rez.first;
    if(r<0)r+=b;
    g<<r;
    return 0;
}
