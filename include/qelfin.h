// Finite element Q1
#ifndef Q1_H_INCLUDED
#define Q1_H_INCLUDED

class Q1:public point{
  public:
  // Attributes
  int N; // number of vertices
  point *V; // pointer a vertices of the finite element
  // Constructors
  Q1();
  ~Q1(); //destructor
  // Methods of the class Q1
  void print_finel();
};

Q1::Q1(){  
  cout <<"Summonnig constructor of Q1"<<endl;
  this->N=4;
  this->V=new point[4];
//  this->V=NULL;
}
Q1::~Q1(){
  cout <<"Summonnig destructor of Q1"<<endl;
}
void Q1::print_finel(){
    for (int k=0;k<(this->N);k++){
        this->V[k].print_point();
    }
}
#endif