#include <fstream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int NMAX = 100001;



vector<int>A[NMAX] , tA[NMAX];

int N , E , StronglyConnectedComponents = 0;



void Read(){

    int x , y;

    fin>>N>>E;

    for(int i = 1 ; i<=E ; i++){

        fin>>x>>y;

        A[x].push_back(y);

        tA[y].push_back(x);

    }

}



stack<int>s;



void DFSstack(int Node , bool viz[NMAX])

{

    viz[Node] = true;

    for(vector<int>::iterator it = A[Node].begin() ; it!=A[Node].end() ; it++){

        if(viz[*it] == false)

            DFSstack(*it , viz);

    }



    s.push(Node);

}



void DFStranspose(int Node , int viz[]){

    viz[Node] = StronglyConnectedComponents;

    for(vector<int>::iterator it = tA[Node].begin() ; it != tA[Node].end() ; it++){

        if(viz[*it] == 0)

            DFStranspose(*it , viz);

    }

}



vector<int> Answer[NMAX];





int main()

{

Read();



    bool viz[NMAX];

    memset(viz , false , sizeof(viz));

    for(int i = 1 ; i<=N ;i++){

        if(viz[i] == false)

            DFSstack(i , viz);

    }



    int x , viz1[NMAX];

    memset(viz1 , 0 , sizeof(viz1));



    while(!s.empty()){

        x = s.top();

        s.pop();

        if(viz1[x] == 0){

            StronglyConnectedComponents++;

            DFStranspose(x , viz1);

        }

    }



    for(int i = 1 ; i<=N ; i++){

        Answer[ viz1[i] ].push_back(i);

    }

    fout<<StronglyConnectedComponents<<'\n';

    for(int i = 1 ; i<=StronglyConnectedComponents ; i++){



        for(vector<int>::iterator it = Answer[i].begin() ; it!=Answer[i].end() ; it++ ){

            fout << *it<<' ';

        }

        fout<<'\n';

    }

    return 0;

}
