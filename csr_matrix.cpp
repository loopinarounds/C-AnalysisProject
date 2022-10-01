
//---------Libraries------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cassert>

using namespace std;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//---------Struct---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



struct csr_formatting 
{

double* matrix_entries;  //* used for dynamic memory allocation. matrix entries,column_no and row_start are vectors- 
int* column_no;       // that will store the information of our CSR format for matrix A. 
int* row_start;
int no_rows; //number of rows 
bool issymmetrical; //true/false for of the csr matrix is being stored symmetrically or not
 
};






//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






//---------------------------Function Prototypes--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

string filename;

csr_formatting SymmetricalCSR(double* matrix_entries, int* column_no, int* row_start, bool issymmetrical); //Function for Symmetrical CSR of A
csr_formatting NonSymmetricalCSR(double* matrix_entries, int* column_no, int* row_start, bool symmetrical); //Function for nonSymmetrical CSR of A
double* Calculation(csr_formatting csrmatrix, double* matrix_entries, int* column_no, int* row_start, int no_rows, bool issymmetrical, double *x);//Function for Calculating Ax
csr_formatting ReadMatrix(double* matrix_entries,int* column_no, int* row_start, bool issymmetrical, string filename); //function to read in our .dat matrix/vector files




void DeallocateMemory(csr_formatting csrmatrix, double* Ax, double* x);//Deallocates our produced vectors, void function as nothing needs to be returned

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------Non-Symmetric Function-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

