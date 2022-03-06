#include <fstream>
#include <vector>
#include <algorithm>




using namespace std;



vector <int> G[256],Gt[256],deque;

int N,Answer;

bool used[256],mark[256];



void DFS(int Nod) {



 used[Nod]=0;

 mark[((Nod)<=N?(Nod+N):(Nod-N))]=1;



 for(int i=0;i<Gt[Nod].size();i++)

  if(used[Gt[Nod][i]])

   DFS(Gt[Nod][i]);



}

void TopologicalSort(int Nod) {



 used[Nod]=1;



 for(int i=0;i<G[Nod].size();i++)

  if(!used[G[Nod][i]])

   TopologicalSort(G[Nod][i]);



 deque.push_back(Nod);



}

void solve() {



 int Nod;



 for(Nod=1;Nod<=2*N;Nod++)

  if(!used[Nod])

   TopologicalSort(Nod);



 reverse(deque.begin(),deque.end());



 for(Nod=0;Nod<2*N;Nod++)

  if(used[deque[Nod]]&&used[((deque[Nod])<=N?(deque[Nod]+N):(deque[Nod]-N))])

   DFS(deque[Nod]);



}

void AddEdges(int x,int y) {



 G[((x)<=N?(x+N):(x-N))].push_back(y);

 G[((y)<=N?(y+N):(y-N))].push_back(x);



 Gt[x].push_back(((y)<=N?(y+N):(y-N)));

 Gt[y].push_back(((x)<=N?(x+N):(x-N)));



}

void read() {



 int x,y,type,M;

 ifstream in("party.in");

 in>>N>>M;



 while(M--) {



  in>>x>>y>>type;



  switch(type) {

   case 0:AddEdges(x,y);break;

   case 1:AddEdges(x,((y)<=N?(y+N):(y-N)));break;

   case 2:AddEdges(((x)<=N?(x+N):(x-N)),y);break;

   case 3:AddEdges(((x)<=N?(x+N):(x-N)),((y)<=N?(y+N):(y-N)));break;

   }



  }



 in.close();



}

void write() {



 ofstream out("party.out");



 for(int i=1;i<=N;i++)

  Answer+=mark[i];



 out<<Answer<<'\n';



 for(int i=1;i<=N;i++)

  if(mark[i])

   out<<i<<'\n';



 out.close();



}

int main() {



 read();

 solve();

 write();



 return 0;



}
