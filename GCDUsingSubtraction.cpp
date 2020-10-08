#include <iostream>

using namespace std;

// Method 1 : Using Loop
int GCD(int a, int b) {
    int result, temp;
    while (a != 0 || b != 0) {
        if (a > b) {
            result = a - b;
            temp = b;
            b = result;
            a = temp;
        } else if (b > a) {
            result = b - a;
            temp = a;
            a = result;
            b = temp;
        } else {
            result = a;
            break;
        }
    }
    return result;
}

// Method 2 : Using Recursion
int GCD_RECUR(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b)
        return GCD_RECUR(a - b, b);
    return GCD_RECUR(a, b - a);
}


int main() {

    cout << "GCD : " << GCD_RECUR(50, 50);

    return 0;
}