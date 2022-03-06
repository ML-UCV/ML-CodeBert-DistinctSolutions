#include <fstream>
#include<algorithm>


using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");



int sef[200005];



struct ura{

    int x,y,cost;

}v[400005];



struct ura2{

    int x,y;

}v2[200005];



bool cmp(ura a,ura b){

    if(a.cost<b.cost)

        return true;

    return false;

}



int sefsuprem(int nod){

    if(sef[nod]==nod)

        return nod;

    else

        return sef[nod]=sefsuprem(sef[nod]);

}





void unire(int nod1, int nod2){

    int sef1, sef2;

    sef1=sefsuprem(nod1);

    sef2=sefsuprem(nod2);

    sef[sef2]=sef1;

}





int main(){

    int n,m,i,tip,x,y,add=0,suma=0;

    cin>>n>>m;

    for(i=1;i<=n;i++)

        sef[i]=i;



    for(int i=1;i<=m;i++)

        cin>>v[i].x>>v[i].y>>v[i].cost;





    sort(v+1,v+m+1,cmp);





    for(int i=1;add<n-1;i++){

        if(sefsuprem(v[i].x)!=sefsuprem(v[i].y)){

            unire(v[i].x,v[i].y);

            add++;

            suma+=v[i].cost;

            v2[add].x=v[i].x;

            v2[add].y=v[i].y;

        }

    }

    cout<<suma<<endl<<add<<endl;

    for(int i=1;i<=add;i++)

        cout<<v2[i].x<<" "<<v2[i].y<<endl;
    return 0;

}
