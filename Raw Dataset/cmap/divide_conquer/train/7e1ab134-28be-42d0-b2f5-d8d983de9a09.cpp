#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;



struct PUNCT

{

    double x, y;

};





PUNCT p[99999], aux[99999], inter[99999], A, B;



double distanta(PUNCT a, PUNCT b)

{

    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));

}



bool cmpX(PUNCT a, PUNCT b)

{

    return a.x < b.x;

}



bool cmpY(PUNCT a, PUNCT b)

{

    return a.y < b.y;

}



double dist_min(int left, int right)

{

    if(right - left + 1 == 3)

    {

        sort(p + left, p + right, cmpY);

        double d1 = distanta(p[left], p[left + 1]);

        double d2 = distanta(p[left + 1], p[left + 2]);

        double d3 = distanta(p[left], p[left + 2]);

        double minim = d1;

        A = p[left];

        B = p[left + 1];

        if(d2 < minim)

        {

           minim = d2;

           A = p[left + 1];

           B = p[left + 2];

        }

        if(d3 < minim)

        {

            A = p[left];

            B = p[left + 2];

            minim = d3;

        }

        return minim;

    }

    if(right - left + 1 == 2)

    {

        if(p[left].y > p[left + 1].y)

            swap(p[left], p[left + 1]);

        A = p[left];

        B = p[left + 1];

        return distanta(p[left], p[left + 1]);

    }

    else

    {

        int mijloc = (left + right) / 2;

        double mediana = p[mijloc].x;

        double delta = min(dist_min(left, mijloc), dist_min(mijloc + 1, right));

        int nr = 0, i, j, k;





        i = left;

        k = left;

        j = mijloc + 1;

        while(i <= mijloc && j <= right)

            if(p[i].y < p[j].y)

                aux[k++] = p[i++];

            else aux[k++] = p[j++];

        while(i <= mijloc)

            aux[k++] = p[i++];

        while(j <= right)

            aux[k++] = p[j++];



        for(i = left; i <= right; i++)

        {

            p[i] = aux[i];

            if(p[i].x - mediana <= delta && p[i].x - mediana >= -delta)

                    inter[++nr] = p[i];

        }



        for(i = 1; i <= nr; i++)

        {

            int nr_vecini = min(nr, i + 7);

            for(j = i + 1; j <= nr_vecini; j++)

                    if(distanta(inter[i], inter[j]) < delta)

                    {

                        delta = distanta(inter[i],inter[j]);

                        A = inter[i];

                        B = inter[j];

                    }

        }

        return delta;

    }

}



int main()

{

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");

    int n, i;

    fin >> n;

    for(i = 1; i <= n; i++)

        fin >> p[i].x >> p[i].y;

    sort(p + 1 , p + n + 1, cmpX);

    fout << setprecision(6) << fixed << dist_min(1, n);

    return 0;

}
