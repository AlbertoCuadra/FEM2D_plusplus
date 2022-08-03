#include "pelfin.h"

P1::P1(){
  cout <<"Summonnig constructor of P1"<<endl;
  this->N=3;
  this->V=new point*[3];
}
P1::~P1(){
  cout <<"Summonnig destructor of P1"<<endl;
//   for(int i=0;i<this->N;i++){
//     this->V[i]->~point();// Summonnig destructor of point
//   }
//   delete[] this->V;
//   cout<<"Remove triangle"<<endl;
}
void P1::print_finel(){
  cout<<"---------------"<<endl;
  for (int k=0;k<(this->N);k++){
    this->V[k]->print_point();
  }
  cout<<endl<<"Area: "<<this->area<<endl;
  cout<<"---------------"<<endl;
}
double P1::solve_area(){
  double d[3],s;
  d[0] = sqrt(pow((this->V[0]->getx()-this->V[1]->getx()),2.) + pow((this->V[0]->gety()-this->V[1]->gety()),2.));
  d[1] = sqrt(pow((this->V[1]->getx()-this->V[2]->getx()),2.) + pow((this->V[1]->gety()-this->V[2]->gety()),2.));
  d[2] = sqrt(pow((this->V[2]->getx()-this->V[0]->getx()),2.) + pow((this->V[2]->gety()-this->V[0]->gety()),2.));
  s = 0.5*(d[0]+d[1]+d[2]); //Semiperimeter
  return sqrt(s*(s-d[0])*(s-d[1])*(s-d[2]));
}
point P1::gradbase(int &i){
  point p;
  if (i==0){
    p.x = -(this->V[i+2]->y - this->V[i+1]->y)/(2*this->area);
    p.y = (this->V[i+2]->x - this->V[i+1]->x)/(2*this->area);
  }
  else if(i==1){
    p.x = -(this->V[0]->y - this->V[i+1]->y)/(2*this->area);
    p.y = (this->V[0]->x - this->V[i+1]->x)/(2*this->area);
  }
  else{
    p.x = -(this->V[1]->y - this->V[0]->y)/(2*this->area);
    p.y = (this->V[1]->x - this->V[0]->x)/(2*this->area);
  }
  return p;
}
void P1::solve_matrix_local(MatrixXf &A){
  cout<<"Solve local matrix"<<endl;
  for (int i=0;i<this->N;i++){
    for (int j=0;j<this->N;j++){
      A(this->V[i]->ind-1,this->V[j]->ind-1) += this->area*dot_escalar(gradbase(i),gradbase(j));
    }
  }
}
double P1::phi(double &x, double &y){
  return (this->V[1]->x*this->V[2]->y - this->V[1]->y*this->V[2]->x
          - x*(this->V[2]->y - this->V[1]->y)
          + y*(this->V[2]->x - this->V[1]->x))/(2*this->area);
}
void P1::connect_area(){
  this->area = this->solve_area();
}