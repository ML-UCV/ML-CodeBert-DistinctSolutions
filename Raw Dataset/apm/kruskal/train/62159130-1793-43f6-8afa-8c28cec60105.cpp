#include <fstream>
#include <queue>


using namespace std;

ifstream in ("apm.in");

ofstream out("apm.out");



bool fr[200001];

int t[200005], h[200005];



int varf(int x)

{

 while (x != t[x])

  x = t[x];

 return x;

}



void unire(int x, int y)

{

 if (h[x] < h[y])

  t[x] = y;

 else if (h[y] < h[x])

  t[y] = x;

 else

 {

  t[x] = y;

  ++h[y];

 }

}



struct MUCHIE

{

    int x,y,c;

}temp,temp2;



struct mycomp

{

    bool operator()(MUCHIE &a,MUCHIE &b)

    {

        if(a.c>b.c)

            return 1;

        else

            return 0;

    }

};



int n,m;

priority_queue<MUCHIE,vector<MUCHIE>,mycomp> pq;

queue<MUCHIE> q;



int main()

{

    int nr,cost=0,i;

    in>>n>>m;



    nr=n-1;



    for (i = 1; i <= n; ++i)

        t[i] = i, h[i] = 1;



    for(i = 0; i < m; i++)

    {

        in>>temp.x>>temp.y>>temp.c;

        pq.push(temp);

    }



    while(nr && !pq.empty())

    {

        temp=pq.top();

        temp2=temp;

        temp.x=varf(temp.x);

        temp.y=varf(temp.y);

        pq.pop();



        if (temp.x != temp.y)

        {

            unire(temp.x, temp.y);

            q.push(temp2);

            cost += temp.c;

            nr--;

        }

    }



    out<<cost<<'\n'<<n-1<<'\n';



    while(!q.empty())

    {

        temp=q.front();

        out<<temp.x<<" "<<temp.y<<'\n';

        q.pop();

    }

    return 0;

}
