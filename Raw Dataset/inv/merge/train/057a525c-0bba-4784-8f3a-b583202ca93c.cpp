#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





int inversiuni(vector<int> &inversat,int stanga,int dreapta)

{

    if(stanga==dreapta)

        return 0;

    int mijloc=(stanga+dreapta)/2;



    int inv1=inversiuni(inversat,stanga,mijloc);

    int inv2=inversiuni(inversat,mijloc+1,dreapta);



    int inv3=0;

    vector<int>primul;

    vector<int>al_doilea;

    for(int i=stanga; i<=mijloc; i++)

    {

        primul.push_back(inversat[i]);



    }

    for(int i=mijloc+1; i<=dreapta; i++)

    {

        al_doilea.push_back(inversat[i]);



    }



    int x=stanga;

    int x1=0;

    int x2=0;

    while(x1!=primul.size()&&x2!=al_doilea.size())

    {



        if(al_doilea[x2]<primul[x1])

        {

            inv3+=primul.size()-x1;

            inversat[x]=al_doilea[x2];

            x++;

            x2++;

        }

        else

        {

            inversat[x]=primul[x1];

            x++;

            x1++;

        }

    }

    while(x1!=primul.size())

    {

        inversat[x]=primul[x1];

        x++;

        x1++;

    }

    while(x2!=al_doilea.size())

    {

        inversat[x]=al_doilea[x2];

        x++;

        x2++;

    }



    return (inv1+inv2+inv3)%9917;

}





int main()

{

    ifstream in("inv.in");

    ofstream out("inv.out");



    int nr_elemente;

    in>>nr_elemente;

    vector<int> elemente;

    for(int i=0; i<nr_elemente; i++)

    {

        int aux;

        in>>aux;

        elemente.push_back(aux);

    }



    out<<inversiuni(elemente,0,elemente.size()-1);



    in.close();

    out.close();

    return 0;

}
