#include <iostream>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;

    static constexpr double PI = 3;

public:
    
    Cylinder() : radius(0), height(0)
    {
    }

   
    Cylinder(double radius, double height)
        : radius(radius), height(height)
    {
    }

   
    double getRadius()
    {
        return radius;
    }

    
    void setRadius(double radius)
    {
        this->radius = radius;
    }

    // Getter for height
    double getHeight()
    {
        return height;
    }

    // Setter for height
    void setHeight(double height)
    {
        this->height = height;
    }

    
    double calculateVolume()
    {
        return PI * radius * radius * height;
    }
};

int main()
{
    Cylinder c1(5, 10);

    cout << "Radius: " << c1.getRadius() << endl;
    cout << "Height: " << c1.getHeight() << endl;
    cout << "Volume: " << c1.calculateVolume() << endl;

    return 0;
}