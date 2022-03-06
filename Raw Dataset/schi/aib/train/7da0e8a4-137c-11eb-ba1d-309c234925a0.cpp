#include<fstream>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int N,V[30005],AIB[30005],Sol[30005];



void Initializare(){

    for(int i=1;i<=N;i++)

        AIB[i]=i&(-i);

}



int Query(int X){

    int S=0;

    for(int i=X;i>=1;i-=i&(-i))

        S=S+AIB[i];

    return S;

}



void Update(int X){

    for(int i=X;i<=N;i+=i&(-i))

        AIB[i]--;

}



int Search(int Val){

    int L=1,R=N;

    while(L<=R){

        int Mid=(L+R)/2;

        if(Query(Mid)>=Val){

            R=Mid-1;

        }

        else

            L=Mid+1;

    }

    return L;

}



int main(){

    fin>>N;

    for(int i=1;i<=N;i++){

        fin>>V[i];

    }

    Initializare();

    for(int i=N;i>=1;i--){

        int K=Search(V[i]);

        Sol[K]=i;

        Update(K);

    }

    for(int i=1;i<=N;i++)

        fout<<Sol[i]<<'\n';

}
