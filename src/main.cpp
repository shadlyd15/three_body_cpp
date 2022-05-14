#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "base3d.h"

#ifndef G
	#define G  0.00001
#endif

using namespace std;

class Particle {
	public:
		// Particle():m(0), r(0), v(0), a(0){};
		Particle(){};
		Particle(double m, Base3D r, Base3D v, Base3D a):m(m), r(r), v(v), a(a){};
		void randomize(){
			this->m = rand() % 10;
			this->r.randomize();
			this->v.randomize();
			this->a.randomize();
		};
		~Particle(){};	

		void print(){
			cout << "m: " << m << endl;
			cout << "r: " << r << endl;
			cout << "v: " << v << endl;
			cout << "a: " << a << endl;
		};

		double m;
		Base3D r;
		Base3D v;
		Base3D a;
};

class world{ 

public:
	world(){};
	~world(){};

	void setup(){
		Particle a;
		Particle b;
		Particle c;
		Particle d;
		Particle e;

		// a.print();
		// b.print();
		// c.print();
		// d.print();
		// e.print();
		// d.print();

		particles.push_back(a);
		particles.push_back(b);
		particles.push_back(c);
		// particles.push_back(d);
		// particles.push_back(e);

		// for (auto p = particles.begin(); p != particles.end(); ++p){
	 //    		// cout << position(&(*p), time) << endl;
		// 	(*p).print();
	 //    	}

	}

	void run(){


		for (double time = 0; time < time_span; time = time + h){
			Base3D result;
			for (auto p = particles.begin(); p != particles.end(); ++p){
	    		cout << "Velocity : " << velocity(&(*p), time) << endl;
	    		cout << "Position : " << position(&(*p), time) << endl;
	    	}
		}
	}

private: 
	double h = 0.01;
	double time_span = 500;
	vector<Particle> particles;

	double norm(Base3D b){
	    return sqrt(pow(b.x,2) + pow(b.y,2) + pow(b.z,2));
	}

	Base3D force(Particle * p1, Particle * p2){
		Base3D result;
		if(p1 == p2){
			return result;
		}
		result = (p1->r - p2->r) / pow(norm((p1->r - p2->r)), 3) * G * p1->m * p2->m;
		return result;
	}

	Base3D forces(Particle * p, double &t){
		Base3D result;
	    for (auto i = particles.begin(); i != particles.end(); ++i){
	    		result = result + force(&(*p), &(*i));
	    }
	    return result * -1;
	}

	Base3D acceleration(Particle * p, double &t){
	    return forces(p, t)/p->m;
	}

	Base3D velocity(Particle * p, double &t){
		Base3D k1 = acceleration(p, t);
		Base3D k2 = acceleration(p, t) + k1 * h * 0.5;
		Base3D k3 = acceleration(p, t) + k2 * h * 0.5;
		Base3D k4 = acceleration(p, t) + k3 * h;

		p->v = p->v + (k1 + (k2 * 2) + (k3 * 2) + k4) * 1/6; // Magic from tylor series
		return p->v;
	}

	Base3D position(Particle * p, double &t){
		

		Base3D k1 = velocity(p, t);
		Base3D k2 = velocity(p, t) + k1 * h * 0.5;
		Base3D k3 = velocity(p, t) + k2 * h * 0.5;
		Base3D k4 = velocity(p, t) + k3 * h;

		p->r = p->r + (k1 + (k2 * 2) + (k3 * 2) + k4) * 1/6; // Magic from tylor series
		return p->r;
	}
};


int main(int argc, char const *argv[]){
	srand(time(0));
	world w;
	w.setup();
	w.run();
}