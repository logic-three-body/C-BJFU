#include <iostream>
#include <cstring>
using namespace std;

class Vehicle
{
public:
	Vehicle();
	~Vehicle();
	virtual void display()=0;

protected:
	char carname[110];
	char carcolor[110];
	int guestnum;
	double weight;

};


Vehicle::Vehicle()
{

}

Vehicle::~Vehicle()
{

}

class Truck:public Vehicle
{
public:
	
	~Truck();
	Truck(const char*, const char*, double);
	virtual void display();
private:
	

};

Truck::Truck(const char* a, const char* b, double c)
{
	
	strcpy(carname, a);
	strcpy(carcolor, b);
	weight = c;
}

inline void Truck::display()
{
	cout << "Truck name:" << carname << " Truck color:" << carcolor << " Truck capacity:" << weight << endl;
}

Truck::~Truck()
{
}

class Car:public Vehicle
{
public:
	Car(const char*, const char*, int);
	~Car();
	virtual void display();
private:

};

Car::Car(const char*a, const char*b, int c)
{
	strcpy(carname, a);
	strcpy(carcolor, b);
	guestnum = c;
}

Car::~Car()
{
}

inline void Car::display()
{
	cout << "Car name:" << carname << " Car color:" << carcolor << " Car passager:" << guestnum << endl;
}
int main() {

 Vehicle *p;

 char type;

 char name[110],color[110];

 int pas;

 double cap;

 while(cin>>type){

 cin>>name>>color;

if(type == 'C'){

cin>>pas;

Car car(name,color,pas);

p = &car;

p->display();

}else if(type == 'T'){

cin>>cap;

Truck truck(name,color,cap);

p = &truck;

p->display();

}

 }

 return 0;

}