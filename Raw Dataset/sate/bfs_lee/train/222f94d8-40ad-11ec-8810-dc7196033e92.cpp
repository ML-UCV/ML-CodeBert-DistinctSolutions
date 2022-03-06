#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int nSate, nMuchii, startNod, stopNod, tempNod1, tempNod2, tempD;
vector < pair<int, int> > graf[30001];
int distNod[30001];
bool parcurs[30001];
queue < int > lee;
ifstream f("sate.in");
ofstream g("sate.out");

void read(){
    f>>nSate>>nMuchii>>startNod>>stopNod;

    for(int i = 0; i<nMuchii; i++) {
        f>>tempNod1>>tempNod2>>tempD;
        graf[tempNod1].push_back({tempNod2, tempD});
        graf[tempNod2].push_back({tempNod1, tempD});
    }
}




void SRCH(int x)
{
    int goThrough = 0, current, nodCurrent, distCurrent;
    lee.push(x);

    while( !lee.empty() ){
        current = lee.front();
        lee.pop();
        while(goThrough < graf[current].size()){

            nodCurrent = graf[current][goThrough].first;
            distCurrent = graf[current][goThrough].second;

            if(!parcurs[nodCurrent]){
                parcurs[nodCurrent] = true;

                lee.push(nodCurrent);

                if(current > nodCurrent)
                    distNod[nodCurrent] = distNod[current] - distCurrent;
                else
                    distNod[nodCurrent] = distNod[current] + distCurrent;

            }
            ++goThrough;
        }
        goThrough = 0;
    }
}

int main()
{


    read();
    SRCH(startNod);

    cout<<distNod[stopNod];
    g<<distNod[stopNod];



    return 0;
}
