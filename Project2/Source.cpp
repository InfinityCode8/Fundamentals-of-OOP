#include <iostream>
#include<Windows.h>
using namespace std;


class Computer // Клас Комп'ютер з властивостями: Частота процесора (МГц), кількість ядер, об'єм пам'яті (МБ), об'єм жорсткого диска (ГБ)
{
public:

	int cpu; // Частота процесора (МГц)
	int cores; // Кількість ядер
	int memory; // Об'єм пам'яті (МБ)
	int hard_disk; // Об'єм жорсткого диска (ГБ)
	
	Computer(int comp_cpu, int comp_cores, int comp_memory, int comp_hard_disk) // Конструктор класу
	{
		cpu = comp_cpu;
		cores = comp_cores;
		memory = comp_memory;
		hard_disk = comp_hard_disk;
	}

	virtual bool Suitability() // Логічний метод "Придатність"
	{
		if ((cpu >= 2000) && (cores >= 2) && (memory >= 2048) && (hard_disk >= 320))
		{
			cout << "Комп'ютер придатний" << endl;
			return true;
		}
		else
		{
			cout << "Комп'ютер не придатний" << endl;
			cout << "Невідповідає умовам: " << endl << "Частота процесора щонайменше 2000 МГц; " << endl << "Кількість ядер щонайменше 2; "\
				<< endl << "Об'єм пам'яті щонайменше 2048 МБ;" << endl << "Об'єм жорсткого диска щонайменше 320 Гб. " << endl << endl;
			return false;
		}
	}

	virtual float Cost(int cpu, int cores, int memory, int hard_disk) // Метод "Вартість", що повертає повертає приблизну розрахункову вартість комп'ютера
	{
		return (cpu * cores / 100 + memory / 80 + hard_disk / 20);
	}

	virtual void Info() // Метод інформації
	{
		cout << "Частота процесора = " << cpu << " МГц" << endl;
		cout << "Кількість ядер = " << cores << endl;
		cout << "Об'єм пам'яті = " << memory << " МБ" << endl;
		cout << "Об'єм жорсткого диска = " << hard_disk << " ГБ" << endl << endl;
		cout << "Придатність: " << boolalpha << Suitability() << endl;
		cout << "Вартість: " << Cost(cpu, cores, memory, hard_disk) << " Usd" << endl;
		cout << "-------------------------------------------------------------" << endl << endl;
	}
};

class Laptop : public Computer //Клас нащадок
{
	int duration; //Тривалість автономної роботи (у хвилинах) 

public:

	Laptop(int comp_cpu, int comp_cores, int comp_memory, int comp_hard_disk, int Lap_duration): Computer(comp_cpu, comp_cores, comp_memory, comp_hard_disk)
	{
		duration = Lap_duration;
	}
	

	bool Suitability() override// Перевизначений логічний метод "Придатність"
	{
		if ((cpu >= 2000) && (cores >= 2) && (memory >= 2048) && (hard_disk >= 320) && (duration >= 60))
		{
			cout << "Ноутбук придатний" << endl;
			return true;
		}
		else
		{
			cout << "Ноутбук не придатний" << endl;
			cout << "Невідповідає умовам: " << endl << "Частота процесора щонайменше 2000 МГц; " << endl << "Кількість ядер щонайменше 2; "\
				<< endl << "Об'єм пам'яті щонайменше 2048 МБ;" << endl << "Об'єм жорсткого диска щонайменше 320 Гб;"\
				<< endl << "Тривалість автономної роботи (у хвилинах) щонайменше 60. " << endl << endl;
			return false;
		}
	}

	float Cost(int cpu, int cores, int memory, int hard_disk) override // Перевизначений метод "Вартість", що повертає повертає приблизну розрахункову вартість ноутбука
	{
		return Computer::Cost(cpu, cores, memory, hard_disk) + (duration / 10);
	}

	void Info() override // Перевизначений метод інформації 
	{
		cout << "Тривалість автономної роботи = " << duration << " хв" << endl << endl;
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