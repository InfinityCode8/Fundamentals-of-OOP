#include <iostream>
#include<Windows.h>
using namespace std;


class Computer // ���� ����'���� � �������������: ������� ��������� (���), ������� ����, ��'�� ���'�� (��), ��'�� ��������� ����� (��)
{
public:

	int cpu; // ������� ��������� (���)
	int cores; // ʳ������ ����
	int memory; // ��'�� ���'�� (��)
	int hard_disk; // ��'�� ��������� ����� (��)
	
	Computer(int comp_cpu, int comp_cores, int comp_memory, int comp_hard_disk) // ����������� �����
	{
		cpu = comp_cpu;
		cores = comp_cores;
		memory = comp_memory;
		hard_disk = comp_hard_disk;
	}

	virtual bool Suitability() // ������� ����� "����������"
	{
		if ((cpu >= 2000) && (cores >= 2) && (memory >= 2048) && (hard_disk >= 320))
		{
			cout << "����'���� ���������" << endl;
			return true;
		}
		else
		{
			cout << "����'���� �� ���������" << endl;
			cout << "��������� ������: " << endl << "������� ��������� ���������� 2000 ���; " << endl << "ʳ������ ���� ���������� 2; "\
				<< endl << "��'�� ���'�� ���������� 2048 ��;" << endl << "��'�� ��������� ����� ���������� 320 ��. " << endl << endl;
			return false;
		}
	}

	virtual float Cost(int cpu, int cores, int memory, int hard_disk) // ����� "�������", �� ������� ������� ��������� ������������ ������� ����'�����
	{
		return (cpu * cores / 100 + memory / 80 + hard_disk / 20);
	}

	virtual void Info() // ����� ����������
	{
		cout << "������� ��������� = " << cpu << " ���" << endl;
		cout << "ʳ������ ���� = " << cores << endl;
		cout << "��'�� ���'�� = " << memory << " ��" << endl;
		cout << "��'�� ��������� ����� = " << hard_disk << " ��" << endl << endl;
		cout << "����������: " << boolalpha << Suitability() << endl;
		cout << "�������: " << Cost(cpu, cores, memory, hard_disk) << " Usd" << endl;
		cout << "-------------------------------------------------------------" << endl << endl;
	}
};

class Laptop : public Computer //���� �������
{
	int duration; //��������� ��������� ������ (� ��������) 

public:

	Laptop(int comp_cpu, int comp_cores, int comp_memory, int comp_hard_disk, int Lap_duration): Computer(comp_cpu, comp_cores, comp_memory, comp_hard_disk)
	{
		duration = Lap_duration;
	}
	

	bool Suitability() override// �������������� ������� ����� "����������"
	{
		if ((cpu >= 2000) && (cores >= 2) && (memory >= 2048) && (hard_disk >= 320) && (duration >= 60))
		{
			cout << "������� ���������" << endl;
			return true;
		}
		else
		{
			cout << "������� �� ���������" << endl;
			cout << "��������� ������: " << endl << "������� ��������� ���������� 2000 ���; " << endl << "ʳ������ ���� ���������� 2; "\
				<< endl << "��'�� ���'�� ���������� 2048 ��;" << endl << "��'�� ��������� ����� ���������� 320 ��;"\
				<< endl << "��������� ��������� ������ (� ��������) ���������� 60. " << endl << endl;
			return false;
		}
	}

	float Cost(int cpu, int cores, int memory, int hard_disk) override // �������������� ����� "�������", �� ������� ������� ��������� ������������ ������� ��������
	{
		return Computer::Cost(cpu, cores, memory, hard_disk) + (duration / 10);
	}

	void Info() override // �������������� ����� ���������� 
	{
		cout << "��������� ��������� ������ = " << duration << " ��" << endl << endl;
		Computer::Info();
	}

};
void main()
{
	SetConsoleOutputCP(1251);

	Computer Asus(2666, 6, 9000, 400);
	Asus.Info();
	Computer LG(2666, 1, 9000, 200);
	LG.Info();

	Laptop hp(2500, 4, 8000, 500, 70);
	hp.Info();
	Laptop Lenovo(1000, 8, 2000, 600, 40);
	Lenovo.Info();
}