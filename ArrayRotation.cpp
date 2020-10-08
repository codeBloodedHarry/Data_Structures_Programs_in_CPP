#include <iostream>

using namespace std;

/* Utilities Functions */
int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

/* Utilities Functions */

void reverse(int arr[], int start, int end) {
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Method 1
// Time Complexity : O(n)
// Auxiliary Space : O(d)
void rotate(int arr[], int d, int n) {
    int temp[d];
    for (int i = 0; i < d; ++i) {
        temp[i] = arr[i];
    }
    for (int j = 0; j < (n - d); ++j) {
        arr[j] = arr[j + d];
    }
    for (int k = (n - d), l = 0; k < n; ++k, ++l) {
        arr[k] = temp[l];
    }
}

// Method 2
// Time Complexity : O(n * d)
// Auxiliary Space : O(1)
void rotateByOne(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

void rotateArray(int arr[], int d, int n) {
    for (int i = 0; i < d; ++i) {
        rotateByOne(arr, n);
    }
}

// Method 3 : Juggling Algorithm
// Time Complexity : O(n)
// Auxiliary Space : O(1)
void rotateUsingJuggle(int arr[], int k_places, int size) {
    k_places = k_places % size;
    if (k_places < 0) k_places += size; // right rotation
    int sets = GCD(k_places, size);
    for (int i = 0; i < sets; ++i) {
        int temp = arr[i], j = i, k;
        while (true) {
            k = j + k_places;
            if (k >= size) k = k - size;
            if (k == i) break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

// Method 4 : Reversal Algorithm
// Time Complexity : O(n)
// Auxiliary Space : O(1)
void rotateByReversing(int arr[], int k_places, int size) {
    k_places %= size;
    if (k_places < 0) k_places += size;
    reverse(arr, 0, k_places - 1);
    reverse(arr, k_places, size - 1);
    reverse(arr, 0, size - 1);
}

// Method 5 : Block Swap Algorithm
// Time Complexity : O(n)
// Auxiliary Space : O(1)
void swap(int arr[], int fi, int si, int n) {
    // Swap n items starting from fi index corresponding to si index
    int temp;
    for (int i = 0; i < n; ++i) {
        temp = arr[i + fi];
        arr[i + fi] = arr[i + si];
        arr[i + si] = temp;
    }
}
void rotateByBlockSwap(int arr[], int k_places, int size) {
    if (k_places == 0 || k_places == size) return;
    k_places %= size;
    if (k_places < 0) k_places += size;
    int i = k_places, j = size - k_places;
    while (i != j) {
        if (i < j) {
            swap(arr, k_places - i, k_places + j - i, i);
            j -= i;
        } else {
            swap(arr, k_places - i, k_places, j);
            i -= j;
        }
    }
    swap(arr, k_places - i, k_places, i);
}

// Method 6 : Simple Rotation by one (Right Shift)
// Time Complexity : O(n)
// Space Complexity : O(1)
void simpleRightRotateByOne(int arr[], int size) {
    int temp = arr[size - 1];
    for (int i = size - 1; i > 0; --i) arr[i] = arr[i - 1];
    arr[0] = temp;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k_places = 3;
//    rotate(arr, 6, size);
//    rotateArray(arr, k_places, size);
//    rotateUsingJuggle(arr, k_places, size);
//    rotateByReversing(arr, k_places, size);
//    rotateByBlockSwap(arr, k_places, size);
//    simpleRightRotateByOne(arr, size);
    displayArray(arr, size);
    return 0;
}

