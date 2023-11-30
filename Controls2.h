#ifndef Controls_h
#define Controls_h

//LIBRARIES
#include <iostream>
#include <cmath>
#include "mat.h"
#include "Numerics.h"
#include "Gen3lite_model.h"

//DEFINITIONS

//#define g 9.8

using namespace std;

// Controler options
enum Ctrl { 
	_nullC_, // Null controler
	_canG_, // Gravity Cancelation
	_PD_canG_, // PD + Gravity Cancelation
	_PD_comG_, // PD + Gravity Compensation
	_P_d_canG_, // P'D' + Gravity Cancelation
	_P_d_comG_ // P'D' + Gravity Compensation
};

//CLASS

//template<const int N> // N = DOF of the Robot
class Control2{
	
	public:
		
		Ctrl controler; // Current Controler Indicator
		
		// >>-->>-->>-- Properties --<<--<<--<<
		
		// Torque (result)
		mat<7,1> tau;

		//Desired position
		mat<7,1> q_des;
		
		//Control gains (vectors)
		mat<7,1> P; // Proportional
		mat<7,1> D; // Derivative
		mat<7,1> K1; // Extra 1
		mat<7,1> K2; // Extra 2
		
		//Virtual variables
		mat<7,1> theta; // Virtual position
		mat<7,1> theta_p; // Virtual velocity
		mat<7,1> theta_pp; // Virtual acceleration
		
		//Gravity vector (vector)
		mat<7,1> G;
		
		
		// >>-->>-->>-- CONSTRUCTOR --<<--<<--<<
		Control2(){ // Void constructor
			initControl(); // Initialize properties
		}
		// DECONSTRUCTOR
		~Control2(){	
			cout<<"\n You Losed Control :u"<<endl;
		}
		
		// >>-->>-->>-- METHODS --<<--<<--<<
		
		// Initialize properties function
		void initControl(void);
		
		//Null Controler
		mat<7,1> Null_C(const mat<7,1> &q, const mat<7,1> &qp);
		
		//Gravity Cancelation Controler
		mat<7,1> canG(const mat<7,1> &q, const mat<7,1> &qp);
		
		//PD + Gravity Cancelation Controler
		mat<7,1> PD_canG(const mat<7,1> &q, const mat<7,1> &qp);
		
		//PD + Gravity Compensation Controler
		mat<7,1> PD_comG(const mat<7,1> &q, const mat<7,1> &qp);
		
		//P'D' + Gravity Cancelation Controler
		mat<7,1> P_d_canG(const mat<7,1> &q, const mat<7,1> &qp);
		
		//P'D' + Gravity Compensation Controler
		mat<7,1> P_d_comG(const mat<7,1> &q, const mat<7,1> &qp);
		
		//Virtual Dynamic of Grade 1
		void virtualD1(const mat<7,1> &q);
		
		//Virtual Dynamic of Grade 2
		void virtualD2(const mat<7,1> &q);
	
};

// FUNCTIONS


// >>==>>==>>==>>==>>== Initialize properties function ==<<==<<==<<==<<==<<
//template<const int N>
void Control2::initControl(void){
	
	for(int n=0 ; n<7 ; n++){ // Initialize vectors
		tau[n][0] = 0;
		P[n][0] = 0;
		D[n][0] = 0;
		K1[n][0] = 0;
		K2[n][0] = 0;
		theta[n][0] = 0;
		theta_p[n][0] = 0;
		theta_pp[n][0] = 0;
		G[n][0] = 0;
	}
	
	controler = _nullC_; // Initialize as null controler
} 


// >>-->>-->>-- Null Controler --<<--<<--<<
//template<const int N>
mat<7,1> Control2::Null_C(const mat<7,1> &q, const mat<7,1> &qp){
}


// >>-->>-->>-- Gravity Cancelation Controler --<<--<<--<<
//template<const int N>
mat<7,1> Control2::canG(const mat<7,1> &q, const mat<7,1> &qp){
	
	//  tau = G(q)
	
	tau = GravityVector(q); // Eval vector of gravity

	return tau;
}


