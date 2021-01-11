#include<iostream>
#include<string>
using namespace std;
class Animal
{
public:
	Animal(const string&,const string&,const bool&);
	~Animal();
	string Type() { return an_type; };
	string Color() { return an_color; };
	//bool Ost() { return an_ost; }
	//bool Day() { return an_daytime; }
	bool Jud(){ return jud; };
	virtual void Print() {};
private:
	string an_type;
	string an_color;
	//bool an_ost,an_daytime;
	bool jud;
};

Animal::Animal(const string&a, const string&b, const bool&c):an_type(a),an_color(b),jud(c)
{
}

Animal::~Animal()
{
}

class  Fish:public Animal
{
public:
	 Fish(const string&,const string&,const bool&);
	~ Fish();
	virtual void Print();
private:

};

Fish::Fish(const string &a, const string &b, const bool &c):Animal(a,b,c)
{

}

 Fish::~ Fish()
{
}
 void Fish::Print()
 {
	 cout << "type: " << Type() << ", " << "color: " << Color() << ", " << "Osteichthyes: " << Jud() << endl;
 }

 class Bird:public Animal
 {
 public:
	 Bird(const string&, const string&, const bool&);
	 ~Bird();
	 virtual void Print();
 private:

 };

 Bird::Bird(const string &a, const string &b, const bool &c) :Animal(a, b, c)
 {
 }

 Bird::~Bird()
 {
 }

 void Bird::Print()
 {
	 cout << "type: " << Type() << ", " << "color: " << Color() << ", " << "daytime: " << Jud() << endl;
 }

 int main()
 {
	 Animal *animal;
	 string type, color;
	 bool Osteichthyes, daytime;
	 cin >> type >> color >> Osteichthyes;
	 Fish fish(type, color, Osteichthyes);
	 fish.Print();
	 animal = &fish;
	 animal->Print();
	 cin >> type >> color >> daytime;
	 Bird bird(type, color, daytime);
	 bird.Print();
	 animal = &bird;
	 animal->Print();
	 return 0;
 }