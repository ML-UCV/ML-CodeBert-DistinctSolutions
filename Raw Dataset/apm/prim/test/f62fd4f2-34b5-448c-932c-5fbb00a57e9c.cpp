#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;
const int MAX_M = 400000;
const int INF = 1000000000;

bool marked[1+MAX_N];

struct Edge {
 int a, b, c;

 bool operator< (const Edge& x) const {
  return c > x.c;
 }
} edges[1+MAX_M];

priority_queue<Edge> pq;
vector<int> graph[1+MAX_N];

void markNode(int node) {
 marked[node] = true;
 for(auto it: graph[node])
  pq.push(edges[it]);
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
 fclose(fin);

 markNode(1);
 while(!pq.empty()) {
  Edge edge = pq.top();
  pq.pop();

  if(marked[edge.a] + marked[edge.b] == 1) {
   apmA[top] = edge.a;
   apmB[top++] = edge.b;
   sumapm += edge.c;
   if(!marked[edge.a])
    markNode(edge.a);
   else
    markNode(edge.b);
  }
 }

 FILE *fout = fopen("apm.out", "w");
 fprintf(fout, "%d\n%d\n", sumapm, top);
 for(int i = 0; i < top; ++i)
  fprintf(fout, "%d %d\n", apmA[i], apmB[i]);
 fclose(fout);
 return 0;
}
