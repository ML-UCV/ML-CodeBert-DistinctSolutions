#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



struct muchie

{

    int x,y,val;

};

int tata[200001], h[200001];

int Reprez(int u)

{

    while(tata[u]!=0)

        u=tata[u];

    return u;

}



void Reun(int ru, int rv)

{



    if(h[ru]>h[rv])

        tata[rv]=ru;

    else

    {

        tata[ru]=rv;

        if(h[ru]==h[rv])

            h[rv]+=1;

    }

}





int main()

{



    int n, m;

    fin>>n>>m;



    vector<muchie> muchii;



    while(m--)

    {

        muchie m;

        fin>>m.x>>m.y>>m.val;

        muchii.push_back(m);

    }

    sort(muchii.begin(),muchii.end(),[](muchie a, muchie b)

    {

        return a.val<b.val;

    });

    vector<muchie> rez;

    int cost=0;

    for(auto m : muchii)

    {

        int rx=Reprez(m.x),ry=Reprez(m.y);

        if((rx==0&&ry==0)||(rx!=ry))

        {

            Reun(rx,ry);



            cost += m.val;

            rez.push_back(m);

        }

    }

    fout<<cost<<"\n";

    fout<<rez.size()<<"\n";

    for(auto m: rez)

    {

        fout<<m.x<<" "<<m.y<<"\n";

    }

    return 0;

}
