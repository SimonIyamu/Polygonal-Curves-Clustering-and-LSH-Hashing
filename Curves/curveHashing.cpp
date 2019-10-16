#include "curveHashing.hpp"
#include <iostream>
#include <math.h>
#include "DTW.hpp"

using namespace std;





void curveHashing(vector<Curve *>::iterator queryCurve){
    
    // first of all we need to caldulate delta
    int m1,m2;
    m1 = (*queryCurve)->getNumberOfCoordinates(); // m1 keeps the number of coordinates of query curve
    //m2 = (*inputCurve)->getNumberOfCoordinates(); // m2 keeps the number of coordinates of input curve
    double delta = 2;
    
    //===============================================================================================
    //          *** SOME INFO FOR WHAT WE ARE GOING TO DO ***
    //===============================================================================================
    // we know begin to take each point of the curve
    // we divide x,y with delta and the two quotient shows as which bucket of the grid, current point belogs to
    // now we know in which bucket the points belogs to, we find the minimum of the four distances
    // between point and the points of the grid - the four corners of the bucket
     //===============================================================================================
    
    float x,y; //coordinates of a point of curve
    int previousMinX = -1;   // stores minX of the previous point of curve
    int previousMinY = -1;   // stores minY of the precious point of curve
    for (int i=0; i< m1; i++){
        x = (*queryCurve)->getSpecificXCoord(i);
        y = (*queryCurve)->getSpecificYCoord(i);
        int xStartOfBucket = x/delta;
        int yStartOfBucket = y/delta;
        
        int x1  = xStartOfBucket * delta; // x start of bucket
        int x2  = (xStartOfBucket+1) * delta; // x end of bucket
        int y1  = yStartOfBucket * delta; // y start of bucket
        int y2  = (yStartOfBucket +1) * delta; // y end of bucket
        
        int minX;      // stores the x of the bucket corner closest to point of curve
        int minY;      // stores the y of the bucket corner closest to point of curve
        

        if (distance(x,(float) x1, y,(float)y1) < distance(x,(float)x1,y,(float)y2)){
            minX = x1;
            minY = y1;
        }
        else{
            minX = x1;
            minY = y2;
        }
        if (distance(x,(float) minX, y,(float)minY) > distance(x,(float)x2,y,(float)y1)){
            minX = x2;
            minY = y1;
        }
        if(distance(x,(float)minX, y,(float)minY) > distance(x,(float)x2,y,(float)y2)){
            minX = x2;
            minY = y2;
        }
        
        // now we are going to check if minx,miny of the previous point of curve is the same
        // with current point's minx miny
        // if it is the same, we do not store it again. We go to the next point of curve
        
        if (minX == previousMinX && minY == previousMinY){
            cout << "Previous had the same point\n";
            cout << previousMinX << " " << minX << " " << previousMinY << " " << minY <<"\n";
             cout << "Point of vector is: " << minX << "-" << minY << "\n";
        }
        else{
            
           cout << "Point of vector is: " << minX << "-" << minY << "\n";
        }
        previousMinX = minX;
        previousMinY = minY;
        
        
       /* cout << "Point of vector is: " << minX << "-" << minY << "\n";
        cout << distance(x,x1, y,y1) << " " << distance(x,x1, y,y2)<< " " << distance(x,x2, y,y1)<< " " << distance(x,x2, y,y2) << "\n";
        cout << x1 << " " << x2 << " AND " << y1 << " " << y2 << "\n";
        cout << x << " " << y << "\n";*/
        
    }
    
}