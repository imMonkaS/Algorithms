#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

#include <chrono>

using namespace std;

int count_elements(string filename) {
    int counter = 0;
    ifstream file(filename);
    while (!file.eof()) {
        int r;
        file >> r;
        counter++;
    }
    return counter;
}

void readNumbers(int arr[], int N, string filename) {
    ifstream file(filename);
    for (int i = 0; i < N; i++) {
        file >> arr[i];
    }
}

void print(int arr[], int N, string filename) {
    ofstream file(filename);
    for (int i = 0; i < N; i++) {
        file << arr[i] << endl;
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

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already 
        // in place 
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
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

int compare(const void* a, const void* b)
{
    const int* x = (int*)a;
    const int* y = (int*)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int SIZE = 5000;
    int R[SIZE];
    cout << "Введите название файла:" << endl;
    string filename;
    cin >> filename;
    int N = count_elements(filename) - 1;

    readNumbers(R, N, filename);

    auto start = chrono::steady_clock::now();
    //bubbleSort(R, N);
    //qsort(R, N, sizeof(int), compare);
    BatchersMergeSort(R, N);
    auto end = chrono::steady_clock::now();
    long duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << endl;

    cout << "Сортируется массив из " << N << " чисел" << endl;
    print(R, N, "d" + to_string(N) + "-s.txt");
    if (checkArray(R, N)) {
        cout << "Массив отсортирован" << endl;
    }
    else {
        cout << "Массив не отсортирован" << endl;
    }
    cout << "Время выполнения: " << duration / 1000.0 << " мсек" << endl;
    cout << "Сортированный массив записан в файл: " << "d" + to_string(N) + "-s.txt" << endl;

    return 0;
}