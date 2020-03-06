#include "rangefilter.h"

// Constructor for RangeFilter
RangeFilter::RangeFilter( double scannedRanges[] , int arraySize ){
    this->length = arraySize;
    this->scanned_range = scannedRanges;
}

// update: 
// Parameters: scannedArray - Array of doubles
// crops all the distances that are below range_min or above range_max 
double* RangeFilter::update( double scannedArray[] ) {
    for (int index = 0; index < this->length; ++index) {
        if (scannedArray[index] < range_min) {
            scanned_range[index] = range_min;
        } else if (scannedArray[index] > range_max) {
            scanned_range[index] = range_max;
        }
    }
    return this->scanned_range;
}