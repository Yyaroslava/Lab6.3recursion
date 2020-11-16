// Рекурсивний спосіб

#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;


template <typename T>
void Create_r(T* c, const int size, const int Low, const int High, int i) {
    if (i == size) {
        return;
    }
    c[i] = Low + rand() % (High - Low + 1);
    Create_r(c, size, Low, High, i + 1);
}

void Create_r(int* c, const int size, const int Low, const int High, int i) {
    if (i == size) {
        return;
    }
    c[i] = Low + rand() % (High - Low + 1);
    Create_r(c, size, Low, High, i + 1);
}

template <typename T>
void Print_r(T* c, const int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << c[i];
    Print_r(c, size, i + 1);
}

void Print_r(int* c, const int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << c[i];
    Print_r(c, size, i + 1);
}

template <typename T>
T Min_r(T* c, const int size, int i) {
    if (i == size - 1) return c[i];
    T min = Min_r<T>(c, size, i + 1);
    if (c[i] < min) return c[i];
    return min;
}

int Min_r(int* c, const int size, int i) {
    if (i == size - 1) return c[i];
    int min = Min_r<int>(c, size, i + 1);
    if (c[i] < min) return c[i];
    return min;
}

int main() {
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел  
    const int n = 14;
    int c[n];

    int Low = 15;
    int High = 85;

    Create_r<int>(c, n, Low, High, 0);
    Create_r(c, n, Low, High, 0);
    Print_r<int>(c, n, 0);
    Print_r(c, n, 0);
    cout << "Minimum = " << Min_r<int>(c, n, 0) << endl;
    cout << "Minimum = " << Min_r(c, n, 0) << endl;

    return 0;
}
