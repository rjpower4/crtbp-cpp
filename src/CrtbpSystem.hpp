#ifndef CRTBPP_H
#define CRTBPP_H

#include <vector>

typedef std::vector<double> state_type;

class CrtbpSystem {
  double mu;

public:


  /**
     Construct a new `CrtbpSystem` type.

     @param mu mass ratio parameter associated with the system
   */
  CrtbpSystem(double mu);

  double getMassRatio();


  /**
     Equation of motion defintion for the CRTBP.

     @param q state to evaluate equations of motion at. Length 6
     @param dqdt output vector containing the velocities associated with states. Length 6
     @param t time. Not used for autonomous CRTBP
   */
  void operator()(const state_type &q, state_type &dqdt, const double t);
};


#endif /* CRTBPP_H */
