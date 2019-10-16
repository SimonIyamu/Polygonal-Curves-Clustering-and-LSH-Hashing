#pragma once
#include <vector>

using namespace std;

class Point{
    private:
        string id;
        double x;
        double y;
    public:
        Point();
        ~Point();
        void setX(double x);
        void setY(double y);
        double getX();
        double getY();
};
