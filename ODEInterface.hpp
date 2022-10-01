#ifndef ODEINTERFACEHEADERDEF
#define ODEINTERFACEHEADERDEF

// Interface class for an ODE IVP

class ODEInterface
{

  public:

    // Compute right-hand side (pure virtual)
    virtual double ComputeRHS( const double t, const double y ) const = 0;

    // Compute analytical solution
    virtual double ComputeAnalyticSolution( const double t ) const;

};

#endif
