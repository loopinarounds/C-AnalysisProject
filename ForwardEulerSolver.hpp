#ifndef FORWARDEULERSOLVERHEADERDEF
#define FORWARDEULERSOLVERHEADERDEF

#include "AbstractODESolver.hpp"
#include "ODEInterface.hpp"

class ForwardEulerSolver: 
  
  public AbstractODESolver

{

  public:

    // Constructor
    ForwardEulerSolver(ODEInterface& anODESystem, 
	const double initialState, const double initialTime, 
	const double finalTime, const double stepSize);

    // Solution method
    void Solve();

  private:

    // Hide general constructor
    ForwardEulerSolver();

};

#endif
