#include<iostream>
#include<string>
using namespace std;
class CPU
{
public:
	CPU() {};
	CPU(const string&, const double&);
	~CPU();
	string CPU_type() { return cp_type; };
	double CPU_frequency() { return  cp_frequency; };
private:
	string  cp_type;
	double cp_frequency;
};
CPU::CPU(const string &x, const double &y):cp_type(x), cp_frequency(y)
{
}


CPU::~CPU()
{
}


class Disk
{
public:
	Disk() {};
	Disk(const string&,const double &);
	~Disk();
	string Dis_type() { return dis_type; };
	double Dis_cap() { return dis_cap; };

private:
	string dis_type;
	double	dis_cap;

};


Disk::Disk(const string &x, const double &y):dis_type(x),dis_cap(y)
{
}

Disk::~Disk()
{
}



class Computer
{
public:
	Computer(const CPU&,const Disk&);
	~Computer();
	void Print();
private:
	CPU cpu;
	Disk disk;
};

Computer::Computer(const CPU &a, const Disk &b)
{
	cpu = a;
	disk = b;
}

Computer::~Computer()
{
}

void Computer::Print()
{
	cout << "The computer has a cpu and a disk.\n";
	cout << "CPU type: " << cpu.CPU_type() << ", " << "CPU frequency: " << cpu.CPU_frequency() << " GHz\n";
	cout << "disk type: " << disk.Dis_type() << ", " << "disk capacity: " << disk.Dis_cap() << " T\n";

}

int main()
{
	string cpuType, diskType;
	double frequency, capacity;
	cin >> cpuType >> frequency >> diskType >> capacity;
	CPU cpu(cpuType, frequency);
	Disk disk(diskType, capacity);
	Computer computer(cpu, disk);

	computer.Print();
	return 0;
}