#include<bits/stdc++.h>
using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

struct edge{
	int destination,cost;
};


int num_nodes,num_edges,x,y;
vector<edge> graph[30000];
bool visited[30000];
int dist[30000];


string file_input;
int cursor=0;

bool is_digit(char a){
	return a>='0' && a<='9';
}


int get_next_number(){
	int result=0;
	while(is_digit(file_input[cursor])){
		result=result*10+(int)(file_input[cursor]-'0');
		cursor++;
	}
	cursor++;

	return result;
}



void read(){

	file_input=string((std::istreambuf_iterator<char>(in)),
			std::istreambuf_iterator<char>());

	num_nodes=get_next_number();
	num_edges=get_next_number();
	x=get_next_number();
	y=get_next_number();
	int a,b,c;
	for(int i=0;i<num_edges;i++){
		a=get_next_number();
		b=get_next_number();
		c=get_next_number();
		graph[a-1].push_back({b-1,c});
		graph[b-1].push_back({a-1,c});
	}
}



int bfs(int start,int end){//returns distance between the two parameters
	visited[start]=true;
	dist[start]=0;
	deque<int> que;
	que.push_back(start);

	while(que.size()){
		int here=que.front();
		que.pop_front();

		for(int i=0;i<graph[here].size();i++){
			int there=graph[here][i].destination;

			if(!visited[there]){
				visited[there]=true;

				if(there<here)
					dist[there]=dist[here]-graph[here][i].cost;
				else dist[there]=dist[here]+graph[here][i].cost;

				if(there==end){
					return dist[there];
				}

				que.push_back(there);

			}

		}
	}

	return -1;//can't reach destination

}



int main(){
	read();
	out<<bfs(x-1,y-1);
	return 0;
}
