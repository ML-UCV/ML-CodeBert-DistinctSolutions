#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;
const int MAX_M = 400000;
const int INF = 1000000000;

bool marked[1+MAX_N];

struct Edge {
 int a, b, c;

 int other(int x) {
  return a ^ b ^ x;
 }
} edges[1+MAX_M];

struct Node {
 int nod, i;
 bool operator< (const Node& x) const {
  return edges[i].c < edges[x.i].c ||
        (edges[i].c == edges[x.i].c && nod < x.nod);
 }
};

vector<int> graph[1+MAX_N];

int bestEdge[1+MAX_N];
set<Node> nodes;

void markNode(int node) {
 marked[node] = true;
 for(auto it: graph[node]) {
  int son = edges[it].other(node);
  if(!marked[son] && edges[it].c < edges[bestEdge[son]].c) {
   nodes.erase({son, bestEdge[son]});
   bestEdge[son] = it;
   nodes.insert({son, bestEdge[son]});
  }
 }
 nodes.erase({node, bestEdge[node]});
}

int top;
int apmA[1+MAX_N], apmB[1+MAX_N];

int main() {
 int N, M, sumapm = 0;

 FILE *fin = fopen("apm.in", "r");
 fscanf(fin, "%d%d", &N, &M);

 for(int i = 0; i < M; ++i) {
  int a, b, c;
  fscanf(fin, "%d%d%d", &a, &b, &c);
  edges[i] = {a, b, c};
  graph[a].push_back(i);
  graph[b].push_back(i);
 }
 edges[M] = {0, 0, INF};

 for(int i = 1; i <= N; ++i) {
  bestEdge[i] = M;
  nodes.insert({i, bestEdge[i]});
 }
 fclose(fin);

 markNode(1);
 for(int i = 2; i <= N; ++i) {
  int nod = nodes.begin()->nod, edge = nodes.begin()->i;

  sumapm += edges[edge].c;
  apmA[top] = edges[edge].a;
  apmB[top++] = edges[edge].b;

  markNode(nod);
 }

 FILE *fout = fopen("apm.out", "w");
 fprintf(fout, "%d\n%d\n", sumapm, top);
 for(int i = 0; i < top; ++i)
  fprintf(fout, "%d %d\n", apmA[i], apmB[i]);
 fclose(fout);
 return 0;
}
