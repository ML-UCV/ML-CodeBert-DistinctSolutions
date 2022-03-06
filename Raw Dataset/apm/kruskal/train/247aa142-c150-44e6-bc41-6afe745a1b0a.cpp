#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>


using namespace std;



ifstream fi("apm.in");

ofstream fo("apm.out");



struct muchie

{

    int v1, v2, c;

};



int n,m;

muchie e[400000];

int p[200001];

int c[200001];



int cmp(muchie a, muchie b)

{

    return a.c<b.c;

}



int parinte(int vf)

{

    while(p[vf]!=vf)

        vf=p[vf];

    return vf;

}



stack <pair<int,int> > s;



int main()

{

    fi>>n>>m;



    for(int i=1;i<=n;i++)

    {

        p[i]=i;

        c[i]=1;

    }



    for(int i=0;i<m;i++)

    {

        fi>>e[i].v1>>e[i].v2>>e[i].c;

    }



    sort(e,e+m,cmp);



    int nrm=1;

    int rez=e[0].c;



    p[e[0].v2]=e[0].v1;

    c[e[0].v2]=2;



    s.push({e[0].v1,e[0].v2});



    int p1,p2;

    for(int i=1;i<m;i++)

    {

        if(nrm<n)

        {

            p1=parinte(e[i].v1);

            p2=parinte(e[i].v2);



            if(p1!=p2)

            {

                rez+=e[i].c;

                s.push({e[i].v1,e[i].v2});

                nrm++;



                if(c[p1]>c[p2])

                {

                    c[p1]+=c[p2];

                    p[p2]=p1;

                }

                else

                {

                    c[p2]+=c[p1];

                    p[p1]=p2;

                }

            }

        }

        else

            break;

    }



    fo<<rez<<'\n'<<n-1<<'\n';

    while(!s.empty())

    {

        fo<<s.top().first<<" "<<s.top().second<<'\n';

        s.pop();

    }



    fi.close();

    fo.close();

    return 0;

}
