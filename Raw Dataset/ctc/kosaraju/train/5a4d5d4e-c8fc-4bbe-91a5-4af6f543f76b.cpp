#include<fstream>
#include<vector>




using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



vector<int> adjList[100001], adjTrList[100001], ordList, component;

bool isVisited[100001];

bool isVisitedTr[100001];

vector<vector<int>> result;



void dfs(int startNode) {

 isVisited[startNode] = true;



 for (const auto& node : adjList[startNode]) {

  if (!isVisited[node]) {

   dfs(node);

  }

 }

 ordList.push_back(startNode);

}



void dfsTr(int startNode) {

 isVisitedTr[startNode] = true;

 component.push_back(startNode);



 for (const auto& node : adjTrList[startNode]) {

  if (!isVisitedTr[node]) {

   dfsTr(node);

  }

 }

}



int main() {



 int N, M;



 in >> N >> M;

 for (int i = 0; i < M; ++i) {

  int startNode, endNode;

  in >> startNode >> endNode;

  adjList[startNode].push_back(endNode);

  adjTrList[endNode].push_back(startNode);

 }



 for (int node = 1; node <= N; ++node) {

  if (!isVisited[node]) {

   dfs(node);

  }

 }



 int stronglyConnComp = 0;

 for (int i = 1; i <= N; ++i) {

  int node = ordList[N - i];

  if (!isVisitedTr[node]) {

   ++stronglyConnComp;

   dfsTr(node);

   result.push_back(component);

   component.clear();

  }

 }



 out << stronglyConnComp << '\n';

 for (const auto& resultComponent: result) {

  for (const auto& node : resultComponent) {

   out << node << ' ';

  }

  out << '\n';

 }



 return 0;

}
