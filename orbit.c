//Chris Conklin
//Oribital reentry
//SI units
#include <stdio.h> //for printf
#include <math.h> //for sqrt


int main()
{
	//Parameters
	double G = 6.67E-11; //Nm^2/kg^2 -- Gravitational constant
	double me = 5.97E24; //kg -- Earth mass
	double mc = 1355; //kg -- capsule mass
	double capsule_force = 6*107; //N -- capsule thrust
	double re = 6371E3; //m -- radius of earth
	double dt = 0.1; //s -- time step, large because it takes awhile to complet an orbit
	double t_burn=500; //s -- time my rocket thrusters will be on

	//Intital Values -- we start with capsule moving in y direction, 260 km above surface
	double x = re+260E3; //m
	double y = 0;	//m
	double r = sqrt(x*x+y*y); 
	double vx = 0; //m/s
	double vy = 7750; //m/s -- initial velocity for a circular orbit
	double v = sqrt(vx*vx+vy*vy);
	double Fx = -G*me*mc*x/pow(r,3); //N -- initial x force
	double Fy = -G*me*mc*y/pow(r,3); //N -- initial y force
	double ax = Fx/mc; //m/s^2
	double ay = Fy/mc; //m/s^2
	double t = 0; //s -- initial time


	while (r > re) //Stop when the capsule is on the earth's surface
	{
		//Time
		t = t+dt;
		//Position
		x = x + vx*dt;
		y = y + vy*dt;
		r = sqrt(x*x+y*y);
		//Velocity
		vx = vx + ax*dt;
		vy = vy + ay*dt;
		v = sqrt(vx*vx+vy*vy); //Here I am updating a velocity magnitude to use is thrust force	
		//Force
		Fx = -G*me*mc*x/pow(r,3);
		Fy = -G*me*mc*y/pow(r,3);
		if (t<t_burn) //if we are less than the max burn time, add the thrust to our total force
		{
			Fx+= -capsule_force*vx/v;
			Fy += -capsule_force*vy/v;
		}	
		//Acceleration
		ax = Fx/mc;
		ay = Fy/mc;
		
		//Emergency stop to keep program from running forever
		if (t > 100000)
		{
			printf("Still not on earth after 100000 seconds");
			break; //This ends the loop
		}
	}
	printf("Time = %f\n", t);	
	printf("angle = %f\n",atan2(y,x)*180/M_PI);
	

	return 0;

}




