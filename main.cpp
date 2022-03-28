#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class creature {
	public:
		creature();
		~creature();
};

class DNA {
public:
	DNA();
	~DNA();
};

class creator {
	public:
		creator();
		~creator();	
		double m;
		double x;
		double y;
		double z;
};

class position{
	public:
		position();
		~position();

		double x;
		double y;
		double z;	
};

class velocity{
	public:
		velocity();
		~velocity();

		double x;
		double y;
		double z;	
};

class acceleration{
	public:
		acceleration();
		~acceleration();

		double x;
		double y;
		double z;	
};

class particle {
	public:
		particle();
		~particle();	
		double m;
		double position;
		double velocity;
		double acceleration;
};



double RK4(particle * particle){
	k1 =  h * f(time, acceleration);
	k2 =  h * f(time + h / 2, acceleration + k1);
	k3 =  h * f(time + h / 2, acceleration + k2);
	k4 =  h * f(time + h, acceleration + k3);

	velocity_new = velocity + 1 / 6 * (k1 + 2 * k2 + 2 * k3 + k4); // Magic from tylor series
}

double velocity(particle * particles, double * f){
	for (int i = 0; i < 3; ++i){
		RK4(particles[i]);
	}
	return 
}

void acceleration(particle * particles, double time){
	for (int i = 0; i < 3; ++i){
 // G is missing
		particles[i].ax =	- particles[1].m*(particles[0].x - particles[1].x)/((particles[0].x - particles[1].x)*(particles[0].x - particles[1].x)*(particles[0].x - particles[1].x)) 
							- particles[2].m*(particles[0].x - particles[2].x)/((particles[0].x - particles[2].x)*(particles[0].x - particles[2].x)*(particles[0].x - particles[2].x));

		particles[i].ay =	- particles[1].m*(particles[0].y - particles[1].y)/((particles[0].y - particles[1].y)*(particles[0].y - particles[1].y)*(particles[0].y - particles[1].y)) 
							- particles[2].m*(particles[0].y - particles[2].y)/((particles[0].y - particles[2].y)*(particles[0].y - particles[2].y)*(particles[0].y - particles[2].y));

		particles[i].az =	- particles[1].m*(particles[0].z - particles[1].z)/((particles[0].z - particles[1].z)*(particles[0].z - particles[1].z)*(particles[0].z - particles[1].z)) 
							- particles[2].m*(particles[0].z - particles[2].z)/((particles[0].z - particles[2].z)*(particles[0].z - particles[2].z)*(particles[0].z - particles[2].z));
	}
}




int main(int argc, char const *argv[]){
	srand(time(0));  // Initialize random number generator


	double itr = 0;
	double jackpot = 0;
	cout << "Random numbers between 1 and 10 : " << endl;
	cin >> itr;

	for(int i=0;i<itr;i++){
		if(((rand() % 20) + 1) == 7){
			jackpot++;
		}
	}
	cout << "Total Jackpot : " << jackpot << " Ratio : " << jackpot/itr << endl;  
	return 0; 
}