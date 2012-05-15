#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

// Forward declaration of cartesian object
class cartesian;

// Define a polar object class
class polar
{
	float radius,angle;
    
    public :
	polar()
	{
		radius=0.0;
		angle=0.0;
	}
    
	polar(float r,float a)
	{
		radius=r;
		angle=a;
	}
    
	polar(cartesian p);
	float get_radius();
	float get_angle();
    
};

// Methods that belong to polar objects
float polar :: get_radius()   { return radius; }
float polar :: get_angle()	{ return angle; }

// Polar constructor taking a cartesian object
polar :: polar(cartesian p)
{
    float X=p.get_x();
    float Y=p.get_y();
    radius=sqrt(X*X+Y*Y);
    angle=atan(X/Y);
}


// Define a cartesian object
class cartesian
{
	float x,y;
    
public:
	cartesian()
	{
		x=0.0;
		y=0.0;
	}
    
	cartesian(float X,float Y)
	{
		x=X;
		y=Y;
	}
    
	cartesian(polar p);
	float get_x();
	float get_y();
    
};

// Methods that belong to cartesian objects
float cartesian :: get_x()	{ return x; }
float cartesian :: get_y()	{ return y; }

// Cartesian constructor taking a polar object.
cartesian :: cartesian(polar p)
{
    float r=p.get_radius();
    float a=p.get_angle();
    x=r*cos(a);
    y=r*sin(a);
}

// Main driver function
void main()
{
    // Create a polar object. Notice that we use new to create an instance.
    // We also print out its angle and radius to make sure they are set.
    polar *polarobj1 = new polar(2.0,1.0);
    cout << "Polar angle: " << polarobj1->get_angle() << endl;
    cout << "Polar radius: " << polarobj1->get_radius() << endl;
    
    // Create a cartesian object, and again print out its coordinates.
    cartesian *cartesianobj1 = new cartesian(2.0,1.0);
    cout << "Cartesian x: " << cartesianobj1->get_x() << endl;
    cout << "Cartesian y: " << cartesianobj1->get_y() << endl;
    
    // Create a cartesian object using polar object defined above
    // Print out results of new cartesian object.
    cartesian *cartesianconvert = new cartesian(*polarobj1);
    cout << "Cartesian x: " << cartesianconvert->get_x() << endl;
    cout << "Cartesian y: " << cartesianconvert->get_y() << endl;
    
    // Create a polar object using the cartesian object defined above
    // Print out the results of the new polar object.
    polar *polarconvert = new polar(*cartesianobj1);
    cout << "Polar angle: " << polarconvert->get_angle() << endl;
    cout << "Polar radius: " << polarconvert->get_radius() << endl;
    
    // Got to clean up our objects.
    delete(polarobj1);
    delete(cartesianobj1);
    delete(cartesianconvert);
    delete(polarconvert);
}

