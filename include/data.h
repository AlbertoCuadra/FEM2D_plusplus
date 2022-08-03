#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include "header.h"

struct fich_mesh{
  string nodes;
  string connect;
  string boundary;
};

class data{
  public:
    fich_mesh mesh;
    void intro();
    void readdata(); 
//     void save(T &m);
//     void f(T &x, T &y);
};
void data::intro(){
  cout<<"*******************************************"<<endl
      <<"** C++ proyect: FEM 2D                   **"<<endl
      <<"** Author: Alberto Cuadra Lara           **"<<endl
      <<"** Last update: 14/04/2018               **"<<endl
      <<"** Email: albertocuadralara@gmail.com    **"<<endl
      <<"*******************************************"<<endl;
}
// Read of the data of the simulation 
// In this case, we only read the data of the mesh
void data::readdata(){
   ifstream fichdatos ("datos.dat");// Name of the file with the data of the mesh
   cout<<"-------------------------------------------"<<endl
       <<"READ OF THE DATA:"<<endl;
   if (fichdatos.is_open()){
      fichdatos>>this->mesh.nodes;
      cout<<"Nodes file: "<<this->mesh.nodes<<endl;
      fichdatos>>this->mesh.connect;
      cout<<"Conexion file: "<<this->mesh.connect<<endl;
      fichdatos>>this->mesh.boundary;
      cout<<"Boundary file: "<<this->mesh.boundary<<endl;
  }
  cout<<"-------------------------------------------"<<endl;
}
// save matrix/vector
template<typename T> 
void save(T &m){
  cout<<"-------------------------------------------"<<endl
      <<"SAVING RESULTS:";
  string fname = "output.txt";
  ofstream fichOut;
  fichOut.open(fname.c_str());
  // file opening || open is expecting a const char -> c_str
  // string does not provide an automatic conversion to const char
  if (fichOut.bad()){//In case corrupt file
    cout << "\nIs not possible to open or create the file"<< endl;
  }
  fichOut<<m<<endl;
  fichOut.close();//file closing
  cout<<fname<<endl
      <<"-------------------------------------------"<<endl;
}
// function f(x,y) || -laplacian(u(x,y)) = f(x,y)
template < typename T >
double f(T &x, T &y){
    return -2.*pow(x,4) + pow(x,2)*(33./2.-24.*pow(y,2))-2.*pow(y,4)+33.*pow(y,2)/2.-5.;
}
#endif