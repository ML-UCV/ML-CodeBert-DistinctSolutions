#include <iostream>
#include <fstream>
#include<math.h>
#include<vector>
#include <iomanip>
#include <algorithm>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");





struct punct{

    int x,y;

};







int comparX(const punct &A, const punct &B)

{

    return A.x<B.x;

}

int comparY(const punct &A, const punct &B)

{

    return A.y<B.y;

}



double dist(punct A,punct B)

{

    double x = A.x - B.x;

    double y = A.y - B.y;

    double dist;

    dist = pow(x, 2) + pow(y, 2);

    dist = sqrt(dist);

    return dist;

}

double distantaMinima(int stg,int dr,vector<punct> &V,vector<punct> &W)

{





    if((dr-stg)==1)

       return 2147483647;



    else if((dr-stg)==2)

         {

         if (W[stg].y > W[stg + 1].y)

            swap (W[stg], W[stg + 1]);

            return dist (V[0],V[1]);

        }



    int mediana;

    double stg_minim,dr_minim, v_minim;

    mediana=(stg+dr)/2;

    stg_minim=distantaMinima(stg,mediana,V,W);

    dr_minim=distantaMinima(mediana,dr,V,W);

    v_minim=min(stg_minim,dr_minim);

    vector <punct> aux(dr-stg);

    merge(W.begin()+stg,W.begin()+mediana,W.begin()+mediana,W.begin()+dr,aux.begin(),comparY);

    copy(aux.begin(),aux.begin()+(dr-stg),W.begin()+stg);



    vector <punct> b;

    for (int i = stg; i < dr; ++i)

    {

        if (abs(W[i].x - V[mediana].x) <= v_minim)

            b.push_back(W[i]);

    }





    double minim_t = v_minim;

    for (int i = 0; i<b.size(); ++i)

        for (int j = i + 1; j < b.size() && b[j].y - b[i].y <= v_minim; ++j)

             minim_t = min(minim_t, dist(b[i], b[j]));



    return minim_t;

}



int main()

{

    int n;

    fin>>n;

    vector <punct>V(n),W(n);

     for(int i=0;i<n;i++)

        fin>>V[i].x>>V[i].y;

    sort(V.begin(),V.end(),comparX);

    W=V;

    fout<<std::fixed<<setprecision(6)<<distantaMinima(0, V.size(), V, W)<<'\n';

    fin.close();

    fout.close();

    return 0;

}