csr_formatting NonSymmetricalCSR(double* matrix_entries, int* column_no, int* row_start, bool issymmetrical, int no_rows)
{
    
    csr_formatting csrmatrix;  //using our struct to hold what values are returned by this function 

    csrmatrix.issymmetrical = false; //as it is non-symmetrical
    csrmatrix.matrix_entries = new double[8] {8, 2, 3, 1, 4, 2, 1, 7}; //creating dynamically allocated arrays for our CSR format, in this case for the nonsymmetrical format
    csrmatrix.column_no = new int[8] {0, 3, 1, 3, 2, 0, 1, 3};
    csrmatrix.row_start = new int[5] {0, 2, 4, 5, 8};
   csrmatrix.no_rows = 4;


    return csrmatrix;  //returning our altered struct values
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




//--------------------------------------Symmetric Function----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

csr_formatting SymmetricalCSR(double* matrix_entries, int* column_no, int* row_start, bool issymmetrical, int no_rows)
{

    csr_formatting csrmatrix;


    csrmatrix.issymmetrical = true; //as it is symmetrical
    csrmatrix.matrix_entries = new double[6] {8, 2, 3, 1, 4, 7}; //creating dynamically allocated arrays for our CSR format, in this case for the symmetrical format
    csrmatrix.column_no = new int[6] {0, 3, 1, 3, 2, 3};
    csrmatrix.row_start = new int[5] {0, 2, 4, 5, 6};
    csrmatrix.no_rows = 4;
    
    


    return csrmatrix; //returning our altered struct values


}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-----------------------------Calculation Function-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  double* Calculation(csr_formatting csrmatrix,double* matrix_entries, int* column_no, int* row_start, int no_rows, bool issymmetrical, double* x)
  {
 
double *Ax = new double[csrmatrix.no_rows]; //defining our solution vector






if (csrmatrix.issymmetrical == false) //if statement to see whether we are processing the  non symmetrical or symmetrical CSR format
{



    for(int k = 0;k<csrmatrix.no_rows;k++) //making the solution vector all 0s
   {
       Ax[k] = 0;
   }

      for(int i=0;i<csrmatrix.no_rows;i++)
       {
           for(int j=csrmatrix.row_start[i];j<csrmatrix.row_start[i+1];j++)    //loops for matrix caculation Ax in non-symmetric CSR format
    
           {
          Ax[i] += csrmatrix.matrix_entries[j] *x[csrmatrix.column_no[j]];
           }
    
      } 
      return Ax; //returns our solution Ax
}

else{ //else covers the symmetric format





    for(int k = 0;k<csrmatrix.no_rows;k++)
   {
       Ax[k] = 0;
   }

for(int i=0;i<csrmatrix.no_rows;i++)  //loops for matrix caculation Ax in symmetric CSR format
    
 {

    
    for(int idx = csrmatrix.row_start[i];idx<csrmatrix.row_start[i+1];idx++)
    {
            int j = csrmatrix.column_no[idx];

                if(i==j){ //if statement checks for values on the diagonal to only multiply once

                    Ax[i] += csrmatrix.matrix_entries[idx] *x[j];
                } else{

                    Ax[i] += csrmatrix.matrix_entries[idx] *x[j]; //else covers the symmetric values in the matrix, because of symmetry we know we multiply them through twice
                    Ax[j] += csrmatrix.matrix_entries[idx] *x[i];


                }
    }

}


return Ax; //returns our solution Ax
} 
        

                     
}








  

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------Read Matrix Function-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




csr_formatting ReadMatrix(double* matrix_entries, int* column_no, int* row_start, bool issymmetrical, string filename)
{

    csr_formatting extractedmatrix, extractedvector; //links our struct to the matrix and the vector we are extracting



                                                                                                                                                    
ifstream readfile; //defines the filestream
readfile.open(filename); //opens the file we have put into the function via the filename string
assert(readfile.is_open()); //checks the file has opened correctly

string line;

getline(readfile,line); //gets the first line


if(line == "Symmetric (1 for symmetric, 0 for not symmetric)") //checks whether it is a file holding a matrix or a vector, if the first line is the given statement we know it is a matrix
{
    getline(readfile,line);  //gets the next line



    int extractedsymmetric = atoi(line.c_str()); //converts the string value of the line to an integer for storage in the struct
    if(extractedsymmetric = 1) //checks if the value is a 1 (symmetrical) or 0 (nonsymmetrical) for storage in the struct
    {
        extractedmatrix.issymmetrical = true;
    }
    else 
    {
        extractedmatrix.issymmetrical = false;
    }


    getline(readfile,line); 
    getline(readfile,line);




    extractedmatrix.no_rows = atoi(line.c_str()); //number of rows being extracted


    getline(readfile,line);
    getline(readfile,line);

    int numberofentries = atoi(line.c_str()); //converts number of entries line in the file to an integer so we can use it to see how many times we need to loop over the properties we are extracting


    getline(readfile,line);


    extractedmatrix.row_start = new int[extractedmatrix.no_rows+1];  //row_start vector is always n+1 to the number of entries n


    for(int i=0;i<extractedmatrix.no_rows+1;i++)  //loop to get row_start from file and store it in the array
    {
        getline(readfile,line);
        extractedmatrix.row_start[i] =  atoi(line.c_str()); 

    }


    getline(readfile,line); 

    extractedmatrix.column_no = new int[numberofentries];  //loop to get column numbers from file and store it in the array
    for(int i =0;i<numberofentries;i++)
    {
        getline(readfile,line);
        extractedmatrix.column_no[i] =  atoi(line.c_str()); 
    }

    getline(readfile,line); 


    extractedmatrix.matrix_entries = new double[numberofentries]; 

    for(int i=0;i<numberofentries;i++) //loop to get matrix entries from file and store it in the array
    {
        getline(readfile,line);   
        extractedmatrix.matrix_entries[i] = atof(line.c_str());
  
    }
    readfile.close(); //closes the file as we are finished extracting
     



    return extractedmatrix; //returns our extracted matrix struct properties

}

else
{
    getline(readfile,line);
    extractedvector.no_rows = atoi(line.c_str()); //finds length of vector and assigns it so we know how many lines we need to loop over


    getline(readfile,line);

    extractedvector.matrix_entries = new double[extractedvector.no_rows]; //defines the entries in the vector, an array of size n (the vector length)

    for(int i=0;i<extractedvector.no_rows;i++)
    {
        getline(readfile,line);
        extractedvector.matrix_entries[i] = atof(line.c_str());
    }

}

    readfile.close(); //closes the file as we are done extracting

return extractedvector; //returns our vector struct properties

}



























//-----------------------Deallocation Function---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void DeallocateMemory(csr_formatting csrmatrix, double* Ax, double* x)
{
    


       //deletion of all vectors produced in our functions
     
    
     delete [] csrmatrix.matrix_entries;
     delete [] csrmatrix.column_no;
     delete [] csrmatrix.row_start;
     delete [] Ax;
     delete [] x;
    

   
    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


