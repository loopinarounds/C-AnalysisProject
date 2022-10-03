# C-AnalysisProject

Find the attached **Coursework.pdf**. This repo contains a set of programs used for solving a set of Initial Value and Boundary Value problem Differential Equations. It makes use of a range of numerical analysis methods, and uses the produced data to comppare the accuracy of each method. The methods used are as follows:
- Forward Euler
- Backward Euler
- Stormer Verlet

These methods are first applied in 1-dimension. Then making use of a custom **Vector** library, the methods are also applied in 2-dimensions.


## Properties of Each File 

All .hpp header files have a corresponding .cpp file, to save reading I will only list what is contained in each .cpp file.

- **Abstract ODE Solver**: Contains class AbstractODESolver which holds all of the variables that are fixed to the Differential Problem, such as the initial time and step size. They are protected as such for use in the variety of method solver files. Also contains a virtual solve method to be overwritten in the driver.cpp when needed.


- **Forward Euler Solver**: Derived from **Abstract ODE Solver**, contains a public constructor to initilaise all the needed variables from the method. It then contains a solve method which integrates the forward euler method to calculate the numerical estimate to the answer and output the solution.

- **Driver**: Used for calling all of our constructed solve methods and timing them.

- **LinearODE**: Contains the linear ODE we are tasked to solve, as well as a method computing the exact answer.

- **NonLinearODE**: Contains the non-linear ODE we are tasked to solve, as well as a method computing the exact answer.

## Overview

An exemplery C++ Numerical Analysis Coursework from my Masters Degree class on C++ and Mathematical Computation.

Find within the code files examples of:

- Algorithm Integration
- OOP methods
- Manipulation of Matrices and Arrays using Algorithms
- Pointers and Memory Allocation
