#include <fstream>
#include <vector>
#include <cstring>
using namespace std;



ifstream f ("strmatch.in");

ofstream g ("strmatch.out");



vector <int> s;



int N, M, x1, x2, y1, y2, power1, power2;



char A[2000002];

char B[2000002];



int main()

{

    f.getline(A,2000002);

    f.getline(B,2000002);



    N = strlen(A);

    M = strlen(B);



    if (N > M)

    {

        g << 0 << '\n';

        return 0;

    }



    for (int i = 0; i < N; ++ i )

    {

        x1 = ((x1 * 127) % 10003 + (A[ i ] - '0')) % 10003;

        x2 = ((x2 * 131) % 666013 + (A[ i ] - '0')) % 666013;

        y1 = ((y1 * 127) % 10003 + (B[ i ] - '0')) % 10003;

        y2 = ((y2 * 131) % 666013 + (B[ i ] - '0')) % 666013;

    }



    power1 = power2 = 1;

    for (int i = 1; i < N; ++ i )

    {

        power1 = (power1 * 127) % 10003;

        power2 = (power2 * 131) % 666013;

    }



    if (x1 == y1 && x2 == y2)

    {

        s.push_back(0);

    }



    for (int i = N; i < M; ++ i )

    {

        y1 = ((y1 - (power1 * (B[i - N] - '0')) % 10003 + 10003) * 127 + (B[i] - '0')) % 10003;

        y2 = ((y2 - (power2 * (B[i - N] - '0')) % 666013 + 666013) * 131 + (B[i] - '0')) % 666013;



        if (y1 == x1 && y2 == x2)

        {

            s.push_back(i - N + 1);

        }

    }



    g << s.size() << '\n';



    for (int i = 0; i < 1000 && i < s.size(); ++ i )

        g << s[i] << " ";



    return 0;

}
