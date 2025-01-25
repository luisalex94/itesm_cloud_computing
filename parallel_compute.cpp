#include <iostream>
#include <omp.h>
#include <vector>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

using namespace std;

int main() {
    const int N = 2000000000;
    int nThreads, tid, arr_n1, arr_n2;

    cout << "Array 1 content: ";
    cin >> arr_n1;

    cout << "Array 2 content: ";
    cin >> arr_n2;

    vector<int> array1(N, arr_n1);
    vector<int> array2(N, arr_n2);
    vector<int> result(N, 0);

    cout << "Enter the number of threads: ";
    cin >> nThreads;

    #ifdef _OPENMP
        cout << "OpenMP is supported!" << endl;
        omp_set_num_threads(nThreads);
    #else
        cout << "OpenMP is not supported!" << endl;
    #endif

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        result[i] = array1[i] + array2[i];
    }

    cout << "Result: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
