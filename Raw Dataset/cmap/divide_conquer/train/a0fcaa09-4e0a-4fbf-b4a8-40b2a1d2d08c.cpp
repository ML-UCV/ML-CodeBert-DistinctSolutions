#include <bits/stdc++.h>


using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");



int n;

pair<double, double> nums[100005], mergeS[100005];

double sol;



double dist(pair<double, double> a, pair<double, double> b);



void divcon(int lft, int rgt);



int main()

{



    fin >> n;

    for(int i = 1; i <= n; ++i){

        fin >> nums[i].first >> nums[i].second;

    }



    std::sort(nums + 1, nums + n + 1);

    sol = DBL_MAX;



    divcon(1, n);



    fout << fixed << setprecision(6) << sol;



    return 0;

}



double dist(pair<double, double> a, pair<double, double> b){

    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));

}



void divcon(int lft, int rgt){

    int mid = (lft + rgt) / 2;

    if(lft >= rgt) return;



    if(lft == rgt - 1){

        sol = min(sol, dist(nums[lft], nums[rgt]));

        return;

    }



    divcon(lft, mid);

    divcon(mid + 1, rgt);

    int stop = mid, start = lft, pos = lft - 1; ++mid;



    while(start <= stop && mid <= rgt){

        if(nums[start].second <= nums[mid].second){

            mergeS[++pos] = nums[start++];

        }

        else{

            mergeS[++pos] = nums[mid++];

        }

    }



    while(start <= stop) mergeS[++pos] = nums[start++];



    while(mid <= rgt) mergeS[++pos] = nums[mid++];



    for(int i = lft; i <= rgt; ++i) nums[i] = mergeS[i];



    for(int i = lft; i <= rgt; ++i){

        for(int j = i + 1; j <= min(i + 8, rgt); ++j){

            sol = min(sol, dist(nums[i], nums[j]));

        }

    }



}
