#ifndef ABSTRACTODESOLVERHEADERDEF
#define ABSTRACTODESOLVERHEADERDEF

#include "ODEInterface.hpp"
#include <string>

class AbstractODESolver
{

  public:

    // Solve initial-value problem (pure virtual)
    virtual void Solve() = 0;

    // Accessor functions for initial and final times
    double GetInitialTime() const;
    double GetFinalTime() const;

    // Return current state
    double GetState() const;

    // Set step size
    void SetStepSize(const double h);

    // Set time interval
    void SetTimeInterval(const double t0, const double t1);

    // Set current state
    void SetState(const double state);

    // Set ODE system
    void SetODESystem(ODEInterface& anODESystem);

  protected: 

    // Initial and final time
    double mFinalTime;
    double mInitialTime;

    // Current time
    double mTime;

    // ODE system
    ODEInterface* mpODESystem;

    // Current state
    double mState;

    // Step size
    double mStepSize;

};

#endif
