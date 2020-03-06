#include "tempmedianfilter.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

// Constructor for TempMedianFilter
TempMedianFilter::TempMedianFilter( int arraySize, int previousScans )
: D(previousScans), length(arraySize) {}

// findMedian:
// Parameters: a - Array of doubles
//             n - Length of array
// returns the median value of the array
double findMedian(double a[], int n) 
{ 
    // Sort the array
    std::sort(a, a+n); 
  
    // Check for even case
    if (n % 2 != 0) 
       return a[n/2]; 
      
    return (a[(n-1)/2] + a[n/2])/2.0; 
} 

// update: 
// Parameters: scannedArray - Array of doubles
// returns the median of the current and previous D scans
double * TempMedianFilter::update( double *scannedArray ) {
    int retvalLen = 0;
    if (this->numUpdates == 0) {
        for (int k = 0; k < this->length; ++k) {
            scanned_range[this->numUpdates][k] = scannedArray[k];
        }
        this->numUpdates++;
        return scannedArray;
    } else {
        double n = std::min(this->numUpdates, this->D);
        for (int i = 0; i < this->length; ++i) {
            double currMedian[(int)n+1];
            currMedian[0] = scannedArray[i];
            int currMedianLen = 1;
            int counter = 0;
            int value = 0;
            
            for (int y = n; y > 0; y--) {
                if (this->numUpdates > 3) {
                    value = this->numUpdates - counter;
                    counter++;
                } else {
                    value = y;
                }
                currMedian[currMedianLen] = scanned_range[value-1][i];
                currMedianLen++;
            }

            double getMedian = findMedian(currMedian, currMedianLen);
            this->retValArray[retvalLen] = getMedian;
            retvalLen++;
        }  
    }
    for (int k = 0; k < this->length; ++k) {
        scanned_range[this->numUpdates][k] = scannedArray[k];
    }
    this->numUpdates++;
    return this->retValArray;
}