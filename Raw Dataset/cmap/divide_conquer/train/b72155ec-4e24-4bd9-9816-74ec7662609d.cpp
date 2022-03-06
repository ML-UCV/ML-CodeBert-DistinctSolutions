#include <bits/stdc++.h>






const int MAXN = (int) 1e5;

const double INF = (double) 2e9;



std::pair <double, double> pts[MAXN + 1];



inline double dist(std::pair <double, double> a, std::pair <double, double> b) {

    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));

}



std::vector < std::pair <double, double> > pts1;



bool cmp(std::pair <double, double> a, std::pair <double, double> b) {

    return b.second - a.second >= 0;

}





double solve(int l, int r) {

    double dst = INF;

    if(r - l + 1 == 1)

        return INF;

    if(r - l + 1 == 2)

        return dist(pts[l], pts[r]);

    if((r - l + 1) == 3) {

        dst = std::min(dist(pts[l], pts[r]), std::min(dist(pts[l], pts[l + 1]), dist(pts[l + 1], pts[r])));

        return dst;

    }

    int med = (l + r) / 2;

    dst = std::min(solve(l, med), solve(med + 1, r));

    pts1.clear();

    for(int i = l; i <= r; i++)

        if(dst - std::fabs(pts[med].first - pts[i].first) >= 0)

            pts1.push_back({pts[i].first, pts[i].second});

    std::sort(pts1.begin(), pts1.end(), cmp);

    for(int i = 0; i < pts1.size(); i++)

        for(int j = i + 1; j < pts1.size() && j <= i + 7; j++)

            dst = std::min(dst, dist(pts1[i], pts1[j]));

    return dst;

}



int main() {

    FILE *fi, *fout;

    int i, n;

    fi = fopen("cmap.in" ,"r");

    fout = fopen("cmap.out" ,"w");

    fscanf(fi,"%d " ,&n);

    for(i = 1; i <= n; i++)

        fscanf(fi,"%lf %lf " ,&pts[i].first,&pts[i].second);

    std::sort(pts + 1, pts + n + 1);

    fprintf(fout,"%.6lf" ,solve(1, n));

    fclose(fi);

    fclose(fout);

    return 0;

}
