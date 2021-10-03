#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

using namespace std;

void algorithm1( const int* arr1, const int* arr2, int*& arr3, const int& n);
void algorithm2( const int* arr1, const int* arr2, int*& arr3, const int& n);


int main() {

    int n = 10;
    while ( n <= 100000) {
        cout << "n = " << n << endl;
        int* arr1 = new int[n];
        int* arr2 = new int[n];
        for ( int i = 0; i < n; i++) {
            arr1[i] = rand();
            arr2[i] = rand();
        }
        sort( arr1, arr1 + n);
        sort( arr2, arr2 + n);
        int* arr3 = new int[n];
        int* arr4 = new int[n];

        cout << "no ordering" << endl;
        cout << "for algorithm 1: " << endl;
        algorithm1( arr1, arr2, arr3, n);

//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr3[i] << " ";
//        }

        cout << endl;
        cout << "for algorithm 2: " << endl;
        algorithm2( arr1, arr2, arr4, n);

//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr4[i] << " ";
//        }

        cout << endl;

        // int n2 = 10000;
        int* arr5 = new int[n];
        int* arr6 = new int[n];
        int* arr7 = new int[n];
        int* arr8 = new int[n];

        for ( int i = 0; i < n; i++) {
            arr5[i] = rand();
        }
        sort( arr5, arr5 + n);
        for ( int i = 0; i < n; i++) {
            arr6[i] = arr5[n-1] + rand();
        }
        sort( arr6, arr6 + n);
        cout << "arr1 is smaller than arr2" << endl;

        cout << "for algorithm 1: " << endl;
        algorithm1( arr5, arr6, arr7, n);

//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr7[i] << " ";
//        }

        cout << endl;
        cout << "for algorithm 2: " << endl;
        algorithm2( arr5, arr6, arr8, n);

//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr8[i] << " ";
//        }

        cout << endl;

        // int n3 = 10000;
        int* arr9 = new int[n];
        int* arr10= new int[n];
        int* arr11 = new int[n];
        int* arr12 = new int[n];

        cout << "arr2 is smaller than arr1" << endl;

        for ( int i = 0; i < n; i++) {
            arr10[i] = rand();
        }
        sort( arr10, arr10 + n);
        for ( int i = 0; i < n; i++) {
            arr9[i] = arr10[n-1] + rand();
        }
        sort( arr9, arr9 + n);

        cout << "for algorithm 1: " << endl;
        algorithm1( arr9, arr10, arr11, n);

//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr11[i] << " ";
//        }

        cout << endl;
        cout << "for algorithm 2: " << endl;
        algorithm2( arr9, arr10, arr12, n);

//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr12[i] << " ";
//        }

        cout << endl;
        n *= 2;

        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
        delete [] arr6;
        delete [] arr7;
        delete [] arr8;
        delete [] arr9;
        delete [] arr10;
        delete [] arr11;
        delete [] arr12;

    }


    return 0;
}

//int main() {
//
//        int n = 10;
//        cout << "n = " << n << endl;
//        int* arr1 = new int[n];
//        int* arr2 = new int[n];
//        for ( int i = 0; i < n; i++) {
//            arr1[i] = rand();
//            arr2[i] = rand();
//        }
//        sort( arr1, arr1 + n);
//        sort( arr2, arr2 + n);
//        int* arr3 = new int[n];
//        int* arr4 = new int[n];
//
//        cout << "no ordering" << endl;
//        algorithm1( arr1, arr2, arr3, n);
//
//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr3[i] << " ";
//        }
//
//        cout << endl;
//
//        // algorithm2( arr1, arr2, arr4, n);
//
////        for ( int i = 0; i < 2 * n; i++) {
////            cout << arr4[i] << " ";
////        }
//
//        cout << endl;
//
//        int* arr5 = new int[n];
//        int* arr6 = new int[n];
//        int* arr7 = new int[n];
//        int* arr8 = new int[n];
//
//        for ( int i = 0; i < n; i++) {
//            arr5[i] = rand();
//        }
//        sort( arr5, arr5 + n);
//        for ( int i = 0; i < n; i++) {
//            arr6[i] = arr5[n-1] + rand();
//        }
//        sort( arr6, arr6 + n);
//        cout << "arr1 is smaller than arr2" << endl;
//        algorithm1( arr5, arr6, arr7, n);
//
//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr7[i] << " ";
//        }
//
//        cout << endl;
//
//        // algorithm2( arr5, arr6, arr8, n);
//
////        for ( int i = 0; i < 2 * n; i++) {
////            cout << arr8[i] << " ";
////        }
//
//        cout << endl;
//
//        int* arr9 = new int[n];
//        int* arr10= new int[n];
//        int* arr11 = new int[n];
//        int* arr12 = new int[n];
//
//        cout << "arr2 is smaller than arr1" << endl;
//
//        for ( int i = 0; i < n; i++) {
//            arr10[i] = rand();
//        }
//        sort( arr10, arr10 + n);
//        for ( int i = 0; i < n; i++) {
//            arr9[i] = arr10[n-1] + rand();
//        }
//        sort( arr9, arr9 + n);
//        algorithm1( arr9, arr10, arr11, n);
//
//        for ( int i = 0; i < 2 * n; i++) {
//            cout << arr11[i] << " ";
//        }
//
//        cout << endl;
//
//        // algorithm2( arr9, arr10, arr12, n);
//
////        for ( int i = 0; i < 2 * n; i++) {
////            cout << arr12[i] << " ";
////        }
//
//        cout << endl;
//
//    return 0;
//}

