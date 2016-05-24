#include <iostream>
#include "Triangle.h"
using namespace std;
int main(int argc, char** argv){
	double H = 0.0,O = 0.0,A = 0.0;
	Triangle* myTriangle = new Triangle();
	cout << "Enter the size of the Hypotenuse:";
	cin >> H;
	myTriangle->set_hypotenuse(H);
	system("clear");
	cout << "Enter the size of the Opposite Side:";
	cin >> O;
	myTriangle->set_opposite(O);
	system("clear");
	cout << "Enter the size of the Adjacent Side:";
	cin >> A;
	myTriangle->set_adjacent(A);
	system("clear");
	cout << "Trigonometric Functions of Triangle:" << endl;
	cout << "Sine:" << myTriangle->sine() << endl;
	cout << "Cosine:" << myTriangle->cosine() << endl;
	cout << "Tangent:" << myTriangle->tangent() << endl;
	return 0;
}
