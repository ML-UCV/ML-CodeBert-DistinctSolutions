#include <stdio.h>
#include <algorithm>






using namespace std;



int n,m,x,y,o,i,j,timp,ma[2*105][2*105],a[2*105][2*105],viz[2*105];

int pot[2*105][2*105],bun[2*105][2*105],cate,scc[2*105][2*105],st[2*105];

int val[2*105],ma1[2*105][2*105];

int stiv[2*105];



int negat(int x) {

  if(x>n) return x-n;

    else return x+n;

}



void bfs(int nod) {

 for(int j=1;j<=2*105;j++) viz[j]=0;

    int q=1,p=1;

    stiv[1]=nod;

    viz[1]=1;

    while(q<=p) {

      for(int i=1;i<=a[stiv[q]][0];i++) {

          int n1=a[stiv[q]][i];

            if(!viz[n1]) {

             pot[nod][++pot[nod][0]]=n1;

                bun[nod][n1]=1;

                stiv[++p]=n1;

                viz[n1]=1;

            }

        }

        q++;

    }

}



void ca_viz(int nod) {

 viz[nod]=1;

    for(int i=1;i<=ma1[nod][0];i++) {

     if(!viz[ma1[nod][i]]) ca_viz(ma1[nod][i]);

    }

    st[++st[0]]=nod;

}



void sortare_topologica() {

 for(int i=1;i<=cate;i++) viz[i]=0;

    for(int i=1;i<=cate;i++)

      if(!viz[i]) ca_viz(i);

}



int main() {

 freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    scanf("%d %d\n",&n,&m);

    for(int i=1;i<=m;i++) {

     scanf("%d %d %d\n",&x,&y,&o);

        if(o==0) {

         ma[negat(x)][y]=1;

            ma[negat(y)][x]=1;

            a[negat(x)][++a[negat(x)][0]]=y;

            a[negat(y)][++a[negat(y)][0]]=x;

        }

        if(o==1) {

         ma[negat(x)][negat(y)]=1;

         ma[y][x]=1;

            a[negat(x)][++a[negat(x)][0]]=negat(y);

            a[y][++a[y][0]]=x;

        }

        if(o==2) {

         ma[x][y]=1;

         ma[negat(y)][negat(x)]=1;

            a[negat(y)][++a[negat(y)][0]]=negat(x);

            a[x][++a[x][0]]=y;

            }

        if(o==3) {

         ma[x][negat(y)]=1;

            ma[y][negat(x)]=1;

            a[x][++a[x][0]]=negat(y);

            a[y][++a[y][0]]=negat(x);

        }

    }

    for(int i=1;i<=2*n;i++) bfs(i);



    cate=0;

    for(int i=1;i<=2*n;i++) {

     int gata=0;

     for(int j=1;j<=cate;j++)

         if((bun[scc[j][1]][i]) && (bun[i][scc[j][1]])) {

    scc[j][++scc[j][0]]=i;

                gata=1;

                break;

            }

        if(!gata) {

         cate++;

            scc[cate][++scc[cate][0]]=i;

        }

    }

    for(int i=1;i<=cate;i++)

      for(int j=1;j<=cate;j++)

         if(i!=j) {

              int bagam=0;

                for(int k=1;k<=scc[i][0];k++) {

                 for(int k1=1;k1<=scc[j][0];k1++)

                     if(ma[scc[i][k]][scc[j][k1]]) {

                         bagam=1;

                            break;

                        }

                    if(bagam) break;

                }

                if(bagam)

                 ma1[i][++ma1[i][0]]=j;

            }



    sortare_topologica();



    for(int i=1;i<=st[0];i++) {

     int nod=st[i];

        for(int j=1;j<=scc[st[i]][0];j++) {

         nod=scc[st[i]][j];

            if(val[negat(nod)]==0) {

           val[nod]=1;

              val[negat(nod)]=2;

         }

        }

    }

    int cate1=0;

    for(int i=1;i<=n;i++) if(val[i]==1) cate1++;

    if(cate1==0) {

                 printf("%d\n",n);

                 for(int i=1;i<=n;i++) printf("%d\n",i);

                 return 0;

    }

    printf("%d\n",cate1);

    for(int i=1;i<=n;i++) if(val[i]==1) printf("%d\n",i);

    return 0;

}
