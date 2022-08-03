// Finite element P1
#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

#include <Eigen/Dense>
#include <vector>
#include <point.h>

using namespace Eigen;

class P1:public point{
private:
  double solve_area(); // private method (by default)
public:
  // Attributes
  int N; // number of vertices
  double area;
  point** V; 
  // pointer to pointer vertices of the finite element: it has three pointers
  // that save the memory path of the vertices already created.
  // Constructors
  P1(); 
  ~P1(); //destructor
  // Methods of the class P1
  void print_finel();
  void connect_area(); // Assing value to the attribute area
  double phi(double &x, double &y);
  point gradbase(int &i);
  void solve_matrix_local(MatrixXf &A);
};
#endif