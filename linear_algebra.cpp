#include <iostream>
#include <cmath>
#include <cstdlib>
#include "csr_matrix.cpp"



using namespace std;

 int length;
 

 double* matrix_entries; //defining our values from the struct we are going to call in the functions below
int *column_no, *row_start; 
int no_rows;
bool issymmetrical;








//function prototypes

double dotproduct(double* u, double* w, int length);
double twonorm(double* u, int length);
double* linearcombination(double* u, double* w, double a, int length);
double* Algorithm(double* x, double tolerance, double* Ax, csr_formatting extractedmatrix);



double dotproduct(double* u, double* w, int length)
{

  double dotanswer;
    



for(int i =0;i<length;i++)
{
       dotanswer += u[i] * w[i]; //simple loop for the dot product 

}





return dotanswer;
}






double twonorm(double*u, int length)
{

double twonormanswer;


for(int i=0;i<length;i++)
{

twonormanswer += pow(u[i],2); //squares each number in a given vector and sums them


}

 

return pow(twonormanswer,0.5); //returns the square root of the sum

}



double* linearcombination(double* u, double* w, double a, int length)
{


double* linearcombinationanswer = new double[length]; 

for(int k=0;k<length;k++)
{

    linearcombinationanswer[k] =0; //creates a 0 vector to fill with solutions
}


for(int i=0;i<length;i++)
{

linearcombinationanswer[i] = u[i] + a*w[i]; //simple loop for linear combination

}

return linearcombinationanswer;


}




double* Algorithm(double* x, double tolerance, double* Ax, csr_formatting extractedmatrix)

{

      int no_rows = extractedmatrix.no_rows; 

     
      double* r = new double[no_rows];
      for(int i=0;i<no_rows;i++)
      {
        r[i] = 0;  //initlaising r to be a zero vector
      }
      double* Axzero = Calculation(extractedmatrix, matrix_entries, column_no, row_start, no_rows, issymmetrical, x); //calculates the matrix vector product of A and initial approximation to x
      for(int i=0;i<no_rows;i++)
      {
        r[i] = Ax[i] - Axzero[i]; //r = b - Ax0 (b = Ax = the martix vector product of our matrix/vector we call to the function)
      }



    double* p = r; //p = r


      double twonormr = 1.0; //sets twonorm at a value > tolerance
      int k =0; //sets our iteration counter to 0



       





      while(twonormr>tolerance) //loops until the required condition is met
      {
          //All the below code follows the algorithm stated in the question, making use of exisitng functions

    
      cout <<  "k = " << k << endl;
      


      double alpha = (dotproduct(r,r, no_rows))/(dotproduct(Calculation(extractedmatrix, matrix_entries, column_no,  row_start, no_rows,  issymmetrical, p), p, no_rows));
      double* newx =  linearcombination(x,p,alpha,no_rows);
      double* newr = linearcombination(r,Calculation(extractedmatrix, matrix_entries, column_no,  row_start, no_rows,  issymmetrical, p),-alpha, no_rows);
      double beta = (dotproduct(newr,newr,no_rows))/(dotproduct(r,r,no_rows));
      double* newp = linearcombination(newr,p,beta,no_rows);

    



      

        p = newp; //e.g newp = p_k+1, to be able to iterate again we must set our p_k to be p_k+1 to then find p_k+2 and so on until the loop closes
        r = newr;
        x = newx;
        k=k+1; //+1 each time we loop through the algorithm

          twonormr = twonorm(r,no_rows); 

      cout << "twonorm of r = " << twonormr << endl;

      }


     
      return x; //returns our approximated solution 


    }

     

