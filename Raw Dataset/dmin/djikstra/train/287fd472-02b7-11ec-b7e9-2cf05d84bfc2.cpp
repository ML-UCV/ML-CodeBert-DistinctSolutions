# include <stdio.h>
# include <math.h>
# include <stdlib.h>
typedef struct {long int n;long int v[2000 +1];long int index[2000 +1],roads[2000 +1];} HEAP;

typedef long double TIPD;

typedef struct NOD {long int nod; TIPD dist; NOD* next;} NOD;

typedef struct LISTA {NOD *begin,*end;};

LISTA ladiac[2000 +1];

TIPD raza[2000 +1];

long int n,m;



TIPD modul(TIPD a) {if (a<0) return -a; return a;}

long int mai_mare(TIPD a, TIPD b)

     {

     if (b==-1) return 0;

     if (a==-1) return 1;

     if (a-b>1e-11) return 1;

     return 0;

     }

long int mai_mic(TIPD a, TIPD b)

     {

     if (a==-1) return 0;

     if (b==-1) return 1;

     if (a-b<-1e-11) return 1;

     return 0;

     }

long int egal(TIPD a, TIPD b)

     {

     if (a==-1 || b==-1) return 0;

     if (modul((a-b))<=1e-11) return 1;

     return 0;

     }



void test(HEAP &a);



void rise_heap(HEAP &a, long int i)

{

     long int auxf;

     while (i/2 && mai_mic(raza[a.v[i]],raza[a.v[i/2]]))

           {

            auxf=a.v[i];a.v[i]=a.v[i/2];a.v[i/2]=auxf;

            a.index[a.v[i]]=i;

            a.index[a.v[i/2]]=i/2;

            i/=2;

            }

}



void submerge_heap(HEAP &a, long int i)

{

     long int min=0,auxi;long int auxf;

     while (2*i<=a.n)

           {

           min=i;

           if (2*i <=a.n && mai_mic(raza[a.v[2*i ]],raza[a.v[min]])) min=2*i;

           if (2*i+1<=a.n && mai_mic(raza[a.v[2*i+1]],raza[a.v[min]])) min=2*i+1;

           if (min==i) break;

           auxf=a.v[min];a.v[min]=a.v[i];a.v[i]=auxf;

           a.index[a.v[min]]=min;a.index[a.v[i]]=i;

           i=min;

           }

}



void insert_heap(HEAP &a, long int nod)

{

     a.n++;

     a.v[a.n]=nod;



     a.index[nod]=a.n;

     rise_heap(a,a.n);

}



long int extract_heap(HEAP &a)

{

     long int sol;

     sol=a.v[1]; a.index[sol]=0;



     a.v[1]=a.v[a.n]; a.v[a.n]=0; a.index[a.v[1]]=1; a.n--;



     submerge_heap(a,1);



     return sol;

}



void create_heap(HEAP &a)

{

     long int i;

     NOD *p;

     a.n=0;

     raza[1]=0;

     a.roads[1]=1;

     a.index[1]=0;

     for (i=2;i<=n;i++)

         {

         raza[i]=-1;

         a.roads[i]=0;

         }

     p=ladiac[1].begin;

     while (p)

           {

           raza[(*p).nod]=(*p).dist;

           a.roads[(*p).nod]=1;

           p=(*p).next;

           }



     for (i=2;i<=n;i++)

         insert_heap(a,i);





}



void insert_list(LISTA &a, long int nod, TIPD dist)

{

     NOD* p=(NOD*) malloc (sizeof(NOD));

     (*p).dist=dist;

     (*p).nod=nod;

     (*p).next=NULL;



     if (a.begin==NULL)

        {

        a.begin=a.end=p;

        }

     else

        {

        (*(a.end)).next=p;

        a.end=p;

        }

}



void citire()

{

     FILE *f=fopen("dmin.in","r");

     fscanf(f,"%ld%ld",&n,&m);

     long int i,aa,bb;long int dist;

     for (i=1;i<=m;i++)

         {

         fscanf(f,"%ld%ld%ld",&aa,&bb,&dist);

         insert_list(ladiac[aa],bb,(long double)log10((long double)dist));

         insert_list(ladiac[bb],aa,(long double)log10((long double)dist));

         }

     fclose(f);

}



void scrie(HEAP &a)

{

     FILE *g=fopen("dmin.out","w");

     long int i;

     for (i=2;i<=n;i++)

         {

         if (i>2) fprintf(g," ");

         fprintf(g,"%ld",a.roads[i]);

         }

     fprintf(g,"\n");

     fclose(g);

}



long int empty(HEAP &a)

{

     if (a.n==0) return 1;

     return 0;

}



void update(HEAP &a, long int nod)

{

     NOD *p;

     p=ladiac[nod].begin;

     while (p)

           {



           if (egal(raza[(*p).nod],raza[nod]+(*p).dist))

                {

                a.roads[(*p).nod]+=a.roads[nod];

                a.roads[(*p).nod]%=104659;

                }

           else if (mai_mare(raza[(*p).nod],raza[nod]+(*p).dist))

              {

              raza[(*p).nod]=raza[nod]+(*p).dist;

              a.roads[(*p).nod]=a.roads[nod];

              a.roads[(*p).nod]%=104659;



              if (a.index[(*p).nod]) rise_heap(a,a.index[(*p).nod]);

              }



           p=(*p).next;

           }

}



void dijkstra(HEAP &a)

{
     long int nod;



     while (!empty(a))

           {

           nod=extract_heap(a);



           update(a,nod);





           }

}





int main()

{

    HEAP a;

    citire();

    create_heap(a);



    dijkstra(a);

    scrie(a);

    return 0;

}



void test(HEAP &a)

{

     long int i;

     for (i=1;i<=n;i++)

         printf("%ld === v[i]=%ld\tindex[i]=%ld\troads[i]=%ld\traza[i]=%f\n",i,a.v[i],a.index[i],a.roads[i],raza[i]);

     getchar();

}
