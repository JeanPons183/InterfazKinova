#ifndef Simulation_h
#define Simulation_h

#include <iostream>
#include "Robot.h"
#include "Controls.h"

using namespace std;

// DEFINITIONS

// CLASS

template<const int N> // DOF Number of the Robot
class Sim{
	
	// >>-->>-->>-- Properties --<<--<<--<<
	
	unsigned int t = 0; // Simulation time in _h = h*h_
	
	unsigned int T = h_; // (Period) Sample step time in _h; h = _h/h_ seconds -> T = 1 second
	unsigned int t_sample=0; // Current time sample
	unsigned int s=0; // Number of samples
	
	Robot<N> bot; // Robot object
	Control<N> ctrl; // Control object
	
	string props[4] = {"q","qp","qpp","tau"}; // Order to save and show data
	
	public:
		
		unsigned int Time = 0; // Time of Simulation
		unsigned int S = 0; // Number of samples
		
		double t_set[10000]; // Length of Samples
		double data_set[10000][N][4]; // [samples][DOF][properties]. Properties: q, qp, qpp, tau
		
		// >>-->>-->>-- CONSTRUCTOR --<<--<<--<<
		Sim(Robot<N> *_bot , Control<N> *_ctrl) // Get the robot and control
		{
			bot = *_bot;
			ctrl = *_ctrl;
		}
		~Sim(){ // Deconstructor
			cout<<"\n Freesed!"<<endl;
		}
		
		void Cycle(void); // Cycle of simulation (Robot and Control)
		
	private:
		
		void SaveData(void); // Save data (q,qp,qpp,tau) function
		
		void show_Data_v(string); // Show data in vertical form
		void show_Data_h(string); // Show data in horizontal form
	
};

// FUNCTIONS

// >>==>>==>>==>>==>>== CYCLE SIMULATION ==<<==<<==<<==<<==<<=
template<const int N>
void Sim<N>::Cycle(void){
	
	T = Time/S; // Period of samples
	
	Ctrl_Law_Type<N> CTRL; // Controler pointer data
	CTRL = ctrl.setControl(); // Choose controler
	
	//  >>==>>==>>== Simulation cicle ==<<==<<==<<
	while(t <= Time){
		
		// =--=--=-- Control --=--=--=
		(ctrl.*CTRL)(bot.q , bot.qp , bot.tau);

		// =--=--=-- Run Robot --=--=--=
		SaveData(); // Save robot data
		bot.Play(); // Active robot
		
		t+=_h; // Next time
	}
	
	show_Data_v("\tTime: ");
	
}

// >>==>>==>>==>>==>>== SAVE DATA ==<<==<<==<<==<<==<<=
template<const int N>
void Sim<N>::SaveData(void){

	if(t >= t_sample){ // Current sample time

		t_set[s] = t/h_; // Save current time

		for(int n=0 ; n<N ; n++){
            data_set[s][n][0] = bot.q[n]*180/PI; // Save current position
            data_set[s][n][1] = bot.qp[n]*180/PI; // Save current velocity
            data_set[s][n][2] = bot.qpp[n]; // Save current acceleration
            data_set[s][n][3] = bot.tau[n]; // Save current force
		}

		t_sample += T; // Next sample time
		s++; // Next sample number
	}
}


//* >>==>>==>>==>>==>>== SHOW DATA in VERTICAL==<<==<<==<<==<<==<<
template<int N> 
void Sim<N>::show_Data_v(string title){
	
	int s,n,p; // samples, articulations, properties
	
	for(s=0 ; s<S ; s++){ // Samples cycle
		cout<<"______________________________________________________________________________________________________________________"<<endl;
		cout<<"|  "<<title<<t_set[s]<<" seconds."<<endl; // Print title and time
		cout<<"|---------------------------------------------------------------------------------------------------------------------"<<endl;
		
		cout<<"| Arts.\t| "; // First column
		for(p=0 ; p<4 ; p++) // Print subtitles
			cout<<props[p]<<"\t\t| ";
		cout<<"\n|---------------------------------------------------------------------------------------------------------------------";
		
		for(n=0 ; n<N ; n++){ // Articulations cycle
			cout<<"\n| "<<n+1<<"\t| "; // Articulation number
			
			for(p=0 ; p<4 ; p++){ // Properties cycle
				int d = round(data_set[s][n][p]*1000); // Set to 3 decimals
				string num = to_string((double)d/1000); // Change to string
				
				if(d>0) // Include '+' symbol
					num = "+" + to_string((double)d/1000); // Change to string
				
				cout<<num.substr(0,6)<<"\t| "; // Print data	
			}
		}
		cout<<"\n----------------------------------------------------------------------------------------------------------------------"<<endl; // End line
		cout<<"######################################################################################################################"<<endl;
	}	
}
//*/


//* >>==>>==>>==>>==>>== SHOW DATA in HORIZONTAL==<<==<<==<<==<<==<<
template<int N> 
void Sim<N>::show_Data_h(string title){
	
	int n,p; // number of articulations, properties
	
	for(s=0 ; s<S ; s++){ // Samples cycle
		cout<<"______________________________________________________________________________________________________________________"<<endl;
		cout<<"|  "<<title<<t_set[s]<<" seconds."<<endl; // Print title and time
		cout<<"|---------------------------------------------------------------------------------------------------------------------"<<endl;
		
		cout<<"| Arts.\t|\t"; // First row
		for(n=0 ; n<N ; n++) // Articulation number
			cout<<n+1<<"\t| ";
		cout<<"\n|---------------------------------------------------------------------------------------------------------------------";
		
		for(p=0 ; p<4 ; p++){ // Properties cycle
			cout<<"\n| "<<props[p]<<"\t| "; // Properties
			
			for(n=0 ; n<N ; n++){ // Columns cycle
				int d = round(data_set[s][n][p]*1000); // Set to 3 decimals
				string num = to_string((double)d/1000); // Change to string
				
				if(d>0) // Include '+' symbol
					num = "+" + to_string((double)d/1000); // Change to string
				
				cout<<num.substr(0,6)<<"\t| "; // Print data	
			}
		}
		cout<<"\n----------------------------------------------------------------------------------------------------------------------"<<endl; // End line
		cout<<"######################################################################################################################"<<endl;
	}	
}
//*/


#endif
