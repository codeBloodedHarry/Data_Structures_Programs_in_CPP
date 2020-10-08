#include <iostream>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {

    cout << "GCD : " << GCD(25, 50);

    return 0;
}