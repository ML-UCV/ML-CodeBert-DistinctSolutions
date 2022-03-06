#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <utility>


using namespace std;


int n,m;

const int MAX_M = 1100;
const int MAX_N = 110;

int val[MAX_N];
int type[MAX_M];
pair<int,int> which[MAX_M];

bool eval(int ind)
{
    int x = which[ind].first, y = which[ind].second;
    x = val[x],y = val[y];
    if(type[ind] == 0){
        return x || y;
    }else if(type[ind] == 1){
        return (!x && !y) || x;
    }else if(type[ind] == 2){
        return (x && y) || !x;
    }else{
        return !(x && y);
    }
}


int main()

{

    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);

    int i,x;

    scanf("%d %d",&n,&m);
    srand(time(NULL));

    for(i = 1 ; i <= m ; ++ i)
        scanf("%d %d %d",&which[i].first,&which[i].second,&type[i]);

    while(true){
        for(i = 1 ; i <= m ; ++ i){
            if(eval(i) == 0){
                x = rand() & 1;
                if(x == 0)
                    val[which[i].first] ^= 1;
                else val[which[i].second] ^= 1;
                break;
            }
        }
        if(i == m + 1){
            x = 0;
            for(i = 1 ; i <= n ; ++ i)
                if(val[i])
                    ++x;
            printf("%d\n",x);
            for(i = 1 ; i <= n ; ++ i)
                if(val[i])
                    printf("%d\n",i);
            return 0;
        }
    }
}
