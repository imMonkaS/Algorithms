///******************************************************************************
//
//Алгоритмы и структуры данных
//Лабораторная работа
//Вариант 8
//Обменная сортировка со слиянием (Алгоритм M)
//
//*******************************************************************************/
//
//#include <iostream>
//#include <cmath>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//void print(int arr[], int N) {
//    for (int i = 0; i < N; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int log2RoundUp(int N) {
//    int i = 0;
//    while (pow(2, i) < N) {
//        i++;
//    }
//    return i;
//}
//void readNumbers(int arr[], int N, string filename) {
//    ifstream file(filename);
//    for (int i = 0; i < N; i++) {
//        file >> arr[i];
//    }
//}
//
//int main()
//{
//    //int R[12] = { 45, 7878, 456, 432, 657, 345, 657, 768, 234, 23, 0, 3 };
//    int R[500];
//    const int N = 500;
//    readNumbers(R, N, "d500.txt");
//    // int t = log10(N);
//    // int p = pow(2, t - 1);
//    // int q = pow(2, t - 1), r = 0, d = p;
//
//    // for (int i = 0; (i < (N - d)); i++){
//    //     if((i + 1) > (i + d + 1)){
//    //         swap(R[i + 1], R[i + d + 1]);
//    //     }
//    //     if (q != p){
//    //         d = q - p;
//    //         q /= 2;
//    //         r = p;
//    //     }
//    // }
//
//    //int t = log2RoundUp(N);
//    //int p = pow(2, t - 1);
//
//    //for (int p_counter = 1; p_counter <= t; p_counter++) {
//    //    int q = pow(2, t - 1), r = 0, d = p;
//
//    //    for (int i = 0; i < N; i++) {
//    //        if (((i < (N - d)) && ((i & p) == r))) {
//    //            if (R[i] > R[i + d]) {
//    //                swap(R[i], R[i + d]);
//    //            }
//    //        }
//
//    //        if (q != p) {
//    //            d = q - p;
//    //            q /= 2;
//    //            r = p;
//    //        }
//    //    }
//
//    //    p /= 2;
//    //}
//
//
//
//
//    //int t = log2RoundUp(N);
//    //int p = pow(2, t - 1);
//    //
//    //int q = pow(2, t - 1);
//
//    //while (p > 0) {
//    //    int r = 0, d = p;
//
//    //    for (int i = 0; i < N; i++) {
//    //        if ((i < (N - d)) && ((i & p) == r)) {
//    //            if (R[i] > R[i + d])
//    //                swap(R[i], R[i + d]);
//    //        }
//    //    }
//
//    //    if (q != p) {
//    //        d = q - p;
//    //        q = q / 2;
//    //        r = p;
//    //    }
//
//    //    for (int i = 0; i < N; i++) {
//    //        if ((i < (N - d)) && ((i & p) == r)) {
//    //            if (R[i] > R[i + d]) swap(R[i], R[i + d]);
//    //        }
//    //    }
//
//    //    p = p / 2;
//    //}
//
//    int t = log2RoundUp(N);
//    int p = pow(2, t - 1);
//    int q = pow(2, t - 1);
//
//    while (p > 0) {
//        int r = 0, d = p;
//
//        for (int i = 0; i < N; i++) {
//            if ((i < (N - d))) {
//                if (R[i] > R[i + d]) swap(R[i], R[i + d]);
//            }
//        }
//
//        if (q != p) {
//            d = q - p;
//            q = q / 2;
//        }
//
//        p = p / 2;
//    }
//
//
//    //do {
//    //    int q = pow(2, t - 1), r = 0, d = p;
//
//    //    for (int i = 0; i < N; i++) {
//    //        if ((i < N - d) && ((i & p) == r)) {
//    //            if (R[i] > R[i + d]) {
//    //                swap(R[i], R[i + d]);
//    //            }
//    //        }
//
//    //        else if (i >= N - d) {
//    //            if (q > p) {
//    //                d = q - p;
//    //                q = q / 2;
//    //                r = p;
//    //            }
//    //        }
//    //    }
//    //    
//    //    p = p / 2;
//    //} while (p > 0);
//
//    print(R, N);
//    if (checkArray(R, N)) {
//        //cout << "Numbers sorted correctly";
//        cout << "Sorted";
//    }
//    else {
//        //cout << "Numbers sorted incorrectly"
//        cout << "Not sorted";
//    }
//
//    return 0;
//}       



#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

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

int main()
{
    const int N = 500;
    int R[N];

    readNumbers(R, N, "d500.txt");

    int t = log2RoundUp(N);
    int p0 = pow(2, t - 1);
    int p = p0;

    //while (p > 0) {
    //    int q = p0, r = 0, d = p;

    //    for (int i = 0; i < N; i++) {
    //        if ((i < (N - d))) {
    //            if (R[i] > R[i + d]) swap(R[i], R[i + d]);
    //        }
    //    }

    //    if (q != p) {
    //        d = q - p;
    //        q = q / 2;
    //    }

    //    p = p / 2;
    //}

    while (p > 0) {
        int q = p0, r = 0, d = p;

        while (r == 0 || q != p) {
            if (r != 0)
            {
                d = q - p;
                q >>= 1;
            }

            for (int i = 0; i < N - d; i++) {
                if (((i & p) == r) && R[i] > R[i + d]) {
                    swap(R[i], R[i + d]);
                }
            }

            r = p;
        }

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