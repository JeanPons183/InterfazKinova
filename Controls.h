#ifndef Controls_h
#define Controls_h

//LIBRARIES
#include <iostream>
#include <cmath>
#include "Numerics.h"

//DEFINITIONS

#define g 9.81

using namespace std;

// Controler options
enum Ctrl { 
	_Me_MySelf_N_I_, // Null controler
	_canG_, // Gravity Cancelation
	_PD_canG_, // PD + Gravity Cancelation
	_PD_comG_, // PD + Gravity Compensation
	_P_d_canG_, // P'D' + Gravity Cancelation
	_P_d_comG_ // P'D' + Gravity Compensation
};

// Control Class
template<const int N> // N = DOF of the Robot
class Control;

// Control Law Type
template<const int N>
using Ctrl_Law_Type = void (Control<N>::*)(double[N] , double[N] , double*);

//CLASS

template<const int N> // N = DOF of the Robot
class Control{
	
	public:
		
		Ctrl controler; // Current Controler Indicator
		
		// >>-->>-->>-- Properties --<<--<<--<<
		
		//Desired position
		double qd[N];
		
		//Control gains (vectors)
		double P[N]; // Proportional
		double D[N]; // Derivative
		double K1[N]; // Extra 1
		double K2[N]; // Extra 2
		
		//Virtual variable
		double theta[N];
		
		//Gravity vector (vector)
		double G[N];
		
		//Gravity vector (function pointer)
		void (*Gravity)(double[N],double*);
		
		
		// >>-->>-->>-- CONSTRUCTOR --<<--<<--<<
		Control(){ // Void constructor
			initControl(); // Initialize properties
		}
		Control(void (*_Gravity)(double[N],double*)){ // Construct with Gravity Vector
			
			Gravity = _Gravity; // Gravity vector function pointer
			
			initControl(); // Initialize properties
		}
		// DECONSTRUCTOR
		~Control(){	
			cout<<"\n You Losed Control :u"<<endl;
		}
		
		// >>-->>-->>-- METHODS --<<--<<--<<
		
		// Set controler function
		Ctrl_Law_Type<N> setControl(void);
		
		// Initialize properties function
		void initControl(void);
		
		//Null Controler
		void Me_MySelf_N_I(double q[N], double qp[N], double* tau);
		
		//Gravity Cancelation Controler
		void canG(double q[N], double qp[N], double* tau);
		
		//PD + Gravity Cancelation Controler
		void PD_canG(double q[N], double qp[N], double* tau);
		
		//PD + Gravity Compensation Controler
		void PD_comG(double q[N], double qp[N], double* tau);
		
		//P'D' + Gravity Cancelation Controler
		void P_d_canG(double q[N], double qp[N], double* tau);
		
		//P'D' + Gravity Compensation Controler
		void P_d_comG(double q[N], double qp[N], double* tau);
		
		//Virtual Dynamic of Grade 1
		void virtualD1(double q[N]);
		
		//Virtual Dynamic of Grade 2
		void virtualD2(double q[N]);
	
};

// FUNCTIONS


// >>==>>==>>==>>==>>== Initialize properties function ==<<==<<==<<==<<==<<
template<const int N>
void Control<N>::initControl(void){
	
	for(int n=0 ; n<N ; n++){ // Initialize vectors
		P[n] = 0;
		D[n] = 0;
		K1[n] = 0;
		K2[n] = 0;
		theta[n] = 0;
		G[n] = 0;
	}
	
	controler = _Me_MySelf_N_I_; // Initialize as null controler
} 


// >>==>>==>>==>>==>>== Choose controler function ==<<==<<==<<==<<==<<
template<const int N>
Ctrl_Law_Type<N> Control<N>::setControl(void){
	
	switch(controler){ // Choose controler
		
		case _Me_MySelf_N_I_: // Null controler
			return &Me_MySelf_N_I;
			
		case _canG_: // PD + Gravity Cancelation
			return &canG;
			
		case _PD_canG_: // PD + Gravity Cancelation
			return &PD_canG;
		
		case _PD_comG_: // PD + Gravity Compensation
			(*Gravity)(qd,G); // Gravity compensation
			return &PD_comG;
			
		case _P_d_canG_: // P'D' + Gravity Cancelation
			return &P_d_canG;
			
		case _P_d_comG_: // P'D' + Gravity Compensation
			(*Gravity)(qd,G); // Gravity compensation
			return &P_d_comG;
	}
}



