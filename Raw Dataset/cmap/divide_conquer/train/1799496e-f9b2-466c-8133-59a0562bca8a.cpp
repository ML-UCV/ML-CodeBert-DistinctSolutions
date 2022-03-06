#include<cstdio>
#include<algorithm>
#include<cmath>


using namespace std;

struct point {
    int x, y;
};

point P[100000];
int n;

inline bool compareX(point a, point b) {
    return a.x < b.x;
}

inline bool compareY(point a, point b) {
    return a.y < b.y;
}

double minim(double a, double b) {
    if(a < b) return a;
    return b;
}

double dist(point p1, point p2) {
    long long a = ((long long)p2.x-p1.x) * ((long long)p2.x-p1.x);
    long long b = ((long long)p2.y-p1.y) * ((long long)p2.y-p1.y);
    return sqrt(a+b);
}

double bruteForce(point P[], int n) {
    double distMin = 4e15;
    double d;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++) {
            d = dist(P[i],P[j]);
            if(d < distMin)
                distMin = d;
        }
    return distMin;
}

double stripClosest(point strip[], int Size, double d) {
    sort(strip,strip+Size,compareY);
    double distmin = d;
    double distance;
    for(int i=0; i<Size; i++)
        for(int j=i+1; j<Size && (strip[j].y - strip[i].y) < distmin; j++) {
            distance = dist(strip[i],strip[j]);
            if(distance < distmin)
                distmin = distance;
        }
    return distmin;
}

double closestUtil(point P[], int n) {
    if(n <= 3)
        return bruteForce(P,n);
    int mid = n /2;
    point midPoint = P[mid];
    double dleft = closestUtil(P,mid);
    double dright = closestUtil(P+mid,n-mid);
    double d = minim(dleft,dright);
    point strip[n];
    int l = 0;
    for(int i=0; i<n; i++)
        if(abs(P[i].x - midPoint.x) < d)
            strip[l++] = P[i];
    return minim(d,stripClosest(strip,l,d));
}

double closestPair(point P[], int n) {
    sort(P,P+n,compareX);
    return closestUtil(P,n);
}

int main() {
    FILE *fin, *fout;
    fin = fopen("cmap.in","r");
    fout = fopen("cmap.out","w");
    fscanf(fin,"%d",&n);
    for(int i=0; i<n; i++)
        fscanf(fin,"%d%d",&P[i].x,&P[i].y);
    fclose(fin);
    fprintf(fout,"%f\n",closestPair(P,n));
    fclose(fout);
    return 0;
}
