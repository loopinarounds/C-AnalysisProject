#ifndef LINEARODEHEADERDEF
#define LINEARODEHEADERDEF

#include "ODEInterface.hpp"

class LinearODE : public ODEInterface
{

  public:

    // Pure virtual method to compute right-hand side function
    double ComputeRHS( const double t, const double y ) const;

    // Virtual method to compute ODE solution
    double ComputeAnalyticSolution( const double t ) const;

  private:

};

#endif
