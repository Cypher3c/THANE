#ifndef OBJECTS_J_H_INCLUDED
#define OBJECTS_J_H_INCLUDED

#include <string>

//Universe Object, base class
class Universe {
public:

    void SetName();

private:
char Name[];

};

//Sys object; Describes each individual system, derived from base class
class Sys : public Universe {
public:
    //Default Sys constructor
	Sys();
	//Constructer that takes arguments
	Sys(float x, float y, float rad, int stars, float interfer);
	//Destructor
	~Sys();
	//Functions for returning Sys parameters
	float Get_x();
	float Get_y();
	float Get_radius();
	float Get_interference();
	int Get_stars();
	//Function to return pointer to next Sys object
	Sys GetNext();

	//TODO: Need something to handle deletion of system, fix pointer list in this case
private:
	//System parameters
	float x_loc;
	float y_loc;
	float radius;
	int num_stars;
	float interference;
	float nebu_density;
	float nebu_volatility;
	//Array of Planets and stations
	char *Assets[];
	//Pointer to next Sys object (linked list)
	Sys *Next;
};
//Define Sys member functions
Sys::Sys(float x, float y, float rad, int stars, float interfer) {
	x_loc = x;
	y_loc = y;
	radius = rad;
	num_stars = stars;
	interference = interfer;
	//TODO: Insert LINKED list stuff here
}
float Sys::Get_x() {
	return x_loc;
}
float Sys::Get_y() {
	return y_loc;
}
float Sys::Get_radius() {
	return radius;
}
float Sys::Get_interference() {
	return interference;
}
int Sys::Get_stars() {
	return num_stars;
}

class Asset {
public:


private:



};

#endif // OBJECTS_J_H_INCLUDED