// >>-->>-->>-- PD + Gravity Cancelation Controler --<<--<<--<<
//template<const int N>
mat<7,1> Control2::PD_canG(const mat<7,1> &q, const mat<7,1> &qp){
	
	//  tau = G(q) - P*q_error - D*qp
	
	G = GravityVector(q); // Make torque control
	
	for(int n=0 ; n<7 ; n++) // Make control for each articulation
		tau[n][0] = G[n][0] - P[n][0]*(q[n][0]-q_des[n][0]) - D[n][0]*qp[n][0];

	return tau; // Result
}
	
	
// >>-->>-->>-- PD + Gravity Cancelation Controler --<<--<<--<<
//template<const int 7>
mat<7,1> Control2::PD_comG(const mat<7,1> &q, const mat<7,1> &qp){
	
	//  tau = G(q_des) - P*q_error - D*qp
	
	for(int n=0 ; n<7 ; n++) // Make control for each articulation
		tau[n][0] = G[n][0] - P[n][0]*(q[n][0]-q_des[n][0]) - D[n][0]*qp[n][0];

	return tau; // Result
}

/*
// >>-->>-->>-- P'D' + Gravity Cancelation Controler --<<--<<--<<
//template<const int N>
mat<7,1> Control2::P_d_canG(const mat<7,1> &q, const mat<7,1> &qp){
	
	//  tau = G(q) - P*q_error - K*(q-theta)
	
	G = GravityVector(q); // Eval vector of gravity
	virtualD1(q); // Virtual dynamic for theta
	
	for(int n=0 ; n<7 ; n++) // Make control for each articulation
		tau[n][0] = G[n][0] - P[n][0]*(q[n][0]-q_des[n][0]) - K1[n][0]*(q[n][0]-theta[n][0]);

	return tau; // Result
}


// >>-->>-->>-- P'D' + Gravity Compensation Controler --<<--<<--<<
//template<const int N>
mat<7,1> Control2::P_d_comG(const mat<7,1> &q, const mat<7,1> &qp){
	
	//  tau = G(q_des) - P*q_error - K*(q-theta)

	virtualD1(q); // Virtual dynamic for theta
	
	for(int n=0 ; n<7 ; n++) // Make control for each articulation
		tau[n][0] = G[n][0] - P[n][0]*(q[n][0]-q_des[n][0]) - K1[n][0]*(q[n][0]-theta[n][0]);

	return tau; // Result
}*/


/* Control Dynamics
	-> mc*theta(^pp) + d_Uc/d_theta + d_Rc/d_theta(^p) = 0
	
	Uc = K*[(q-theta)^2]/2
	Rc = D*theta(^p)/2
	
	Dynamic -> mc*theta(^pp) + K*(theta-q) + D*theta(^p) = 0
	
	If mc>0
		-> theta(^pp) = [K*(q-theta) - D*theta(^p)]/mc
	If mc=0
		-> theta(^p) = K*(q-theta)/D
	
	For the class variables
		K = K1
		mc = K2
*/
/*
// >>-->>-->>-- Virtual Dynamic Function of Grade 1--<<--<<--<<
//template<const int N>
void Control::virtualD1(const mat<7,1> &q){
	
	for(int n=0 ; n<7 ; n++){ // Articulations cycle
		
		// theta(^1) =  K1*(q-theta)/D
		theta_p[n][0] = (K1[n][0]/D[n][0])*(q[n][0] - theta[n][0]); // Dynamic
		
		//Next value for theta
		double y0[1] = {theta[n][0]}; // Initial conditions
		double y[1] = {0}; // Solution variable
		
		numerics::Taylor<1>(_h_ , theta_p[n][0] , y0 , y); // Numeric method
		
		theta[n][0] = y[0]; // Result = virtual position
	}
}

/*
// >>-->>-->>-- Virtual Dynamic Function of Grade 2--<<--<<--<<
//template<const int N>
void Control::virtualD2(const mat<7,1> &q){
	
	for(int n=0 ; n<7 ; n++){ // Articulations cycle
		
		// theta(^2) = [K1*(q-theta) - D*theta(^1)]/K2
		theta_pp[n][0] = (K1[n][0]*(q[n][0] - theta[n][0]) - D[n][0]*theta_p[n][0])/K2[n][0]; // Dynamic
		
		//Next value for theta
		double y0[2] = {theta[n][0], theta_p[n][0]}; // Initial conditions
		double y[2] = {0,0}; // Solution variable
		
		numerics::Taylor<2>(_h_ , theta_pp[n][0] , y0 , y); // Numeric method
		
		theta[n][0] = y[0]; // Result = virtual position
		theta_p[n][0] = y[1]; // Result = virtual velocity
	}
}*/

#endif
