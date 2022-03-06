#include<fstream>
#include<vector>
#include<stack>


using namespace std;

ifstream cin("ctc.in");

ofstream cout("ctc.out");

stack < int > S;

vector<int> G[100005], GT[100005], CTC[100005];

int N, M, NrCTC;

int beenThere[100005];

void Read()

{

    cin >> N >> M;

    for (int i = 1; i <= M; i++)

    {

        int x, y;

        cin >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}

void DFSP(int Nod)

{

    beenThere[Nod] = 1;

    for (unsigned int i = 0; i < G[Nod].size(); i++)

    {

        int Vecin = G[Nod][i];

        if (!beenThere[Vecin])

            DFSP(Vecin);

    }

    S.push(Nod);

}

void DFSM(int Nod)

{

    beenThere[Nod] = 2;

    CTC[NrCTC].push_back(Nod);

    for (unsigned int i = 0; i < GT[Nod].size(); i++)

    {

        int Vecin = GT[Nod][i];

        if (beenThere[Vecin] == 1)

            DFSM(Vecin);

    }

}

void Solve()

{

    for (int i = 1; i <= N; i++)

        if (!beenThere[i])

            DFSP(i);

    while (!S.empty())

    {

        int Nod = S.top();

        if (beenThere[Nod] == 1)

        {

            NrCTC++;

            DFSM(Nod);

        }

        S.pop();

    }

}

void Print()

{

    cout << NrCTC << "\n";

    for (int i = 1; i <= NrCTC; i++)

    {

        for (unsigned int j = 0; j < CTC[i].size(); j++)

            cout << CTC[i][j] << " ";

        cout << "\n";

    }

}

int main()

{

    Read();

    Solve();

    Print();

    return 0;

}
