#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



class Edge{



public:



    int first;

    int second;



    int price;

};



int n, m;

Edge * lm;



int * t;



vector <Edge> selected;

int price_min;



bool comp(Edge i, Edge j){



    if(i.price < j.price)

        return 1;



    return 0;

}



int get_root(int node){



    if(t[node] > 0){



        int root = get_root(t[node]);

        t[node] = root;



        return root;

    }

    else

        return node;

}



bool check(int i){



    int root_first = get_root(lm[i].first);

    int root_second = get_root(lm[i].second);



    if(root_first == root_second)

        return 0;



    if(t[root_first] <= t[root_second]){



        t[root_first] += t[root_second];

        t[root_second] = root_first;

    }

    else{



        t[root_second] += t[root_first];

        t[root_first] = root_second;

    }



    return 1;

}



void Kruskal(){



    sort(lm, lm + m, comp);



    for(int i = 0; i < m; i++)



        if(check(i)){



            price_min += lm[i].price;

            selected.push_back(lm[i]);

        }

}



int main(){



    f >> n >> m;



    lm = new Edge[m];

    t = new int[n + 1];



    for(int i = 0; i <= n; i++)

        t[i] = -1;



    int x, y, c;

    for(int i = 0; i < m; i++){



        f >> x >> y >> c;



        lm[i].first = x;

        lm[i].second = y;

        lm[i].price = c;

    }



    Kruskal();



    g << price_min << '\n';

    g << selected.size() << '\n';



    for(int i = 0; i < selected.size(); i++)



        g << selected[i].first << " " << selected[i].second << '\n';



    return 0;

}
