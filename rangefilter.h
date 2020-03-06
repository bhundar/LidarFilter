#ifndef _RANGEFILTER_H
#define _RANGEFILTER_H

// A RangeFilter crops all values 
class RangeFilter {
    // Minimum measured distance
    double range_min = 0.03;
    // Maximum measured distance
    double range_max = 50;
    public:
        // Pointer to scanned arrays
        double *scanned_range;
        // Length of scans
        int length = 0;
        RangeFilter( double scannedRanges[] , int arraySize);
        double * update( double scannedArray[] );
};

#endif