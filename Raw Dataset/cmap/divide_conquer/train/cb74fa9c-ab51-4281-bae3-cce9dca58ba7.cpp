#include <bits/stdc++.h>
long long dist2(const std::pair <long long, long long>& p0, const std::pair <long long, long long>& p1) {

    return (p0.second - p1.second) * (p0.second - p1.second) + (p0.first - p1.first) * (p0.first - p1.first);

}
int N;







std::vector <std::pair <long long, long long> > V(100005);

std::vector <std::pair <long long, long long> > A, B;



long long DivideEtImpera(int Left = 0, int Right = N, std::vector <std::pair <long long, long long> >& A = A, std::vector <std::pair <long long, long long> >& B = B) {

    if (Left+1 >= Right) return 40000000000000005;

    if (Left+2 == Right) {

        if (B[Left] > B[Left+1])

            std::swap(B[Left], B[Left+1]);

        return dist2(A[Left], A[Left+1]);

    } long long Min = std::min(DivideEtImpera(Left, (Left+Right)/2, A, B), DivideEtImpera((Left+Right)/2, Right, A, B));



    std::merge(B.begin() + Left, B.begin() + (Left+Right)/2, B.begin() + (Left+Right)/2, B.begin() + Right, V.begin());

    std::copy(V.begin(), V.begin() + (Right-Left), B.begin() + Left);



    int replace = 0;

    for (int i=Left, j; i<Right; ++i)

        if (abs(B[i].second - A[(Left+Right)/2].first) <= Min)

            V[replace++] = B[i];



    for (int i=0, j; i<replace; ++i)

        for (j=i+1; j<replace && j < i+8; ++j)

            Min = std::min(Min, dist2(V[j], V[i]));

    return Min;

}



std::ifstream In ("cmap.in");

std::ofstream Out("cmap.out");



void Citire() {

    In >> N;

    for (int i=0, X, Y; i<N; ++i)

        In >> X >> Y, A.push_back({X, Y});

}



void Rezolvare() {

    std::sort(A.begin(), A.end());

    for (int i=0; i<N; ++i)

        B.push_back(A[i]);

    Out << std::fixed << std::setprecision(6) << sqrt(double(DivideEtImpera())) << '\n';

}



int main()

{

    Citire();

    Rezolvare();



    return 0;

}
