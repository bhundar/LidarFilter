#include "rangefilter.h"
#include "tempmedianfilter.h"
#include <iostream>

using namespace std;

int main() {
    cout << endl;
    cout << "Choices Avaialable: " << endl;
    cout << "1. Range Filter" << endl;
    cout << "2. Temporal Median Filter" << endl;
    cout << endl;
    cout << "Enter 1 or 2: ";

    int method;
    cin >> method;

    cout << endl;

    while (method != 1 && method != 2) {
        cout << "Invalid Option! Try again: ";
        cin >> method;
        cout << endl;
    }

    if (method == 1) { // Range Filter
        int example;
        int inputOption;
        cout << "If you would like to use the following example, enter '1', or enter '2' for manual input: "<< endl;
        cout << "[5, 15, 22, 0.03, 0.02, 55]"<< endl;
        cout << endl;

        cout << "Option: ";
        cin >> inputOption;

        while (inputOption != 1 && inputOption != 2) {
            cout << "Invalid Option! Try again: ";
            cin >> inputOption;
            cout << endl;
        }
        
        cout << endl;

        if (inputOption == 1) { // Option: Example defined above;
            cout << "Output: " << endl;
            // Initialize input scan
            double range[] = {5, 15, 22, 0.03, 0.02, 55};
            RangeFilter r1 = RangeFilter(range, 6);
            double *array1 = r1.update(range);

            for (int i = 0; i < 6; ++i) {
                if (i == 0) {
                    cout << "[" << array1[i] << ", ";
                } else if (i == 5) {
                    cout << array1[i] << "]" << endl;
                } else {
                    cout << array1[i] << ", ";
                }
            }
            cout << endl;
        } else { // Manual input
            int sizeOfScans;
            cout << "Enter the size of input scan arrays: ";
            cin >> sizeOfScans;
            cout << endl;
            while (sizeOfScans < 0) {
                cout << "Invalid entry! Please enter a positive value: ";
                cin >> sizeOfScans;
                cout << endl;
            }

            double range[1000] = {0};
            double inputScanValue;
            cout << "Enter input scan values: " << endl;
            for (int i = 0; i < sizeOfScans; ++i) {
                cin >> inputScanValue;
                range[i] = inputScanValue;
            }
            cout << endl;

            RangeFilter r1 = RangeFilter(range, sizeOfScans);
            double *array1 = r1.update(range);
            cout << "Output: " << endl;
            for (int i = 0; i < sizeOfScans; ++i) {
                if (i == 0) {
                    cout << "[" << array1[i] << ", ";
                } else if (i == sizeOfScans - 1) {
                    cout << array1[i] << "]" << endl;
                } else {
                    cout << array1[i] << ", ";
                }
            }
            cout << endl;

        }

    } else { // Temporal Median Filter
        int example;
        int inputOption;
        cout << endl;
        cout << "If you would like to use the following example (N=5, D=3), enter '1', or enter '2' for manual input: " << endl;
        cout << "[0, 1, 2, 1, 3]" << endl;
        cout << "[1, 5, 7, 1, 3]" << endl;
        cout << "[2, 3, 4, 1, 0]" << endl;
        cout << "[3, 3, 3, 1, 3]" << endl;
        cout << "[10, 2, 4, 0, 0]" << endl;
        cout << endl;

        cout << "Option: ";
        cin >> inputOption;

        while (inputOption != 1 && inputOption != 2) {
            cout << "Invalid Option! Try again: ";
            cin >> inputOption;
            cout << endl;
        }
        
        cout << endl;
        
        if (inputOption == 1) { // Option: Example defined above
            cout << "Output: " << endl;
            // Initialize input scan arrays
            double a[5] = {0, 1, 2, 1, 3};
            double b[5] = {1, 5, 7, 1, 3};
            double c[5] = {2, 3, 4, 1, 0};
            double d[5] = {3, 3, 3, 1, 3};
            double e[5] = {10, 2, 4, 0, 0};
            
            TempMedianFilter t1 = TempMedianFilter(5, 3);

            double outputArray[5][5] = {0};

            // Call update method on 5 scans initialized above 
            double * array1 = t1.update(a);
            // Add the returned output arrays to the outputArray
            for (int i = 0; i < 5; ++i) {
                outputArray[0][i] = array1[i];
            }
            double * array2 = t1.update(b);
            for (int i = 0; i < 5; ++i) {
                outputArray[1][i] = array2[i];
            }
            double * array3 = t1.update(c);
            for (int i = 0; i < 5; ++i) {
                outputArray[2][i] = array3[i];
            }
            double * array4 = t1.update(d);
            for (int i = 0; i < 5; ++i) {
                outputArray[3][i] = array4[i];
            }
            double * array5 = t1.update(e);
            for (int i = 0; i < 5; ++i) {
                outputArray[4][i] = array5[i];
            }

            // Printing output array
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (j == 0) {
                        cout << "[" << outputArray[i][j] << ", ";
                    } else if (j == 4) {
                        cout << outputArray[i][j] << "]" << endl;
                    } else {
                        cout << outputArray[i][j] << ", ";
                    }
                }
            }
            cout << endl;

        } else { // Option: Manual input
            // Get N value for the length of scanned arrays
            int sizeOfScans;
            cout << "Enter the size of input scan arrays: ";
            cin >> sizeOfScans;
            cout << endl;
            while (sizeOfScans < 0) {
                cout << "Invalid entry! Please enter a positive value: ";
                cin >> sizeOfScans;
                cout << endl;
            }
            
            // Get D value for the number of previous scans to be considered while calculating median
            int D;
            cout << "Enter the number of previous scans (D): ";
            cin >> D;
            cout << endl;
            while (D < 0) {
                cout << "Invalid entry! Please enter a positive value: ";
                cin >> D;
                cout << endl;
            }
            int exitInput;
            int counter = 0;
            TempMedianFilter t1 = TempMedianFilter(sizeOfScans, D);
            while(true) {
                double scanInput;
                double scannedArrayInput[1000] = {0};
                for (int i = 0; i < sizeOfScans; ++i) {
                    cout << "Enter scan input: " << endl;
                    cin >> scanInput;
                    cout << endl;
                    scannedArrayInput[i] = scanInput;
                }

                double * outputArray = t1.update(scannedArrayInput);
               
                for (int i = 0; i < sizeOfScans; ++i) {
                    if (i == 0) {
                        cout << "[" << outputArray[i] << ", ";
                    } else if (i == sizeOfScans - 1) {
                        cout << outputArray[i] << "]" << endl;
                    } else {
                        cout << outputArray[i] << ", ";
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}