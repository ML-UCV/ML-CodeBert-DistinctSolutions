#include <bits/stdc++.h>






using namespace std;



ifstream in("party.in");



ofstream out("party.out");



int n,m;



int vine[105],a[1005],b[1005],c[1005];



int main()



{



    in >> n >> m;



    for(int i=1; i<=n; i++) vine[i]=1;



    for(int i=1; i<=m; i++)



    {



        in >> a[i] >> b[i] >> c[i];



    }



    int ok=0;



    while(!ok)



    {



        ok=1;



        for(int i=1; i<=m; i++)



        {



            switch(c[i]){



                case 0:



                    if(vine[a[i]]==0 && vine[b[i]]==0)



                    {



                        ok=0;



                        int p = rand()%2;



                        vine[a[i]]=p;



                        vine[b[i]]=1-p;



                    }



                    break;



                case 1:



                    if(vine[a[i]]==0 && vine[b[i]]==1)



                    {



                        ok=0;



                        vine[b[i]]=0;



                    }



                    break;



                case 2:



                    if(vine[a[i]]==1 && vine[b[i]]==0)



                    {



                        ok=0;



                        vine[a[i]]=0;



                    }



                    break;



                case 3:



                    if(vine[a[i]]==1 && vine[b[i]]==1)



                    {



                        ok=0;



                        int p = rand()%2;



                        vine[a[i]]=p;



                        vine[b[i]]=1-p;



                    }



                    break;



            }



        }



    }



    int cnt=0;



    for(int i=1; i<=n; i++) if(vine[i]) cnt++;



    out << cnt << '\n';



    for(int i=1; i<=n; i++) if(vine[i]) out << i << '\n';



}
