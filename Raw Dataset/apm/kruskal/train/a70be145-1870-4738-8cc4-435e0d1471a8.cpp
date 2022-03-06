#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



vector< pair<int,int> >apm;



int n, m, t[200001], s;



struct muchii

{

    int x, y, cost;

};



muchii lm[400001];



bool cmp(muchii a, muchii b)

{

    return a.cost<b.cost;

}



int rep(int i)

{

    if(t[i]!=i)

        t[i] = rep(t[i]);



    return t[i];

}



int main()

{

    f >> n >> m;



    for(int i = 0; i < m; i++)

        f >> lm[i].x >> lm[i].y >> lm[i].cost;



    sort(lm, lm + m, cmp);



    for(int i = 1; i <= n; i++)

        t[i] = i;



    for(int i = 0; i < m; i++)

        if(rep(lm[i].x) != rep(lm[i].y))

        {

            t[rep(lm[i].y)] = lm[i].x;

            s += lm[i].cost;

            apm.push_back ( make_pair(lm[i].x,lm[i].y));

        }



    g<<s<<'\n'<<apm.size()<<'\n';



   for( auto elem =apm.begin(); elem != apm.end(); elem++)

        g<<(*elem).first<<" " << (*elem).second<< '\n';



    return 0;

}
