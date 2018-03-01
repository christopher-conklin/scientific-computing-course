//Chris Conklin
//Projectile motion examples
//SI units
#include <stdio.h> //for printf
#include <math.h> //for sin and cos

/*
   This code gives an example of projectile motion with air resistance
   I took my Euler's method loop and put it into a function so I could see what
   launch angle produced the maximum horizontal distance travelled.

*/

//Function to compute the x distance travelled for a given launch angle input
double distance_launch_degree(double u_deg) //my input is the angle in degrees
{
	//Constants
	double rho = 1.2; //kg/m^2 -- density of air
	double A = 0.01; //m^2 -- cross sectional area of the sphere
	double C_d = 0.47; // drag coefficient for sphere
	double m = 1.0; //kg -- mass os sphere
	//Initial values
	double ay = -9.8;
	double ax=0;
	double u_rad = u_deg*3.141592653/180; //must convert degrees to radians
	double v_mag = 50;
	double vx = v_mag*cos(u_rad), vy = v_mag*sin(u_rad);
	double x=0, y=0;
	double t=0, dt=0.001;
	do{		//I'm using do instead of while because the first 
			//iteration will have y = 0, so if I used while
			//the loop wouldn't start. After the first iteration
			//the y value is greater than zero so I'm ok to loop
		x += vx*dt;
		y += vy*dt;
		vy += ay*dt;
		vx += ax*dt;
		//The acceleration has an air resistance component (see Wikipedia)
		//and gravitational acceleration (in the y direction only)
		//The air resistance is in the opposite direction of the velocity
		//and is proportional to the velocity squared.
		ax = -rho*C_d*A/(2*m)*sqrt(vx*vx+vy*vy)*vx;
		ay = -rho*C_d*A/(2*m)*sqrt(vx*vx+vy*vy)*vy-9.8;
		t+=dt;

	}while(y>0.0);
	//printf("%f \t %f \t %f \t %f \n", u_deg, u_rad,y,x); //This prints the final x position and y position as well as the angle. I used it only for testing, so it is otherwise commented out

	return x; //output is the distance this projectile traveled
}

int main()
{
	//Here I write a loop to try to find what the max distance is. The goal
	//is to iterate through a variety of angles, and when a new max distance
	//is found, I set max_dist to that distance and umax to that angle.
	//Basically umax and max_dist act like a leaderboard with the current
	//high score. By the end I know it will have the highest angle found

	double umax; //find the angle that maximizes the distance
	double max_dist = -1.0; //max distance found, set to negative to be sure the first one gets stored
	double dist; //use to to store the distance at each step
	for(double u = 0; u<=90; u+=0.5)
	{
		dist = distance_launch_degree(u); //I set the dist equal to the distance travelled for this variable u
		if(dist > max_dist) //Check if it is larger than the current largest
		{
			umax = u;	//If it is I update umax and max_dist
			max_dist = dist;
		}

	}
	//After the loop umax and max_dist correspond to the largest distance travelled
	printf("Max launch: %.2f\t Angle: %.2f\n", max_dist, umax);

	return 0;
}
