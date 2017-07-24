/* Closest Pair of Points
    - We are given an array of n points in the plane, and the problem is to find out the closest pair of points in the array
    - The Brute force solution is O(n^2), compute the distance between each pair and return the smallest. We can calculate the smallest distance in O(nLogn) time using Divide and Conquer strategy.
*/

#include <iostream>
#include <cmath>
#include <cfloat>
#include <cstdlib>


using namespace std;

struct Point {
    int x, y;
};

float min(float x, float y) {
    return (x < y) ? x : y;
}

int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

float bruteForce(Point P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float stripClosest(Point strip[], int size, float d) {
    float min = d;

    qsort(strip, size, sizeof(Point), compareY);

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// Time Complexity :: O(n(Logn)^2)
float approach_1(Point P[], int n) {
    // For 2 or 3 points, use brute force
    if (n <= 3)
        return bruteForce(P, n);

    // Find the middle point
    int mid = n/2;
    Point midPoint = P[mid];

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = approach_1(P, mid);
    float dr = approach_1(P + mid, n-mid);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}

// The main function that finds the smallest distance
// This method mainly uses approach_1()
float closest_approach_1(Point P[], int n) {
    qsort(P, n, sizeof(Point), compareX);

    // Use recursive function approach_1() to find the smallest distance
    return approach_1(P, n);
}

// Time Complexity :: O(nLogn)
float approach_2(Point Px[], Point Py[], int n) {
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);

    // Find the middle point
    int mid = n/2;
    Point midPoint = Px[mid];


    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    Point Pyl[mid+1];   // y sorted points on left of vertical line
    Point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = approach_2(Px, Pyl, mid);
    float dr = approach_2(Px + mid, Pyr, n-mid);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}

// The main function that finds the smallest distance
// This method mainly uses approach_2()
float closest_approach_2(Point P[], int n) {
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);

    // Use recursive function approach_2() to find the smallest distance
    return approach_2(Px, Py, n);
}

int main() {
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout<<"The smallest distance is "<<closest_approach_1(P, n)<<endl;
    cout<<"The smallest distance is "<<closest_approach_2(P, n)<<endl;
    return 0;
}
