#include "LinearODE.hpp"
#include "NonlinearODE.hpp"
#include "ForwardEulerSolver.hpp"


int main(int argc, char* argv[])
{
  // Instantiate Linear ODE for test
  ODEInterface* p_linear_ode = new LinearODE();
  ODEInterface* p_nonlinear_ode = new NonlinearODE();

  // Initial condition for linear ODE
  double y0 = 1.0;
  double t0 = 0.0;
  double tmax = 1.0;
  double h = 0.05;

  // Instantiate forward Euler 
  ForwardEulerSolver* p_FEsolver = new ForwardEulerSolver(*p_linear_ode, y0, t0, tmax, h);
  p_FEsolver->Solve();

  t0 = 2.0;
  tmax = 3.0;

  // Reset for forward Euler for nonlinear ODE
  p_FEsolver->SetODESystem(*p_nonlinear_ode);
  p_FEsolver->SetTimeInterval(t0, tmax);
  p_FEsolver->SetState(y0);
  p_FEsolver->Solve();
  // Reset with half the step size
  p_FEsolver->SetStepSize(h/2.0);
  p_FEsolver->SetState(y0);
  p_FEsolver->Solve();

  // Clean
  delete p_linear_ode;
  delete p_nonlinear_ode;
  delete p_FEsolver;
}
