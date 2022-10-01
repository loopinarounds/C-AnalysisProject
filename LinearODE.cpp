#include <cmath>
#include "LinearODE.hpp"


// Compute value of right-hand side function
double LinearODE::ComputeRHS( const double t, const double y ) const
{
  return -3.0*y;
}


// Compute solution of ODE
double LinearODE::ComputeAnalyticSolution( const double t ) const
{
  return exp(-3.0*t);
}
