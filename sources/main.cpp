#include "header.h"
#include "mesh.h"
#include "data.h"
#include <ctime>
#include <stdlib.h>

main(){
  double t0, t1;// Execution time
  data Data;
  //FILE* freopen(const char* filename,const char mode* write, FILE* stream)
  freopen("log.txt","w",stdout);// Log file || redirecting stdout
  t0=clock();// Execution time
  Data.intro(); //Introduction to the program: FEM_2D 
  Data.readdata(); 
  Mfinel<P1> Mesh; // Selecting element type P1
//   Mfinel<Q1> Mesh; // Selecting element type Q1 || NOT COMPLETE
  Mesh.fill_mesh(Data); // Read of the mesh by files
  Mesh.print_nodes(); // Print nodes
  Mesh.print_elements(); // Print elements
  Mesh.solve(); 
//   Mesh.~Mfinel(); // Memory clean
  t1 = clock(); // Execution time
  cout<<"Execution Time: "<<(double(t1-t0)/CLOCKS_PER_SEC)<<" seconds"<<endl;	
  fclose (stdout);
  return 0;
}	