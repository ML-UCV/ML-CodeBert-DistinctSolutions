#include <bits/stdc++.h>




using namespace std;

typedef long long LL;



const LL INF = 4e18;



struct Point

{

    LL x;

    LL y;



    void operator=(const Point &other)

    {

        x = other.x;

        y = other.y;

    }

};



Point xVector[100000 + 5 + 5], yVector[100000 + 5 + 5];



bool xCmp(Point a, Point b)

{

    return (a.x < b.x);

}



bool yCmp(Point a, Point b)

{

    return (a.y < b.y);

}



LL dist(const Point &a, const Point &b)

{

    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

}



void mergeVectorY(int st, int mij, int dr)

{

    vector<Point>aux;



    int i = st;

    int j = mij + 1;



    while(i <= mij && j <= dr)

        if(yVector[i].y == yVector[j].y)

        {

            if(yVector[i].x < yVector[j].x)

            {

                aux.push_back(yVector[i]);

                i++;

            }

            else

            {

                aux.push_back(yVector[j]);

                j++;

            }

        }

        else

        {

            if(yVector[i].y < yVector[j].y)

            {

                aux.push_back(yVector[i]);

                i++;

            }

            else

            {

                aux.push_back(yVector[j]);

                j++;

            }

        }



    while(i <= mij)

    {

        aux.push_back(yVector[i]);

        i++;

    }



    while(j <= dr)

    {

        aux.push_back(yVector[j]);

        j++;

    }



    for(int i = 0; i < aux.size(); i++)

        yVector[st + i] = aux[i];

}



LL solve(int st, int dr)

{

    if(st >= dr)return INF;

    if(dr == st + 1)

    {

        if(yVector[st].y > yVector[dr].y || (yVector[st].y == yVector[dr].y && yVector[st].x > yVector[dr].x))

            swap(yVector[st], yVector[dr]);



        return dist(xVector[st], xVector[dr]);

    }



    int mij = (st + dr) >> 1;

    LL best = min(solve(st, mij), solve(mij + 1, dr));



    mergeVectorY(st, mij, dr);



    vector<Point>rectangle;



    for(int i = st; i <= dr; i++)

        if(abs(yVector[i].x - xVector[mij].x) < best)rectangle.push_back(yVector[i]);



    if(rectangle.size() == 0)rectangle.push_back({0, 0});



    for(int i = 0; i < rectangle.size() - 1; i++)

    {

        for(int j = i + 1; j < rectangle.size() && j - i < 8; j++)

        {



            best = min(best, dist(rectangle[i], rectangle[j]));

        }



    }



    return best;

}



int main()

{

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");





    fin.tie(0);

    fout.tie(0);

    srand(time(NULL));



    int n;



    fin >> n;



    for(int i = 1; i <= n; i++)

        fin >> xVector[i].x >> xVector[i].y;



    sort(xVector + 1, xVector + 1 + n, xCmp);



    for(int i = 1; i <= n; i++)

        yVector[i] = xVector[i];



    fout << fixed << setprecision(6) << sqrt(solve(1, n));



    fin.close();

    fout.close();



    return 0;

}
