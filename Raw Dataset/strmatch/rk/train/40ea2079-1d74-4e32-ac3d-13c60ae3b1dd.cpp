#include <stdio.h>
#include <stdlib.h>
#include <string.h>






int main()
{
    FILE *in = freopen("strmatch.in", "r", stdin);
    FILE *out = freopen("strmatch.out", "w", stdout);
    char *subsir = (char *)malloc(2000010 * sizeof(char));
    char *sir = (char *)malloc(2000010 * sizeof(char));
    char c;
    int n = 0;
    int m = 0;
    while ((c = getchar()) != '\n')
    {
        subsir[m++] = c;
    }
    subsir[m] = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        sir[n++] = c;
    }
    sir[n] = 0;
    int h_sir1 = 0;
    int h_subsir1 = 0;
    int h_sir2 = 0;
    int h_subsir2 = 0;
    int h1 = 1;
    int h2 = 1;
    int nr = 0;
    int aparitii[1000];
    for (int i = 0; i < m - 1; i++)
    {
        h1 = (73 * h1) % 100007;
        h2 = (73 * h2) % 100021;
        h_sir1 = (73 * h_sir1 + sir[i]) % 100007;
        h_subsir1 = (73 * h_subsir1 + subsir[i]) % 100007;
        h_sir2 = (73 * h_sir2 + sir[i]) % 100021;
        h_subsir2 = (73 * h_subsir2 + subsir[i]) % 100021;
    }
    h_sir1 = (73 * h_sir1 + sir[m - 1]) % 100007;
    h_subsir1 = (73 * h_subsir1 + subsir[m - 1]) % 100007;
    h_sir2 = (73 * h_sir2 + sir[m - 1]) % 100021;
    h_subsir2 = (73 * h_subsir2 + subsir[m - 1]) % 100021;
    for (int i = 0; i <= n - m; i++)
    {
        if (h_sir1 == h_subsir1 && h_sir2 == h_subsir2)
        {
            if (nr < 1000)
                aparitii[nr] = i;
            nr++;
        }
        if (i != n - m)
        {
            h_sir1 = (73 * (h_sir1 - h1 * sir[i]) + sir[i + m]) % 100007;
            h_sir1 = h_sir1 < 0 ? h_sir1 + 100007 : h_sir1;
            h_sir2 = (73 * (h_sir2 - h2 * sir[i]) + sir[i + m]) % 100021;
            h_sir2 = h_sir2 < 0 ? h_sir2 + 100021 : h_sir2;
        }
    }
    printf("%d\n", nr);
    for (int i = 0; i < nr && i < 1000; i++)
    {
        printf("%d ", aparitii[i]);
    }
    fclose(in);
    fclose(out);
    return 0;
}
