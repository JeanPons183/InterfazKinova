#ifndef Numerics_h
#define Numerics_h

//LIBRARIES
#include <iostream>
#include <cmath>

//CONSTANTS

// Step time: h = _h/h_ seconds
#define _h 1.0 // Integer
#define h_ 1000.0 // Integer
#define _h_ _h/h_ // Double: seconds

//FUNCTIONS

int fact(int x){ // Factorial function = x!
	
	if(x<1){ return 1; }
	else{
		int n=1;
		for(int i=2; i<=x ; i++){ n*=i; }
		return n;
	}	
}

namespace numerics{
	
	// Taylor Method
	template<int n>
	void Taylor(const double h, double dY0, double y0[n-1], double* y){
		
		/*
		
		VARIABLES:
		
		'n' is the grade of the differential equation
		'h' is the time step
		'y0' are the initial conditions = [y0, y0', y0'', ... y0{^(n-1)}]
		'dY0' is the result of the last derivate = y0{^n}
		'y' is a vector of next values = [y, y', y'', ... y{^(n-1)}]
		
		EQUATIONS: i=n
		
		y = y0 + h*y0' + (h^2)*(y0'')/2 + (h^3)*(y0{^3})/3! + ... + (h^i)*(dY0)/i! 
		y' = y0' + h*y0'' + (h^2)*(y0{^3})/2 + ... + (h^[i-1])*(dY0)/(i-1)!
		y'' = y0'' + h*y0{^3} + ... + (h^[i-2])*(dYn)/i!
		...
		y{^(i-1)} = y0{^(i-1)} + h*(dY0)
		
		*/
		
		for(int i=0 ; i<n ; i++){ // Varible y^(n) cicle 
			for(int j=i ; j<n ; j++){ // Taylor succession terms
				
				y[i] += y0[j]*pow(h,j-i)/fact(j-i); // Terms = (h^[j-i])*(y{^j})/(j-i)!
		
			}
			y[i] += dY0*pow(h,n-i)/fact(n-i); // Term = (h^[n-i])*(dY0)/(n-i)!
		}	
	}
	
}

#endif
