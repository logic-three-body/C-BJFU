#include<iostream>
#include<stdlib.h>
using namespace std;
template<typename T>
class Vector
{
private:
	T x, y, z;
public:
	Vector() :x(0), y(0), z(0) {};
	Vector(T a, T b, T c);
	Vector(Vector<T>& a);
	//friend Vector<T> operator*(const Vector<T>&a,double d);
	//friend Vector<Vector> &operator*(double d, const Vector<T>&a);
	//friend Vector<T> operator+(const Vector<T>&a, const Vector<T>&b);
	//friend Vector<Vector> operator+(const Vector<T>&a, const Vector<T>&b);
	//friend &operator+(Vector &a, Vector &b);
	//template <class T> //特化处理
	friend Vector<T>operator+(const Vector<T>&a, const Vector<T>&b);
	//template <class T> //特化处理
	friend Vector<T>operator*(double a, const Vector<T>&b);

	//template <class T>
	friend ostream & operator<<(ostream &os, const Vector<T> &st);

	//template <class T>
	friend istream & operator>><T>(istream &is, Vector<T> &st);

	//template <class T>
	friend bool operator==(const Vector<T>&a, const Vector<T>&b);
};

//template<class T>
bool operator==(const Vector<T>& a, const Vector<T>& b)
{
	const double i = 0.0000001;
	//bool jud;
	if (abs(a.x - b.x) <= i && abs(a.y - b.y) <= i && abs(a.z - b.z) <= i)
		return true;
	else
		return false;
}

//template<class T>
istream & operator>>(istream &is, Vector<T> &st)
{
	// TODO: 在此处插入 return 语句
	is >> st.x >> st.y >> st.z;
	return is;
}



//template<class T>
ostream & operator<<(ostream &os, const Vector<T> &st)
{
	// TODO: 在此处插入 return 语句
	os << st.x << " " << st.y << " " << st.z;
	return os;
}


//template<class T>
Vector<T>operator+(const Vector<T>&a, const Vector<T>&b)
{
	Vector<T> outer;
	outer.x = a.x + b.x;
	outer.y = a.y + b.y;
	outer.z = a.z + b.z;
	return outer;
}

//template<class T>
Vector<T>operator*(double a, const Vector<T>&b)
{
	Vector<T> outer;
	outer.x = a * b.x;
	outer.y = a * b.y;
	outer.z = a * b.z;
	return outer;
}

template<typename T>
Vector<T>::Vector(T a, T b, T c) :x(a), y(b), z(c)
{

}

template<typename T>
Vector<T>::Vector(Vector<T>& a)
{
	x = a.x;
	y = a.y;
	z = a.z;
}

//template<typename T>
Vector<T> operator*(const Vector<T>&a, double d)
{
	a.x *= d;
	a.y *= d;
	a.z *= d;
	return a;
}
//template<typename T>
//Vector<T> &operator*( double d, const Vector<T>&a)
//{
//	a.x *= d;
//	a.y *= d;
//	a.z *= d;
//	return a;
//}




//template<typename T>
//Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
//{
//	a.x += b.x;
//	a.y += b.y;
//	a.z += b.z;
//	return a;
//}

int main()
{
	double a, b, c;
	std::cin >> a >> b >> c;
	Vector<double> v1(a, b, c), v2(v1), v3, v4;
	double d;
	std::cin >> d;
	v4 = (d*v1) + v2;

	std::cout << v4 << std::endl;

	Vector<double>  v;
	std::cin >> v;

	int flag = (v4 == v);
	std::cout << flag << std::endl;

	return 0;
}



