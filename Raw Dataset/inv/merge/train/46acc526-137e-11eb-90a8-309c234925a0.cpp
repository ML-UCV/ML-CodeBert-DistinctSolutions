#include <iostream>
#include <vector>
#include <fstream>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



vector <int> v;







int interclasare(int left1, int right1, int left2, int right2)

{

    int nr_inversiuni = 0;

    vector <int> interclasat;

    int i=left1, j= left2;

    while(i<= right1 && j<= right2)

    {

        if(v[i] > v[j])

        {

            interclasat.push_back(v[j]);

            nr_inversiuni += right1 - i +1;

            j++;

        }

        else

        {

            interclasat.push_back(v[i]);

            i++;

        }

    }

    while(i<=right1)

    {

        interclasat.push_back(v[i]);

        i++;

    }

    while(j<=right2)

    {

        interclasat.push_back(v[j]);

        j++;

    }

    int k = left1;

    for(i=0; i<interclasat.size(); i++)

    {

        v[k] = interclasat[i];

        k++;

    }

    return nr_inversiuni;

}







int inversiuni(int left, int right)

{

    if(left == right)

    {

        return 0;

    }

    int mid = (left+right)/2;

    int ans1 = inversiuni(left, mid)%9917;

    int ans2 = inversiuni(mid+1, right)%9917;

    int ans3 = interclasare(left, mid, mid+1, right)%9917;



    return (ans1+ans2+ans3)%9917;

}



int main()

{

    int n;

    fin>>n;

    int i;

    for(i=1; i<=n; i++)

    {

        int x;

        fin>>x;

        v.push_back(x);

    }

    fout<<inversiuni(0, n-1);



}
