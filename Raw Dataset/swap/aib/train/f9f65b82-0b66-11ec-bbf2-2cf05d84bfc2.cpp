#include <bits/stdc++.h>




using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

int bit[50005];

void update(int pozitie,int val)

{

    while(pozitie<50005)

    {

        bit[pozitie]+=val;

        pozitie=(pozitie|(pozitie+1));

    }

}

int query(int pozitie)

{

    int ans=0;

    while(pozitie>=0)

    {

        ans=ans+bit[pozitie];

        pozitie=(pozitie&(pozitie+1))-1;

    }

    return ans;

}

int main()

{

    string s1,s2;

    deque <int> pozitie[26];

    f>>s1>>s2;

    int mutari=0,i;

    for(i=0; i<s1.size(); i++)

    {

        pozitie[s1[i]-'a'].push_back(i);

        update(i,1);

    }

    for(i=0; i<s2.size(); i++)

    {

        if(pozitie[s2[i]-'a'].empty()==true)

        {

            g<<-1<<'\n';

            return 0;

        }

        mutari=mutari+query(pozitie[s2[i]-'a'].front())-i-1;

        update(0,1);

        update(pozitie[s2[i]-'a'].front(),-1);

        pozitie[s2[i]-'a'].pop_front();

    }

    g<<mutari<<'\n';

    return 0;

}
