#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>


const int kMaxDim = 1505;

const int kModulo = 104659;

const double eps = 1e-8;

const double inf = 1e10;



inline double Abs(const double& a) {

 return (a > 0 ? a : -a);

}



inline int Compare(const double& a, const double& b) {

 if (Abs(a - b) < eps)

  return 0;

 return (a < b ? -1 : 1);

}



struct Data {

 int node;

 double cost;

};



struct Functor {

 bool operator()(const Data& a, const Data& b) {

  return Compare(a.cost, b.cost) > 0;

 }

};



int nodeCount, edgeCount;

std::vector< Data > edges[kMaxDim];

double minDist[kMaxDim];

int minDistCount[kMaxDim];



std::priority_queue< Data, std::vector< Data >, Functor > heap;



int main() {

 std::ifstream inputFile("dmin.in");

 std::ofstream outputFile("dmin.out");



 inputFile >> nodeCount >> edgeCount;

 for (int i = 1; i <= edgeCount; ++i) {

  int first, second;

  double cost;

  inputFile >> first >> second >> cost;

  cost = log(cost);



  edges[first].push_back({second, cost});

  edges[second].push_back({first, cost});

 }



 for (int i = 2; i <= nodeCount; ++i)

  minDist[i] = inf;

 minDistCount[1] = 1;

 heap.push({1, 0});



 while (!heap.empty()) {

  while (!heap.empty() && Compare(minDist[heap.top().node], heap.top().cost) < 0)

   heap.pop();

  if (heap.empty())

   break;



  int node = heap.top().node;

  double cost = heap.top().cost;

  heap.pop();



  for (Data& edge : edges[node]) {

   if (Compare(minDist[edge.node], cost + edge.cost) > 0) {

    minDist[edge.node] = cost + edge.cost;

    minDistCount[edge.node] = minDistCount[node];

    heap.push({edge.node, minDist[edge.node]});

   }

   else if (Compare(minDist[edge.node], cost + edge.cost) == 0) {

    minDistCount[edge.node] += minDistCount[node];

    minDistCount[edge.node] %= kModulo;

   }

  }

 }



 for (int i = 2; i <= nodeCount; ++i)

  outputFile << minDistCount[i] << ' ';

 outputFile << '\n';



 inputFile.close();

 outputFile.close();



 return 0;

}
