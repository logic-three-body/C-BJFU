#include<iostream>
#include<stdlib.h>
//ͷ�ļ���main�������ṩ����ʵ��template<typename T> class Vector
using namespace std;
template<typename T>
class Vector
{
private:
	T x, y, z;
public:
	Vector() :x(0), y(0), z(0) {}
	Vector(T a, T b, T c) :x(a), y(b), z(c) {}

	Vector(Vector<T>& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
	}
	//friend Vector<T> operator*(const Vector<T>&a,double d);
	//friend Vector<Vector> &operator*(double d, const Vector<T>&a);
	//friend Vector<T> operator+(const Vector<T>&a, const Vector<T>&b);
	//friend Vector<Vector> operator+(const Vector<T>&a, const Vector<T>&b);
	//friend &operator+(Vector &a, Vector &b);
	//template <typename T> //�ػ�����
	friend Vector<T>operator+(const Vector<T>&a, const Vector<T>&b)
	{
		Vector<T> outer;
		outer.x = a.x + b.x;
		outer.y = a.y + b.y;
		outer.z = a.z + b.z;
		return outer;
	}
	//template <typename T> //�ػ�����
	friend Vector<T>operator*(double a, const Vector<T>&b)
	{
		Vector<T> outer;
		outer.x = a * b.x;
		outer.y = a * b.y;
		outer.z = a * b.z;
		return outer;
	}

	//template <typename T>
	friend ostream & operator<<(ostream &os, const Vector &st)
	{
		// TODO: �ڴ˴����� return ���
		os << st.x << " " << st.y << " " << st.z;
		return os;
	}

	//template <typename T>
	friend istream & operator>>(istream &is, Vector &st)

	{
		// TODO: �ڴ˴����� return ���
		is >> st.x >> st.y >> st.z;
		return is;
	}


	//template <typename T>
	friend bool operator==(const Vector<T>&a, const Vector<T>&b)
	{
		const double i = 0.0000001;
		//bool jud;
		if (a.x - b.x <= i && a.y - b.y <= i && a.z - b.z <= i)
			return true;
		else return false;
	}
};

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



