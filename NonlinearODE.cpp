#include <cmath>
#include "NonlinearODE.hpp"


// Compute value of right-hand side function
double NonlinearODE::ComputeRHS( const double t, const double y ) const
{
  return 1.0 + (t-y)*(t-y);
}


// Compute solution of ODE
double NonlinearODE::ComputeAnalyticSolution( const double t ) const
{
  return t + 1.0/(1.0-t);
}
