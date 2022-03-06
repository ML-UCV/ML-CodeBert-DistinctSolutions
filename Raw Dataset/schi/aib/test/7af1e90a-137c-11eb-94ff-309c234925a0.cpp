#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



class AIB

{

public:

    AIB(int n)

    {

        this->n = n;

        v.resize(n+1);

    }

    void Add(int ind, int val)

    {

        while(ind <= n)

        {

            v[ind] += val;

            ind += ind & (-ind);

        }

    }

    int Query(int dr)

    {

        int ret = 0;

        while(dr >= 1)

        {

            ret += v[dr];

            dr -= dr & (-dr);

        }

        return ret;

    }

    int GetFirstPos(int sum)

    {

        int ret;

        int step;

        for(step = 1; step < n; step <<= 1);

        for(ret = 0; step > 0; step >>= 1)

            if(ret + step < n && sum > v[ret+step])

                ret += step, sum -= v[ret];

        return ret+1;

    }

private:

    int n;

    vector<int> v;

};



int main()

{

    ifstream in("schi.in");

    int n;

    in >> n;

    vector<int> v(n+1);

    AIB aib(n);

    for(int i = 1; i <= n; ++i)

    {

        in >> v[i];

        aib.Add(i, 1);

    }

    in.close();



    vector<int> rasp(n+1);

    for(int i = n; i >= 1; --i)

    {

        int pos = aib.GetFirstPos(v[i]);

        rasp[pos] = i;

        aib.Add(pos, -1);

    }



    ofstream out("schi.out");

    for(int i = 1; i <= n; ++i)

        out << rasp[i] << "\n";

    out.close();

    return 0;

}
