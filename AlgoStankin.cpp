#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

void print(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int log2RoundUp(int N) {
    int i = 0;
    while (pow(2, i) < N) {
        i++;
    }
    return i;
}

bool checkArray(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

void readNumbers(int arr[], int N, string filename) {
    ifstream file(filename);
    for (int i = 0; i < N; i++) {
        file >> arr[i];
    }
}

int main()
{
    //int R[12] = { 45, 7878, 456, 432, 657, 345, 657, 768, 234, 23, 0, 3 };
    int R[500];
    const int N = 500;
    readNumbers(R, N, "d500.txt");

    int t = log2RoundUp(N);
    int p = pow(2, t - 1);

    while (p > 0) {
        int q = pow(2, t - 1);
        int r = 0;
        int d = p;

        do {
            for (int i = 0; i < N - d; i++) {
                if (((i & p) == r) && R[i] > R[i + d]) {
                    swap(R[i], R[i + d]);
                }
            }
            d = q - p;
            q = q / 2;
            r = p;
        } while (q > p);

        p = p / 2;
    }

    print(R, N);
    if (checkArray(R, N)) {
        //cout << "Numbers sorted correctly";
        cout << "Sorted";
    }
    else {
        //cout << "Numbers sorted incorrectly"
        cout << "Not sorted";
    }

    return 0;
}
