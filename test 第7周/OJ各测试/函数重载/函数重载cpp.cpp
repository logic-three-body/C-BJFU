#include<iostream>
#include<algorithm>
using namespace std;
int Max(int a,int b);
float  Max(float d, float e, float f);
int main()

{

	int a, b;

	float d, e, f;

	cin >> a >> b;

	cin >> d >> e >> f;

	int m;

	m = Max(a, b);

	cout << "max_i=" << m << endl;

	float n;

	n = Max(d, e, f);

	cout << "max_f=" << n << endl;

	return 0;
}
int Max(int a, int b)
{
	if (a < b) return b;
	else return a;
}
float  Max(float d, float e, float f)
{
	float *a = new float[3]();
	a[0] = d;
	a[1] = e;
	a[2] = f;
	sort(a, a + 3);
	return a[2];
}
