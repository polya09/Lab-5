#include<iostream>
#include<string>
#include<fstream>
#include <windows.h>

using namespace std;

struct date
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool date::isCorrect()
{
	bool result = false;
	if ((day < 1) || (month < 1) || (year < 1))
		result = false;
	else {
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}

		default:
			result = false;
		}
	}
	return result;
}
struct HomeAdress
{
	string mail_index;
	string country;
	string region;
	string district;
	string city;
	string street;
	string house_number;
	string flat_num;
};
struct Person
{
	string fio;
	date birth;
	string nation;
	string telephone_num;
	HomeAdress home_adress;

};
struct Worker {
	Person person;
	string fio;
	int NumberShop;
	int PersonnelNumber;
	char educated[32];
	int YearEmployment;
};


void BaseLevel() {

	/* «Рабочий»:
	фамилия; имя; отчество; домашний адрес(почтовый индекс, страна,
	область, район, город, улица, дом, квартира); национальность; дата
	рождения(год, месяц число); № цеха; табельный номер; образование; год
	поступления на работу.Вывести данные про рабочих, поступивших на
	работу в 2010 году.*/

	Worker* worker = new Worker[2];
	worker[0].YearEmployment = 2000 + rand() % 21;
	worker[0].fio = "Иванов Алексей Александрович";
	worker[1].YearEmployment = 2000 + rand() % 21;
	worker[1].fio = "Руда Мария Витальевна";
	fstream f_out_in; f_out_in.open("f_base.txt", ios::out | ios::in | ios::trunc);
	for (size_t i = 0; i < 2; i++)
	{
		f_out_in << worker[i].YearEmployment << " " << worker[i].fio << endl;
	}
	f_out_in.seekp(0, ios::beg);

	Worker* buffer = new Worker[2];
	cout << "\nИнформация о работике считанная с файла <<base.txt>>: \n";
	for (size_t i = 0; i < 2; i++)
	{
		f_out_in >> buffer[i].YearEmployment;
		cout << "\t" << buffer[i].YearEmployment << " ";
		string tmp;
		getline(f_out_in, buffer[i].fio); cout << buffer[i].fio << "\n";
	}
	cout << "\nДанные о работниках поступивших на работу в 2010 году: \n";
	for (size_t i = 0; i < 2; i++)
	{
		if (buffer[i].YearEmployment == 2010)
		{
			cout << "\t" << buffer[i].YearEmployment << " ";
			cout << buffer[i].fio << " ";
		}
	}
	getchar();

}


void MiddleLevel()
{
	/*Дан файл f, компоненты которого являются целыми числами.
	Найти колличество чётных чисел среди компонент.*/

	ifstream fin("f_middle.txt");
	ofstream fout("g_middle.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		int* arr;
		int count = 0;
		arr = new int[36];
		for (int i = 0; i < 36; i++)
		{
			fin >> arr[i];
			if (arr[i] % 2 == 0)
			{
				count++;
			}
		}
		fout << count;
	}
	fin.close();
	fout.close();

}

int main() {
	BaseLevel();
	MiddleLevel();
	return 0;
}