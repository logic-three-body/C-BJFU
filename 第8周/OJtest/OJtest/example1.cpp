#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);

class Circle
{
public:
	void count(double r);
private:
	double radius=0;

};
void Circle::count(double r)
{
	radius = r*r*PI;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << radius;
}
int main()
{
	double r;
	cin >> r;
	Circle area;
	area.count(r);
	return 0;
}