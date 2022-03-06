#include <iomanip>
#include <fstream>
#include<algorithm>
#include<cmath>


using namespace std;



struct punct

{

    int x, y;

};



punct P[100001];

int N;



ifstream f("cmap.in");

ofstream g("cmap.out");



bool comp(const punct &A, const punct &B)

{

    return A.x < B.x;

}



long long dist2(const punct &A, const punct &B)

{

    long long dx = A.x - B.x;

    long long dy = A.y - B.y;

    return dx * dx + dy * dy;

}



double solutie()

{

    long long dmin = 0x7FFFFFFFFFFFFFFFLL;

    for(int i = 1; i <= N; i++)

        for(int j = i + 1; j <= i + 7 && j <= N; j++)

        {

            long long d = dist2(P[i], P[j]);

            if(d < dmin) dmin = d;

        }

    return sqrt(dmin);

}



int main()

{

    f >> N;

    for(int i = 1; i <= N; i++)

        f >> P[i].x >> P[i].y;

    sort(P + 1, P + N + 1, comp);

    g << fixed << setprecision(6) << solutie();

    return 0;

}
