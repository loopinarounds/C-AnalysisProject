#include <iostream>
#include <cmath>
#include <cstdlib>
#include "linear_algebra.cpp"


using namespace std;


int main(int argc, char* argv[])
{


csr_formatting extractedmatrix, extractedvector;


double* matrix_entries; //defining our values from the struct we are going to call in the functions below
int *column_no, *row_start; 
int no_rows;
bool issymmetrical;
double tolerance = 0.0000000001;

string filename; //creating a string 'filename' to name the file we would like to call in the read function






filename = "matrix2.dat"; //setting the file as the file that holds our matrix


 extractedmatrix = ReadMatrix(matrix_entries, column_no,  row_start, issymmetrical, filename); //extracting our read in matrix struct values





filename = "vector2.dat"; //setting the file as the file that holds our vector


extractedvector = ReadMatrix(matrix_entries, column_no,  row_start, issymmetrical, filename); //extracting our read in vector struct values

 






double* Ax = Calculation(extractedmatrix, matrix_entries, column_no, row_start, no_rows, issymmetrical, extractedvector.matrix_entries); //calculating the matrix vector product of our read in matrix and vector


  for(int q=0;q<extractedmatrix.no_rows;q++) 
    {
      cout << "position " << q << " = " << Ax[q] << endl;  //Loops over to print the solution vector 
    }





double* x = new double[extractedmatrix.no_rows];  //defines a new vector to be an initial approximation 

for(int i =0;i<extractedvector.no_rows;i++)
{ 
   x[i] = 0;  //sets it equal to the zero vector as per the question
}


 double* approximationtox = Algorithm(x,tolerance,Ax,extractedmatrix); //carries out the approximation alogrithm with our extracted matrix and initial approximation 0, with set tolerance


for(int q=0;q<extractedmatrix.no_rows;q++) 
   {
      cout << "position " << q << " = " << approximationtox[q] << endl;  //Loops over to print the approximated solution
   }


double* errorvector = linearcombination(extractedvector.matrix_entries,approximationtox, -1,extractedmatrix.no_rows); //defines the error vector x-approximate of x
double error = twonorm(errorvector, extractedmatrix.no_rows); //calculates the two norm of the error vector



cout <<  "error = " << error << endl; //outputs the two norm 

return 0;







}