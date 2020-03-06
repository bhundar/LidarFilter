#ifndef _TEMPMEDIANFILTER_H
#define _TEMPMEDIANFILTER_H


class TempMedianFilter {
    public:
        int D;
        int length;
        double scanned_range[722][722] = {0};
        int numUpdates = 0; // is the length of this array
        double retValArray[1000] = {0};

        TempMedianFilter( int arraySize, int previousScans );
        double * update( double *scannedArray );
};

#endif