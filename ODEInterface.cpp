#include <iostream>
#include "ODEInterface.hpp"


double ODEInterface::ComputeAnalyticSolution( const double t ) const
{
  std::cout << "WARNING: No analytic solution available." << std::endl;
  return 0.0;
}