//void algorithm1( const int* arr1, const int* arr2, int*& arr3, const int& n) {
//    double duration;
//    clock_t startTime = clock();
//    if ( n <= 0) {
//        cout << "Invalid size!" << endl;
//        return;
//    }
//    if ( arr3 != NULL) {
//        delete [] arr3;
//    }
//
//    int valid = n;
//    arr3 = new int[n];
//
//    for ( int i = 0; i < n; i++) {
//        arr3[i] = arr1[i];
//    }
//    for ( int i = 0; i < n; i++) {
//        bool check = false;
//        for ( int k = valid - 1; k >= 0; k--) {
//            if ( arr2[i] >= arr3[k]) {
//                int* tmp = new int[valid + 1];
//                for ( int j = 0; j <= k; j++) {
//                    tmp[j] = arr3[j];
//                }
//                for ( int j = k + 1; j < valid; j++) {
//                    tmp[j+1] = arr3[j];
//                }
//                valid++;
//                tmp[k+1] = arr2[i];
//                delete [] arr3;
//                arr3 = tmp;
//                check = true;
//                break;
//            }
//        }
//
//        if ( !check) {
//            int* tmp = new int[valid + 1];
//            for ( int k = 0; k < valid; k++) {
//                tmp[k+1] = arr3[k];
//            }
//            valid++;
//            tmp[0] = arr2[i];
//            delete [] arr3;
//            arr3 = tmp;
//            }
//        }
//
//    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//    cout << "Execution took " << duration << " milliseconds." << endl;
//}

void algorithm1( const int* arr1, const int* arr2, int*& arr3, const int& n) {
    double duration;
    clock_t startTime = clock();
    if ( n <= 0) {
        cout << "Invalid size!" << endl;
        return;
    }
    if ( arr3 != NULL) {
        delete [] arr3;
    }

    int valid = n;
    arr3 = new int[2 * n];

    for ( int i = 0; i < n; i++) {
        arr3[i] = arr1[i];
    }
    for ( int i = 0; i < n; i++) {
        bool check = false;
        for ( int k = valid - 1; k >= 0; k--) {
            if ( arr2[i] >= arr3[k]) {
                for ( int j = valid; j > k; j--) {
                    arr3[j] = arr3[j-1];
                }
                valid++;
                arr3[k+1] = arr2[i];
                check = true;
                break;
            }
        }

        if ( !check) {
            for ( int k = valid; k > 0; k--) {
                arr3[k] = arr3[k-1];
            }
            valid++;
            arr3[0] = arr2[i];
            }
        }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}


void algorithm2( const int* arr1, const int* arr2, int*& arr3, const int& n) {
    double duration;
    clock_t startTime = clock();
    if ( n <= 0) {
        cout << "Invalid size!" << endl;
        return;
    }
    if ( arr3 != NULL) {
        delete [] arr3;
    }

    arr3 = new int[2*n];

    int index = 0;
    int checked = 0;
    int checked2 = 0;

    for ( int i = 0; i < n; i++) {
        for ( int j = checked; j < n; j++){
            if ( arr1[i] <= arr2[j]) {
                arr3[index] = arr1[i];
                index++;
                checked2 = i + 1;
                break;
            }
            else if ( arr1[i] > arr2[j]) {
                arr3[index] = arr2[j];
                checked = j + 1;
                index++;
            }
        }
    }

    for ( int i = checked; i < n; i++) {
        arr3[index] = arr2[i];
        index++;
    }

    if ( checked >= n) {
        for ( int i = checked2; i < n; i++) {
            arr3[index] = arr1[i];
            index++;
        }
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}
