#include <cassert>
#include "AbstractODESolver.hpp"


// Accessor for initial time
double AbstractODESolver::GetInitialTime() const
{
  return mInitialTime;
}


// Accessor for final time
double AbstractODESolver::GetFinalTime() const
{
  return mFinalTime;
}


// Accessor for current state
double AbstractODESolver::GetState() const
{
  return mState;
}


// Set step size
void AbstractODESolver::SetStepSize(const double h)
{
  assert(h>0);
  mStepSize = h;
}


// Set time interval
void AbstractODESolver::SetTimeInterval(const double t0, const double t1)
{
  assert(t1>t0);
  mInitialTime = t0;
  mFinalTime = t1;
}


// Set current state
void AbstractODESolver::SetState(const double state)
{
  mState = state;
}


// Set ODE system
void AbstractODESolver::SetODESystem(ODEInterface& anODESystem)
{
  mpODESystem = &anODESystem;
}
