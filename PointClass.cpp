#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Point
{
private:
    double x;
    double y;
public:
    Point(): x(0), y(0) {}
    Point(double a, double b): x(a), y(b) {}
    void setXY(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
    double getX() const { return x; }
    double getY() const { return y; }
    double operator|(const Point& q)
    {
        return sqrt((this->x - q.getX())*(this->x - q.getX()) + (this->y - q.getY())*(this->y - q.getY()));
    }
    bool operator!= (Point a)
    {
        if ((this->x != a.getX()) || (this->y != a.getY()))
        {
            return true;
        }
        else {return false;}
    }
};

bool operator== (const Point &a, const Point&b)
{
    if ((a.getX() == b.getX()) && (b.getY() == b.getY()))
    {
        return true;
    }
    else { return false;}
}
