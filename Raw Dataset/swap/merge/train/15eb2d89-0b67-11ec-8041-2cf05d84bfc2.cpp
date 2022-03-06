#include <fstream>
#include <vector>





using namespace std ;
int n,sol;
int aint[4*50004];
inline void Update(const int node,const int Left,const int Right,const int pos)
{
    if(Left==Right)
    {
        aint[node] = 1;
        return ;
    }
    int Middle = ( Left + Right ) >>1;
    if(pos<=Middle)
        Update(2*node,Left,Middle,pos);
    else
        Update(2*node+1,Middle+1,Right,pos);
    aint[node] = aint[2*node] + aint[2*node+1];
}
inline void Query(const int node,const int Left,const int Right,const int A,const int B)
{
    if(A <= Left && Right <= B)
    {
        sol += aint[node];
        return;
    }
    int Middle = ( Left + Right ) >>1;
    if(A<=Middle)
        Query(2*node,Left,Middle,A,B);
    if(Middle < B)
        Query(2*node+1,Middle+1,Right,A,B);
}
int fr0[300],fr1[300], ind[300] , a[50004];
vector < int > pos[300];
char s0[50004],s1[50004];
inline void Read()
{
    ifstream f("swap.in");
    f>> (s0+1) >> (s1+1);
    f.close();
}
inline void Solve()
{
    int i;
    for(i = 1;s0[i] ;++i)
        ++fr0[s0[i]];
    for(i = 1;s1[i] ;++i)
        ++fr1[s1[i]],
        pos[s1[i]].push_back(i);
    n = i-1;
    for(i = 'a';i <= 'z'; ++i)
        if(fr0[i]!=fr1[i])
        {
            sol = -1;
            return ;
        }
    for(i = 1;i <= n; ++i)
        a[i] = pos[s0[i]][ind[s0[i]]++];
    for(i = 1;i <= n; ++i)
    {
        if(a[i]!=n)
            Query(1,1,n,a[i]+1,n);
        Update(1,1,n,a[i]);
    }
}

inline void Write()
{
    ofstream g("swap.out");
    g<<sol<<"\n";
    g.close();
}

int main()
{
    Read();
    Solve();
    Write();
    return 0;
}
