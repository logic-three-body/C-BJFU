#include<iostream>
using namespace std;
template<typename T>
class Vector
{
private:
	T x, y, z;
public:
	Vector() :x(0), y(0), z(0) {};
	Vector(T a,T b,T c);
	Vector(Vector<T>& a);
	friend Vector<T> operator*(const Vector<T>&a,double d);
	friend Vector<T> operator+(const Vector<T>&a, const Vector<T>&b);
};
template<typename T>
Vector<T>::Vector(T a, T b, T c):x(a),y(b),z(c)
{

}

template<typename T>
Vector<T>::Vector(Vector<T>& a)
{
	x = a.x;
	y = a.y;
	z = a.z;
}

template<typename T>
Vector<T> operator*(const Vector<T>&a,double d)
{
	a.x *= d;
	a.y *= d;
	a.z *= d;
	return a;
}


template<typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

int main()
{
	double a, b, c;
	std::cin >> a >> b >> c;
	Vector<double> v1(a, b, c), v2(v1), v3, v4;
	double d;
	std::cin >> d;
	v4 = v1*d + v2;

	//std::cout << v4 << std::endl;

	//Vector<double>  v;
	//std::cin >> v;

	//int flag = (v4 == v);
	//std::cout << flag << std::endl;

	return 0;
}
