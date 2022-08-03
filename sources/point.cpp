#include <point.h>
#include <iomanip> //setprecision -> conf. print

point::point(){
  cout <<"Summonnig constructor of point"<<endl;
  this->x = 0.;
  this->y = 0.;
  this->bound = 0; //Boundary node yes==1, no==0
}
point::point(const double& x,const double& y){
  cout <<"Summonnig constructor of point"<<endl;
  this->x = x;
  this->y = y;
  this->bound = 0; //Boundary node yes==1, no==0
}
point::point(const point* other){
  cout <<"Summonnig constructor: pointer of point"<<endl;
  this->x = other->x;
  this->y = other->y;
  this->bound = 0; //Boundary node yes==1, no==0
}
point::~point(){
  cout <<"Summonnig destructor of point"<< endl ;
}
double point::getx(){
  return this-> x;
}
double point::gety(){
  return this-> y;
}
void point::setx(const double& x){
  this->x = x;
}
void point::sety(const double& y){
  this->y = y;
}
void point::setxy(const double& x,const double& y){
  this->x = x;
  this->y = y;
}
void point::print_point(){
  cout<<fixed<<setprecision(6) //Conf. print
      <<"("<<this->x<<","<<this->y<<")"
      <<"  || boundary type: "<<this->bound
      <<endl;
}
void point::move(const double& a,const double& b){
  this->x = x + a;
  this->y = y + b;
}
void point::move(const point* other){
  this->setxy(x + other->x,y + other->y);
}
double dot_escalar(point v1,point v2){
  return v1.x*v2.x + v1.y*v2.y;
}