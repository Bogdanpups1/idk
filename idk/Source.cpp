#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student(string n, string s, int a)
	{
		name = n;
		surname = s;
		age = a;
	}
	void Print()
	{
		cout << "Name: " << name << "Surname: " << surname << "\tAge: " << age << endl;
	}
	void Input()
	{
		cout << "Enter Name: ";
		cin >> name;

		cout << "Enter Surname: ";
		cin >> surname;

		cout << "Enter Age: ";
		cin >> age;
	}

	//------------- HW
	void SaveFile()
	{
		ofstream out("NameSave.txt", ios::app);

		if (out.is_open())
		{
			out << name << ' ' << surname << ' ' << age << endl;
			out.close();
		}
		else
		{
			cout << "Srry but we cant open file" << endl;
		}

	}
	void LoadFile()
	{
		ifstream in("NameSave.txt");
		string n;
		string s;
		int a;

		if (in.is_open())
		{
			while (in >> n >> s >> a)
			{
				cout << n << ' ' << s << ' ' << a << endl;
			}
			in.close();
		}
		else
		{
			cout << "Srry but we cant open file" << endl;
		}
	}

};

int main()
{
	Student obj1("Ivan", "Ivanov", 19);

	obj1.SaveFile();
	obj1.LoadFile();
}
