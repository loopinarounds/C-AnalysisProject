#include <iostream>
#include <iomanip>
#include <cmath>
#include "ForwardEulerSolver.hpp"


// Constructor
ForwardEulerSolver::ForwardEulerSolver(ODEInterface& anODESystem, 
    const double initialState, const double initialTime, 
    const double finalTime, const double stepSize)
{
  // Initialise
  SetTimeInterval(initialTime, finalTime);
  SetStepSize(stepSize);
  mpODESystem = &anODESystem;
  mState = initialState;
  mTime = mInitialTime;
}


// Solution method
void ForwardEulerSolver::Solve()
{
  // Format output
  std::cout.setf(std::ios::scientific,std::ios::floatfield);
  std::cout.precision(6);

  // Print info on screen
  std::cout << "*****************************************************************" << std::endl;
  std::cout << "Calling forward Euler solver using the following parameters: " << std::endl; 
  std::cout << "Initial Time  " << mInitialTime << std::endl;
  std::cout << "Final Time    " << mFinalTime << std::endl;
  std::cout << "Step Size     " << mStepSize << std::endl;
  std::cout << "*****************************************************************" << std::endl;

  // Set current time
  mTime = mInitialTime;

  // Step counter and right-hand side
  int num_steps = round((mFinalTime-mInitialTime)/mStepSize);
  double rhsState;

  // Main loop
  for (int i=1; i<=num_steps; i++)
  {
    // Calculate f(t_n, u_n)
    rhsState = mpODESystem->ComputeRHS(mTime, mState);

    // Update state u_n+1 = u_n + f(t_n, u_n) h
    mState += mStepSize * rhsState;

    // Update time
    mTime += mStepSize; 
  }

  // Output solution to screen
  double exact = mpODESystem->ComputeAnalyticSolution(mTime);
  std::cout << "Final time   " << std::setw(15) << mTime << std::endl;
  std::cout << "Final state  " << std::setw(15) << mState << std::endl;
  std::cout << "Exact value  " << std::setw(15) << exact << std::endl;
  std::cout << "Error        " << std::setw(15) << fabs(exact-mState) << std::endl;
}
