#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int INF = 2100000000;



int n, m;

vector <pair <int, int>> * lv;



class Edge{



public:



    int first;

    int second;



    int price;



    Edge(int f, int s, int p): first(f), second(s), price(p) {};

};



int min_price;

vector <Edge> selected;

int * pair_node;



int * d;

bool * v;



int * q_pos;

int * q;

int q_dim;



int pop(){



    swap(q_pos[q[1]], q_pos[q[q_dim]]);

    swap(q[1], q[q_dim]);



    q_dim -= 1;



    bool ok = 0;



    int pos = 1;

    while(!ok)



        if(pos * 2 > q_dim && pos * 2 + 1 > q_dim)



            ok = true;



        else if(pos * 2 > q_dim){



            if(d[q[pos * 2 + 1]] > d[q[pos]])



                ok = true;



            else{



                swap(q_pos[q[pos * 2 + 1]], q_pos[q[pos]]);

                swap(q[pos * 2 + 1], q[pos]);



                pos *= 2;

                pos += 1;

            }

        }

        else if(pos * 2 + 1 > q_dim){



            if(d[q[pos * 2]] > d[q[pos]])



                ok = true;



            else{



                swap(q_pos[q[pos * 2]], q_pos[q[pos]]);

                swap(q[pos * 2], q[pos]);



                pos *= 2;

            }

        }

        else{



            if(d[q[pos]] < d[q[pos * 2]] && d[q[pos]] < d[q[pos * 2 + 1]])



                ok = true;



            else if(d[q[pos * 2]] < d[q[pos * 2 + 1]]){



                swap(q_pos[q[pos * 2]], q_pos[q[pos]]);

                swap(q[pos * 2], q[pos]);



                pos *= 2;

            }

            else{



                swap(q_pos[q[pos * 2 + 1]], q_pos[q[pos]]);

                swap(q[pos * 2 + 1], q[pos]);



                pos *= 2;

                pos += 1;

            }

        }



    return q[q_dim + 1];

}



void update(int node){



    int pos = q_pos[node];



    bool ok = 0;



    while(!ok)



        if(pos / 2 == 0 || d[q[pos]] > d[q[pos / 2]])



            ok = true;

        else{



            swap(q_pos[q[pos]], q_pos[q[pos / 2]]);

            swap(q[pos], q[pos / 2]);



            pos /= 2;

        }

}



void prim(){



    while(q_dim){



        int current_node = pop();

        v[current_node] = 1;





        if(current_node != 1){



            min_price += d[current_node];

            selected.push_back(Edge(current_node, pair_node[current_node], d[current_node]));

        }



        for(int i = 0; i < lv[current_node].size(); i++){



            int next_node = lv[current_node][i].first;

            int new_price = lv[current_node][i].second;



            if(!v[next_node] && d[next_node] > new_price){



                d[next_node] = new_price;

                pair_node[next_node] = current_node;



                update(next_node);

            }

        }

    }

}



int main(){



    f >> n >> m;



    lv = new vector <pair <int ,int>> [n + 1];



    d = new int [n + 1];

    v = new bool [n + 1];



    pair_node = new int [n + 1];



    q = new int [n + 1];

    q_pos = new int [n + 1];

    q_dim = n;



    for(int i = 1 ; i <= n; i++){



        d[i] = INF;

        v[i] = 0;



        q[i] = i;

        q_pos[i] = i;

    }



    int x, y, c;

    for(int i = 0; i < m ; i++){



        f >> x >> y >> c;



        lv[x].push_back(make_pair(y, c));

        lv[y].push_back(make_pair(x, c));

    }



    prim();



    g << min_price << '\n';



    g << selected.size() << '\n';

    for(int i = 0; i < selected.size(); i++)



        g << selected[i].first << " " << selected[i].second << '\n';





    return 0;

}
