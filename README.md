# LidarFilter

Creates a filter object to reduce noise in the data coming from a LIDAR sensor attached to a robot. The LIDAR generates scans at a certain rate. Each scan is an array of length N of float values representing distance measurements.

Range filter:
Crops all values that are below a specific minimum and replaces it with the required minimum and all values that are above a specific maximum are replaced with the required maximum.

Temporal median filter:
Returns the median of the current and previous D scans.

Short example for temporal median:
D = 3, N = 5

T (time):
0
1
2
3
4

X (input scan):
[0, 1, 2, 1, 3] 
[1, 5, 7, 1, 3]
[2, 3, 4, 1, 0]
[3, 3, 3, 1, 3]
[10, 2, 4, 0, 0]

 Y (return of the update):
 [0, 1, 2, 1, 3]
 [0.5, 3, 4.5, 1, 3]
 [1, 3, 4, 1, 3]
 [1.5, 3, 3.5, 1, 3]
 [2.5, 3, 4, 1, 1.5]
