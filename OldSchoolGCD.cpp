#include <iostream>

#define MAX_FACTORS 1024

using namespace std;

typedef struct {
    int size;
    int factors[MAX_FACTORS];
    int exponents[MAX_FACTORS];
} FACTORIZATION;

void displayFactors(const FACTORIZATION *factorization) {
    for (int i = 0; i < factorization->size; ++i) {
        cout << "Factors of " << factorization->factors[i] << " : ";
        for (int j = 1; j <= factorization->exponents[i]; ++j) {
            cout << factorization->factors[i] << (j < factorization->exponents[i] ? " * " : "");
        }
        cout << endl;
    }
    cout << endl;
}

void getFactors(int n, FACTORIZATION *factorization) {
    factorization->factors[0] = 1;
    factorization->exponents[0] = 1;

    int currentIndex = 1, exponentCount = 0;

    for (int i = 2; i <= n; ++i) {
        exponentCount = 0;
        while (n % i == 0) {
            exponentCount++;
            n /= i;
        }
        if (exponentCount > 0) {
            factorization->factors[currentIndex] = i;
            factorization->exponents[currentIndex] = exponentCount;
            currentIndex++;
        }
    }
    factorization->size = currentIndex;

    displayFactors(factorization);
}

int getGCD(int m, int n) {

    FACTORIZATION factorization_m, factorization_n;

    getFactors(m, &factorization_m);
    getFactors(n, &factorization_n);

    int i = 1, j = 1, gcd = 1, min;

    while (i < factorization_m.size && j < factorization_n.size) {
        if (factorization_m.factors[i] < factorization_n.factors[j]) i++;
        else if (factorization_n.factors[j] < factorization_m.factors[j]) j++;
        else {
            min = (factorization_m.exponents[i] < factorization_n.exponents[j] ?
                   factorization_m.exponents[i] : factorization_n.exponents[j]);
            for (int k = 0; k < min; ++k) {
                gcd *= factorization_m.factors[i];
            }
            i++;
            j++;
        }
    }

    return gcd;
}

int main() {

    int a = 28, b = 20;
    int gcd = getGCD(a, b);
    cout << "GCD(" << a << ", " << b << ") : " << gcd;

}