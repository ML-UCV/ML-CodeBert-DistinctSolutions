#include <bits/stdc++.h>

#define MaximumNodes 30005
#define mp std::make_pair
#define Distance second
#define Node first

std::ifstream InFile("sate.in");
std::ofstream OutFile("sate.out");


int N, M, X, Y;
// Assuming no data duplicates
std::vector <std::pair <int, int>> Adj[MaximumNodes];
// Distance[i] - distance from X to i
int Distance[MaximumNodes];

// We'll start a BFS from the leftmost given starting index (it'll be X), updating Distance[] on the way
// using the fact that if x = distance from i to j given in the data entry,
// Distance[i] = Distance[j] - distance (j>i) or Distance[j] + distance (i < j)
std::queue <int> BFSQueue;

void ComputeDistance() {
    BFSQueue.push(X);

    while(!BFSQueue.empty()) {
        int Index = BFSQueue.front();
        BFSQueue.pop();

        for (auto Relationship : Adj[Index]) {
            if(Distance[Relationship.Node] && Relationship.Node != X);  //Distance is known already
            else {
                Distance[Relationship.Node] = Distance[Index] + Relationship.Distance;
                if(Relationship.Node == Y) return;

                BFSQueue.push(Relationship.Node);
            }

        }
    }
}

void Initialise() {
    if(X > Y) std::swap(X, Y);
}


void Citire() {
    InFile >> N >> M >> X >> Y;
    X--, Y--;

    for (int i=0, x, y, dist; i<M; i++) {
        InFile >> x >> y >> dist;
        // Because I can
        x--, y--;
        Adj[x].push_back(mp(y, dist));
        Adj[y].push_back(mp(x, -dist));
    }
}

void Rezolvare() {
    Initialise();

    ComputeDistance();

    OutFile << Distance[Y];
}

int main()
{
    Citire();
    Rezolvare();

    return 0;
}
