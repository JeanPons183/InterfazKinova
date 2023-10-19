#ifndef Dynamics_h
#define Dynamics_h

//LIBRARIES
#include <iostream>
#include <cmath>

#define g 9.8

//FUNCTIONS

namespace robot{
	
	//SINGLE PENDULUM DYNAMIC
	void singlePendulum(double tau[1], double q[1], double qp[1], double* qpp){
		
		const float c1 = 1; // = (mass*Length^2) -> (mL^2)
		const float c2 = 1; // = (mass*Length) -> (mL)
		
		qpp[0] = (tau[0] - c2*g*sin(q[0]))/c1; // dqq = (T - mgL*sin(q))/(mL^2);
	}

}

namespace gravity{
	
	// SINGLE PENDULUM GRAVITY VECTOR
	void singlePendulum(double q[1], double* G){
		
		const float c = 1; // = (mass*Length) -> (mL)
		
		G[0] = c*g*sin(q[0]); // G = mgL*sin(q);
	}
	
}

#endif
