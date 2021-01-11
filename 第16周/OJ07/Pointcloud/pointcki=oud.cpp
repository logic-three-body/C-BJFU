#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>
using namespace std;

string header;
struct Point
{
	double XYZ[3];
	int RGB[3];
};

int readPoints(const string &path,vector<Point>&vP) {
	fstream ifs(path, ios::in);//�����ļ���
	if (!ifs)//����ʧ��
	{
	//	cerr << "Fail\a " << path << endl;
		return -1;
	}

	string line;
	int Rows = 0;
	vP.clear();

	//������
	getline(ifs, line);
	::header = line;
	while (getline(ifs, line))
	{
		Rows++;
		stringstream sstr(line);
		string temp;
		Point p = { 0,0 };
		int column = 0;//��ȡ��������,֮����RGB����
		//��ȡ��������
		while (column<3&&getline(sstr,temp,','))//col����߱���column�ж�ʧ��ʱִ��getline��������
		{
			stringstream value(temp);
			double dvalue = -1;
			if (!(value >> dvalue))//δ�ɹ�д�����ݣ��ļ��ر�
			{
				//cerr << "Fail at \a" << Rows << endl;
				ifs.close();
				return -2;
			}
			p.XYZ[column++] = dvalue;
		}
		//��ȡRGB
		while (column < 6 && getline(sstr, temp, ','))//col����߱���column�ж�ʧ��ʱִ��getline�������� 244407
		{
			stringstream value(temp);
			int ivalue = -1;
			if (!(value >> ivalue))
			{
				//cerr << "failed at " << Rows << endl;
				ifs.close();
				return -3;
			}
			p.RGB[column++ - 3] = ivalue;//�����㣬��++����֤RGB�����0��ʼ
		}
		vP.push_back(p);

	}

	ifs.close();
	return 0;
}

int calGrav_center(const string &path, vector<Point>&vP) {
	//return 0;
	unsigned num = vP.size();
	if (!num)
	{
		//cerr << "erro\a" << endl;
		return -1;
	}
	fstream of(path, ios::app);
	if (!of)
	{
		//cerr << "fail at\a " << path << endl;
		return -2;
	}

	double x_to_grav(0), y_to_grav(0), z_to_grav(0);
	for (Point p : vP)
	{
		x_to_grav += p.XYZ[0];
		y_to_grav += p.XYZ[1];
		z_to_grav += p.XYZ[2];
	}
	x_to_grav /= num;
	y_to_grav /= num;
	z_to_grav /= num;

	of << fixed << setprecision(3);
	of <<endl<< x_to_grav << "," << y_to_grav << "," << z_to_grav<<" success\n";
	of.close();
	return 0;
}

int shiftPoints(const string &path, vector<Point>&vP) {
	unsigned num = vP.size();
	if (!num)
	{
		//cerr << "erro\a" << endl;
		return -1;
	}
	fstream of(path, ios::out);
	of << fixed << setprecision(3);
	of << ::header << endl;

	vector<Point>::iterator it;
	for (it = vP.begin(); it != vP.end(); ++it)
	{
		it->XYZ[0] += 100;
		it->XYZ[1] -= 50;

		of << it->XYZ[0] << "," << it->XYZ[1] << "," << it->XYZ[2] << "," << it->RGB[0] << "," << it->RGB[1] << "," << it->RGB[2] << endl;
	}


	of.close();
	return 0;
}

void processPoints() {
	string path("D:\\English_only\\cpp\\points.csv");
	string path_offset("D:\\English_only\\cpp\\points_offset.csv");
	vector<Point>pc;
	readPoints(path, pc);
	calGrav_center(path, pc);
	shiftPoints(path_offset, pc);
}

int main() {
	std::cout << "Point cloud in processing..." << endl;
	processPoints();
	return 0;
}