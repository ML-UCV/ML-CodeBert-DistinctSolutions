#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include <stack>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



class Graph {

    int vertices;

    list <int> *adj;



    vector <vector <int>> ans;



public:

    Graph(int v) : vertices(v) {

        adj = new list <int>[v];

    }



    void addEdge(int from, int to) {

        adj[from].push_back(to);

    }



    void depthFirst(int i, vector <int> &disc, vector <int> &low, stack <int> &st, vector <bool> &stackMember) {

        static int id = 0;



        disc[i] = low[i] = ++id;

        st.push(i);

        stackMember[i] = true;



        for (auto &adjVal : adj[i]) {

            if (!disc[adjVal]) {

                depthFirst(adjVal, disc, low, st, stackMember);



                low[i] = min(low[i], low[adjVal]);

            }



            else

                if (stackMember[adjVal])

                    low[i] = min(low[i], disc[adjVal]);

        }



        if (low[i] == disc[i]) {

            vector <int> newAns;



            while (st.top() != i) {

                int topVal = st.top();

                st.pop();

                stackMember[topVal] = false;

                newAns.push_back(topVal);

            }



            int topVal = st.top();

            st.pop();

            stackMember[topVal] = false;

            newAns.push_back(topVal);



            ans.push_back(newAns);

        }

    }



    void findSCC() {

        vector <int> disc(vertices), low(vertices);

        vector <bool> stackMember(vertices);

        stack <int> st;



        for (int i = 1; i < vertices; ++i) {

            if (!disc[i])

                depthFirst(i, disc, low, st, stackMember);

        }

    }



    void printData() {

        out << ans.size() << "\n";



        for (size_t j = 0; j < ans.size(); ++j) {

            sort(ans[j].begin(), ans[j].end());

            for (size_t i = 0; i < ans[j].size(); ++i) {

                out << ans[j][i];

                if (i + 1 != ans[j].size())

                    out << " ";

            }

            if (j + 1 != ans.size())

                out << "\n";

        }

    }



};



int main() {



    int N, M;



    in >> N >> M;



    Graph *myGraph = new Graph(N + 1);



    while (M--) {

        int from, to;

        in >> from >> to;

        myGraph -> addEdge(from, to);

    }



    myGraph -> findSCC();



    myGraph -> printData();



    in.close();

    out.close();

    return 0;

}
