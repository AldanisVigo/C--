/*
//Class Declaration (Triangle.h)
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
using namespace std;

class Triangle{
private:
	double Hypotenuse;
	double Opposite;
	double Adjacent;
public:
	Triangle();
	//Overloaded Constructor
	Triangle(double,double,double);
	//Destructor
	~Triangle();
	void set_hypotenuse(double);
	void set_opposite(double);
	void set_adjacent(double);
	double get_hypotenuse();
	double get_opposite();
	double get_adjacent();
	double sine();
	double cosine();
	double tangent();
};

#endif //TRIANGLE_H
*/	

#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::set_hypotenuse(double nH){
	Hypotenuse = nH;
}
Triangle::set_adjacent(double nA){
	Adjacent = nA;
}
Triangle::set_opposite(double nO){
	Opposite = nO;
}
Triangle::Triangle(){
	cout << "The triangle constructor was called!" << endl;
}
Triangle::Triangle(double nH, double nA, double nO){
	Hypotenuse = nH;
	Adjacent = nA;
	Opposite = nO;
	cout << "The overloaded triangle constructor was called!" << endl;
}
~Triangle(){
	cout << "The triangle distructor was called!" << endl;
}
double Triangle::sine(){
	return Opposite / Hypotenuse;
}
double Triangle::cosine(){
	return Adjacent / Hypotenuse;
}
double Triangle::tangent(){
	return Opposite / Adjacent;
}

