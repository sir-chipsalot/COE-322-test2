#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

class Point {
protected:
  float x,y;
public:
  Point(float in_x,float in_y) {
    x = in_x; y = in_y; };

  float get_x() { return x; };

  float get_y() { return y;};
  
  float distance_to_origin(){ return sqrt( x*x + y*y ); };
  
  float angle() { return atan(y/x); };
  
  //add operation
  Point operator+(Point q)
  {
	  return Point(x+q.x, y+q.y);
  };

  //scale operation
  Point operator*(float scale)
  {
	  return Point(x*scale, y*scale);
  };
  //Halfway function
  /*Point halfway(Point q){
    Point sum = add(q);
    return sum.scale(0.5);
  };
  */

  Point halfway(Point p2)
  {
	  Point p3(x,y); // equal to the point we are calling from

	  Point p4 = p3+p2;
	  p4 = p4*0.5;
	  return p4;
  }
  float distance( Point q ) {
    auto dx = x-q.x, dy = y-q.y;
    return sqrt( dx*dx + dy*dy );
  };
  float twice_the_angle() {
    float a = angle();
    return 2*a;
  };
};

int main() {
  Point p1(1.0,1.0);
  float d = p1.distance_to_origin();
  cout << "Distance to origin: "
  	<< d << '\n';
  cout << p1.angle() << '\n';
  
  Point p2(2.0,2.0);
  
  p1.distance(p2);

  Point p3 = p1+p2;

  p3 = p3*0.5;

  cout << p3.get_x() << "\n";
}