// >>-->>-->>-- Null Controler --<<--<<--<<
template<const int N>
void Control<N>::Me_MySelf_N_I(double q[N], double qp[N], double* tau){
}


// >>-->>-->>-- Gravity Cancelation Controler --<<--<<--<<
template<const int N>
void Control<N>::canG(double q[N], double qp[N], double* tau){
	
	//  tau = G(q)
	
	(*Gravity)(q,G); // Eval vector of gravity
	
	for(int n=0 ; n<N ; n++) // Make control for each articulation
		tau[n] = G[n];
}


// >>-->>-->>-- PD + Gravity Cancelation Controler --<<--<<--<<
template<const int N>
void Control<N>::PD_canG(double q[N], double qp[N], double* tau){
	
	//  tau = G(q) - P*q_error - D*qp
	
	(*Gravity)(q,G); // Eval vector of gravity
	
	for(int n=0 ; n<N ; n++) // Make control for each articulation
		tau[n] = G[n] - P[n]*(q[n]-qd[n]) - D[n]*qp[n];
}
	
	
// >>-->>-->>-- PD + Gravity Cancelation Controler --<<--<<--<<
template<const int N>
void Control<N>::PD_comG(double q[N], double qp[N], double* tau){
	
	//  tau = G(qd) - P*q_error - D*qp
	
	for(int n=0 ; n<N ; n++) // Make control for each articulation
		tau[n] = G[n] - P[n]*(q[n]-qd[n]) - D[n]*qp[n];
}


// >>-->>-->>-- P'D' + Gravity Cancelation Controler --<<--<<--<<
template<const int N>
void Control<N>::P_d_canG(double q[N], double qp[N], double* tau){
	
	//  tau = G(q) - P*q_error - K*(q-theta)
	
	(*Gravity)(q,G); // Eval vector of gravity
	virtualD1(q); // Virtual dynamic for theta
	
	for(int n=0 ; n<N ; n++) // Make control for each articulation
		tau[n] = G[n] - P[n]*(q[n]-qd[n]) - K1[n]*(q[n]-theta[n]);
}


// >>-->>-->>-- P'D' + Gravity Compensation Controler --<<--<<--<<
template<const int N>
void Control<N>::P_d_comG(double q[N], double qp[N], double* tau){
	
	//  tau = G(qd) - P*q_error - K*(q-theta)

	virtualD1(q); // Virtual dynamic for theta
	
	for(int n=0 ; n<N ; n++) // Make control for each articulation
		tau[n] = G[n] - P[n]*(q[n]-qd[n]) - K1[n]*(q[n]-theta[n]);
}


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

// >>-->>-->>-- Virtual Dynamic Function of Grade 1--<<--<<--<<
template<const int N>
void Control<N>::virtualD1(double q[N]){
	
	double theta_p[N]; // Virtual velocity
	
	for(int n=0 ; n<N ; n++){ // Articulations cycle
		
		// theta(^p) =  K1*(q-theta)/D
		theta_p[n] = (K1[n]/D[n])*(q[n] - theta[n]); // Dynamic
		
		//Next value for theta
		double y0[1] = {theta[n]}; // Initial conditions
		double y[1] = {0}; // Solution variable
		
		numerics::Taylor<1>(_h_ , theta_p[n] , y0 , y); // Numeric method
		
		theta[n] = y[0]; // Result = virtual position
	}
}

// >>-->>-->>-- Virtual Dynamic Function of Grade 2--<<--<<--<<
template<const int N>
void Control<N>::virtualD2(double q[N]){
	
	double theta_p[N]; // Virtual velocity
	double theta_pp[N]; // Virtual acceleration
	
	for(int n=0 ; n<N ; n++){ // Articulations cycle
		
		// theta(^pp) = [K1*(q-theta) - D*theta(^p)]/K2
		theta_pp[n] = (K1[n]*(q[n] - theta[n]) - D[n]*theta_p[n])/K2; // Dynamic
		
		//Next value for theta
		double y0[2] = {theta[n], theta_p[n]}; // Initial conditions
		double y[2] = {0,0}; // Solution variable
		
		numerics::Taylor<2>(_h_ , theta_pp[n] , y0 , y); // Numeric method
		
		theta[n] = y[0]; // Result = virtual position
		theta_p[n] = y[1]; // Result = virtual velocity
	}
}

#endif
