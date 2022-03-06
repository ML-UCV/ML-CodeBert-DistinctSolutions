#include <fstream>






long long A, N, modular_inverse;







long long ext_euclid(long long a, long long b)

{

    long long old_r = a, r = b;

    long long old_s = 1, s = 0;

    long long old_t = 0, t = 1;

    long long q, new_r, new_s, new_t;

    while (r != 0)

    {

        q = old_r / r;

        new_s = old_s - s * q;

        new_t = old_t - t * q;

        new_r = old_r % r;

        old_r = r, r = new_r;

        old_s = s, s = new_s;

        old_t = t, t = new_t;

    }

    return old_s;

}





int main()

{

    std::ifstream fisierIN("inversmodular.in");

    fisierIN >> A >> N;

    fisierIN.close();

    modular_inverse = ext_euclid(A, N);

    if (modular_inverse < 0)

    {

        do

        {

            modular_inverse += N;

        } while (modular_inverse < 0);

    }

    std::ofstream fisierOUT("inversmodular.out");

    fisierOUT << modular_inverse;

    fisierOUT.close();

    return 0;

}
