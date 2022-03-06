#include<cstdio>
#include<vector>


using namespace std;



const int NMAX = 100+5;

const int MMAX = 1000+5;



void Read(),Solve(),Print();



int N,M,Top,NrCTC;

vector<int> V[2*NMAX];



vector<int> W[2*NMAX];



bool Viz[2*NMAX];



int TSort[2*NMAX];

int Comp[2*NMAX];



int Opus[2*NMAX];

int Sol[NMAX];

vector<int> CTC[2*NMAX];

vector<int> G[2*NMAX];



void SortareTopologica(int nod)

{





    vector<int>::iterator it;

    (Viz+NMAX)[nod]=1;

    for(it=(V+NMAX)[nod].begin(); it!=(V+NMAX)[nod].end(); it++)

    {

        if((Viz+NMAX)[*it]) continue;

        SortareTopologica(*it);

    }

    TSort[Top--]=nod;

}



void DFS(int nod)

{





    vector<int>::iterator it;

    (Viz+NMAX)[nod]=0;

    for(it=(W+NMAX)[nod].begin(); it!=(W+NMAX)[nod].end(); it++)

    {

        if(!(Viz+NMAX)[*it]) continue;

        DFS(*it);

    }

    CTC[Top].push_back(nod);

    (Comp+NMAX)[nod]=Top;

}



void ComponenteTareConexe()

{

    int i,x;



    Top=2*N;



    for(i=-N; i<=N; i++)

    {

        if(!i) continue;

        if((Viz+NMAX)[i]) continue;

        SortareTopologica(i);

    }



    for(i=1; i<=2*N; i++)

    {

        x=TSort[i];

        if(!(Viz+NMAX)[x]) continue;

        Top++;

        DFS(x);

    }



    NrCTC=Top;

}



void ConstruiesteGraf()

{







    int i,x;

    vector<int>::iterator it,jt;



    for(i=1; i<=NrCTC; i++)

    {

        for(it=CTC[i].begin(); it!=CTC[i].end(); it++)

        {

            x=*it;

            for(jt=(V+NMAX)[x].begin(); jt!=(V+NMAX)[x].end(); jt++)

            {

                if((Comp+NMAX)[*jt]==i) continue;

                G[i].push_back((Comp+NMAX)[*jt]);

            }

        }

    }



    for(i=1; i<=N; i++)

    {

        Opus[(Comp+NMAX)[i]]=(Comp+NMAX)[-i];

        Opus[(Comp+NMAX)[-i]]=(Comp+NMAX)[i];

    }

}



void SorteazaTopologic(int nod)

{





    vector<int>::iterator it;

    (Viz+NMAX)[nod]=1;

    for(it=G[nod].begin(); it!=G[nod].end(); it++)

    {

        if((Viz+NMAX)[*it]) continue;

        SorteazaTopologic(*it);

    }

    TSort[Top--]=nod;

}



int main()

{

    Read();

    Solve();

    Print();



    return 0;

}



void Read()

{

    int x,y,z;



    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);



    scanf("%d%d",&N,&M);



    for(; M; --M)

    {

        scanf("%d%d%d",&x,&y,&z);



        if(z==1) y=-y;

        else if(z==2) x=-x;

        else if(z==3) x=-x,y=-y;
        (V+NMAX)[-x].push_back(y);

        (V+NMAX)[-y].push_back(x);

        (W+NMAX)[y].push_back(-x);

        (W+NMAX)[x].push_back(-y);

    }

}



void Solve()

{

    int i;

    vector<int>::iterator it;



    ComponenteTareConexe();



    ConstruiesteGraf();



    Top=NrCTC;



    for(i=1; i<=NrCTC; i++)

    {

        if((Viz+NMAX)[i]) continue;

        SorteazaTopologic(i);

    }



    for(i=1; i<=NrCTC; i++)

    {

        if(!(Viz+NMAX)[i]) continue;

        for(it=CTC[i].begin(); it!=CTC[i].end(); it++)

            if(*it < 0) Sol[-(*it)]=1;

        (Viz+NMAX)[i]=0;

        (Viz+NMAX)[Opus[i]]=0;

    }

}



void Print()

{

    int i,ans=0;

    for(i=1; i<=N; i++)

        ans+=Sol[i];

    printf("%d\n",ans);

    for(i=1; i<=N; i++)

        if(Sol[i]) printf("%d\n",i);

}
