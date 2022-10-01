#include <iostream>
#include <cmath>
#include <cstdlib>
#include "csr_matrix.cpp"

using namespace std;



int main(int argc, char* argv[])
{


double* matrix_entries; //defining our values from the struct we are going to call in the functions below
int *column_no, *row_start; 
int no_rows;
bool issymmetrical;
double *x=new double[4] {6,8,2,5}; //our given vector x from the question

 


csr_formatting nonsymmetriccsrmatrix = NonSymmetricalCSR(matrix_entries, column_no,  row_start,  issymmetrical, no_rows); //calls the functions we have defined in order to setup the nonsymmetric matrix

double* nonsymmetricAx = Calculation(nonsymmetriccsrmatrix, matrix_entries, column_no, row_start, no_rows, issymmetrical, x); //returns the solution vector Ax where A is stored non-symmetrically

 for(int q=0;q<nonsymmetriccsrmatrix.no_rows;q++) 
 {
    cout << "position " << q << " = " << nonsymmetricAx[q] << endl;  //Loops over  to print the solution vector 
 }



 csr_formatting symmetriccsrmatrix = SymmetricalCSR(matrix_entries, column_no,  row_start,  issymmetrical, no_rows);    //calls the functions we have defined in order to setup the symmetric matrix




 double* symmetricAx = Calculation(symmetriccsrmatrix, matrix_entries, column_no, row_start, no_rows, issymmetrical, x); //returns the solution vector Ax where A is stored symmetrically


 
    for(int q=0;q<symmetriccsrmatrix.no_rows;q++)
  {
     cout << "position " << q << " = " << symmetricAx[q] << endl;  //Loops to print the solution vector
  }

DeallocateMemory(symmetriccsrmatrix, symmetricAx, x); //deallocate all the vectors we have defined
DeallocateMemory(nonsymmetriccsrmatrix, nonsymmetricAx, x);



return 0;
}