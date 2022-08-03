#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

class point{
public:  
  // Attributes
  double x;
  double y;
  int ind;
  int bound; 
  double sol;
  // Constructors
  point();
  point(const double& x,const double& y);
  point(const point* other);
  virtual ~point();// destructor
  // Methods
  double getx();
  double gety();
  void setx(const double& x);
  void sety(const double& y);
  void setxy(const double& x,const double& y);
  void print_point();
  void move(const double& x,const double& y);
  void move(const point* other);
  friend double dot_escalar(point v1,point v2);
};
#endif