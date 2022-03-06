#include <iostream>
#include <fstream>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

 ifstream myinpf ("stramosi.in");

 unsigned int N, M, i;

 myinpf >> N >> M;

 vector<unsigned int> graph[N+1];

 unsigned int anc_array[N+1], depth_array[N+1], anc;

 depth_array[0] = 0;

 for(i = 1 ; i < N + 1; i++) {

  myinpf >> anc;

  graph[anc].push_back(i);

  depth_array[i] = depth_array[anc] + 1;

 }

 vector< pair<unsigned int, unsigned int> > querry_arr[N+1];

 unsigned int a, b, results_arr[M];

 for(i = 0 ; i < M ; i++) {

  myinpf >> a >> b;

  querry_arr[a].push_back(make_pair(b, i));

 }

 myinpf.close();

 stack<unsigned int> s;

 s.push(0);

 anc_array[0] = 0;

 while(!s.empty()) {
  a = s.top();
  s.pop();

  anc_array[depth_array[a]] = a;

  for(vector<unsigned int>::iterator t = graph[a].begin() ; t != graph[a].end() ; ++t) {

   for(vector< pair<unsigned int, unsigned int> >::iterator p = querry_arr[*t].begin();
    p != querry_arr[*t].end() ; ++p ) {

    if(p->first >= depth_array[a] + 1)
     results_arr[p->second] = 0;
    else
     results_arr[p->second] = anc_array[depth_array[a] + 1 - p->first];
   }
   s.push(*t);
  }
 }

 ofstream myoutf ("stramosi.out");

 unsigned int *ap = results_arr;
 while(M--) {
  myoutf << *ap << '\n';
  ap++;
 }

 myoutf.close();

 return 0;
}
