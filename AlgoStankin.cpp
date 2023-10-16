#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

#include <chrono>

using namespace std;

void readNumbers(int arr[], int N, string filename) {
    ifstream file(filename);
    for (int i = 0; i < N; i++) {
        file >> arr[i];
    }
}

void print(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(int arr[], int N, string filename) {
    ofstream file(filename);
    for (int i = 0; i < N; i++) {
        file << arr[i] << " ";
    }
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

void BatchersMergeSort(int arr[], int N) {
    int t = log2RoundUp(N);
    int p0 = pow(2, t - 1);
    int p = p0;

    while (p > 0) {
        int q = p0, r = 0, d = p;

        while (r == 0 || q != p) {
            if (r != 0)
            {
                d = q - p;
                q = q / 2;
            }

            for (int i = 0; i < N - d; i++) {
                if (((i & p) == r) && arr[i] > arr[i + d]) {
                    swap(arr[i], arr[i + d]);
                }
            }

            r = p;
        }

        p = p / 2;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int SIZE = 5000;
    int R[SIZE];
    int N;
    cout << "Введите количество цифр в файле:" << endl;
    cin >> N;
    cout << "Введите название файла:" << endl;
    string filename;
    cin >> filename;

    readNumbers(R, N, filename);

    auto start = chrono::steady_clock::now();
    BatchersMergeSort(R, N);
    auto end = chrono::steady_clock::now();
    long duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << endl;

    print(R, N, "sortedArray.txt");
    if (checkArray(R, N)) {
        cout << "Массив отсортирован" << endl;
    }
    else {
        cout << "Массив не отсортирован" << endl;
    }
    cout << "Время выполнения: " << duration / 1000.0 << " мсек" << endl;

    return 0;
}