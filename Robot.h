#ifndef Robot_h
#define Robot_h

//LIBRARIES
#include <iostream>
#include <conio.h>

#include "Numerics.h"

#define PI acos(-1)

using namespace std;

// Enum for robot properties
enum Props {_q_ , _qp_ , _qpp_ , _tau_};

// >>-->>-->>-->>-->>-- CLASS --<<--<<--<<--<<--<<

template<const int N> // N = number of articulations
class Robot{
	
	void (*Dynamic)(double[N], double[N], double[N], double*); // Articulations dynamics function
	
	public:
		
		// >>-->>-->>-- PROPERTIES --<<--<<--<<
		
		void (*Intertia)(double[N],double[][N]); // Inertia Matrix
		void (*Coriolis)(double[N],double[][N]); // Coriolis Matrix
		void (*Gravity)(double[N],double*); // Gravity Vector
		
		// Articulations Arrays
		double q[N]; // Position
		double qp[N]; // Velocity
		double qpp[N]; // Acceleration
		double tau[N]; // Torques
		
		string arts; // Type of articulations array
		
		
		// >>-->>-->>-- Constructor --<<--<<--<<
		Robot(){ // Void constructor
			initRobot(); // Initialize properties
		}
		Robot(string _arts, void (*_Dynamic)(double[N], double[N], double[N], double*)){ // Construct with Dynamic
			arts = _arts; // Type of articulations array
			Dynamic = _Dynamic; // Dynamic function pointer
			
			initRobot(); // Initialize properties
		}
		
		//Deconstructor
		~Robot(){
			cout<<"\nYou Killed a ROBOT </3\n"<<endl;
		}
		
		
		// >>-->>-->>-- METHODS --<<--<<--<<
		
		//Initialize Robot Function
		void initRobot(void){
			for(int n=0 ; n<N ; n++){ // Initialize vectors
				q[n] = 0;
				qp[n] = 0;
				qpp[n] = 0;
				tau[n] = 0;
			}
		}
		
		//Dynamics Function
		void D(double _tau[N], double _q[N], double _qp[N], double* _qpp){		
			(*Dynamic)(_tau, _q, _qp, _qpp);		
		}
		
		// Play function
		void Play(void);
		
		// Save data function
		void SaveData(double* t_set, double data[][N]); // T = sample time
};


// >>-->>-->>-->>-->>-- FUNCTIONS --<<--<<--<<--<<--<<

// =--=--=- PLAY -=--=--=
template<const int N>
void Robot<N>::Play(void){
	
	(*Dynamic)(tau, q, qp, qpp); // Dynamic evaluation = qpp
	
	// Next positions and velocities
	for(int n=0 ; n<N ; n++){
		
		double y0[2] = {q[n] , qp[n]}; // Initial conditions for articulation 'n'
		double y[2] = {0,0}; // Array auxiliar (result)
		
		numerics::Taylor<2>(_h_ , qpp[n] , y0 , y); // Numeric method
		
		q[n] = y[0]; // New position
		qp[n] = y[1]; // New velocity
		
	}
	
	//cout<<"Lets play!"<<endl;
}

#endif
