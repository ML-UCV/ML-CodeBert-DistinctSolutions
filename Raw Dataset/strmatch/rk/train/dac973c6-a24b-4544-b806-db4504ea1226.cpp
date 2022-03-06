#include <cstdio>
#include <cstring>







char a[2000005], b[2000005];
int nrla, nrlb, hashA1, hashA2, P1 = 1, P2 = 1, hash1, hash2, nr_pot;
bool match[2000005];

void citire() {
    freopen("strmatch.in", "r", stdin);
    freopen("strmatch.out", "w", stdout);
    scanf("%s\n%s", a, b);
    nrla = strlen(a);
    nrlb = strlen(b);
}

void initializare() {
    for (int i = 0; i < nrla; ++i) {
        hashA1 = (hashA1 * 73 + a[i]) % 100007;
        hashA2 = (hashA2 * 73 + a[i]) % 100021;

        if (i != 0) {
            P1 = (P1 * 73) % 100007;
            P2 = (P2 * 73) % 100021;
        }
    }

    for (int i = 0; i < nrla; ++i) {
        hash1 = (hash1 * 73 + b[i]) % 100007;
        hash2 = (hash2 * 73 + b[i]) % 100021;
    }
}

void cautare_potriviri() {
    if (hash1 == hashA1 && hash2 == hashA2) {
        match[0] = true;
        nr_pot++;
    }

    for (int i = nrla; i < nrlb; ++i) {
        hash1 = ((hash1 - (b[i - nrla] * P1) % 100007 + 100007) * 73 + b[i]) % 100007;
        hash2 = ((hash2 - (b[i - nrla] * P2) % 100021 + 100021) * 73 + b[i]) % 100021;

        if (hash1 == hashA1 && hash2 == hashA2) {
            match[i - nrla + 1] = true;
            nr_pot++;
        }
    }
}

void afisare() {
    printf("%d\n", nr_pot);
    nr_pot = 0;
    for (int i = 0; i < nrlb && nr_pot < 1000; ++i)
        if (match[i]) {
            nr_pot++;
            printf("%d ", i);
        }
}

int main() {
    citire();
    if (nrla > nrlb) {
        printf("0");
        return 0;
    }
    initializare();
    cautare_potriviri();
    afisare();
    return 0;
}
