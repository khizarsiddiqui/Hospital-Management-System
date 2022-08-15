#include<iostream>
#include<conio.h>
#include<string.h>
#include <string>
#include<stdlib.h>
using namespace std;

struct patient
{
	long long ID;
	string firstname;
	string lastname;
	int age;
	char blood[5];
	char gender;
	patient*next;
};
class linkedqueue
{
	patient *head, *last;
public:
	linkedqueue() //constructor
	{
		head = NULL;
		last = NULL;
	}
	patient input();
	void insertatend();
	void insertatbeg();
	void getpatientout();
	void listofpatients();
	int search(int);
	char departmentname[50];
};

int linkedqueue::search(int item)
{
	if (head == NULL)
		return false;
	else
	{
		int flag = 0;
		patient*p = new patient();
		p = head;

		while (p->next != NULL && p->ID != item)
		{
			p = p->next;
		}
		if (p->ID == item)
		{
			flag = 1;
			return true;
		}
		if (flag == 0)
			return false;
	}
}

int readnumber()
{
	char b[20];
	cin.getline(b, sizeof(b));
	return atoi(b);
}

patient linkedqueue::input() //taking input of the patient1353
{
	int flag = 0;
	patient *p = new patient();
	cout << "\n\tPlease enter data for patient\n";
	cout << "\n\tFirst name     : ";
	getline(cin, p->firstname);
	cout << "\tLast name      : ";
	getline(cin, p->lastname);
again:
	cout << "\tBlood Group    : ";
	cin >> p->blood;
	if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
		(strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
		(strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
		(strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
		flag = 1;
	if (flag == 0)
	{
		cout << "\nWrong Entry...Enter a valid Blood Group..Try Again..";
		goto again;

	}
	cout << "\tGender           : (m/f)";
	cin >> p->gender;
	cout << "\tAge              : ";
	cin >> p->age;
	cout << "\tMobile number    : ";
	cin >> p->ID;//=readnumber()1353;


	if (search(p->ID))
	{
		p->ID = 0;
		cout << "\n\tData not valid. Operation cancelled.";
	}
	return *p;
}

void output(patient *p)
{
	cout << "\n**********************************";
	cout << "\n\nPatient data:";
	cout << "\n\nFirst Name       : " << p->firstname;
	cout << "\nLast Name          : " << p->lastname;
	cout << "\nGender             : " << p->gender;
	cout << "\nAge                : " << p->age;
	cout << "\nBlood Group        : " << p->blood;
	cout << "\nMobile Number      : " << p->ID;
	cout << "\n\n**********************************";
}
void linkedqueue::insertatbeg()
{
	patient*p = new patient();
	*p = input();
	if (p->ID == 0)
		return;

	if (head == NULL)

	{
		head = p;
		last = p;
		p->next = NULL;
	}
	else
	{
		p->next = head;
		head = p;
	}
	system("cls");
	cout << "\n\tPatient added:";
	output(p);
}
void linkedqueue::insertatend()
{
	patient*p = new patient();
	*p = input();
	if (p->ID == 0)
		return;

	if (head == NULL)
	{
		head = p;
		last = p;
		p->next = NULL;
	}
	else
	{
		p->next = NULL;
		last->next = p;
		last = p;
	}
	system("cls");
	cout << "\n\tPatient added:";
	output(p);
}
void linkedqueue::getpatientout()
{
	system("cls");
	if (head == NULL)
	{
		cout << "\n\tNo Patient to operate";
	}
	else
	{
		patient*p = new patient();
		p = head;
		head = head->next;
		cout << "\n\tPatient to operate:";
		output(p);
	}
}

void linkedqueue::listofpatients()
{
	if (head == NULL)
	{
		cout << "\n\tNo patient";
	}
	patient*p = new patient;
	p = head;
	while (p != NULL)
	{
		cout << "\nPatient data:";
		cout << "\nFirst Name       : " << p->firstname;
		cout << "\nLast Name        : " << p->lastname;
		cout << "\nGender           : " << p->gender;
		cout << "\nAge              : " << p->age;
		cout << "\nBlood Group      : " << p->blood;
		cout << "\nMobile Number    : " << p->ID;
		cout << "\n**********************************\n";
		p = p->next;
	}
	cout << "\n";
}


void departmentmenu(linkedqueue * q)
{
	int choice = 0, success;
	patient p;
	while (choice != 5)
	{
		system("cls");
		cout << "\n\n\tWelcome To Department : " << q->departmentname;
		cout << "\n\t\t[1] Add normal patient\n";
		cout << "\t\t[2] Add critically ill patient\n";
		cout << "\t\t[3] Take patient to Doctor\n";
		cout << "\t\t[4] Display list\n";
		cout << "\t\t[5] Change department or exit\n";
		cout << "\n\tPlease enter your choice : ";
		choice = readnumber();

		switch (choice)
		{
		case 1:	q->insertatend();
			cout << "\n\tPress any key";
			getchar();
			break;

		case 2:	q->insertatbeg();
			cout << "\n\tPress any key";
			getchar();
			break;

		case 3:	q->getpatientout();
			cout << "\n\tPress any key";
			getchar();
			break;

		case 4:	system("cls");
			q->listofpatients();
			cout << "\n\tPress any key";
			getchar();
			break;
		}
	}
}

int main()
{
	int i, choice = 0;
	linkedqueue departments[4];
	system("COLOR 5F");

	while (choice != 5)
	{
		strcpy_s(departments[0].departmentname, "General Clinic\n");
		strcpy_s(departments[1].departmentname, "Heart Clinic\n");
		strcpy_s(departments[2].departmentname, "Lung Clinic\n");
		strcpy_s(departments[3].departmentname, "Plastic Surgery\n");
		system("cls");
		cout << "\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout << "\n\tHOSPITAL MANAGEMENT SYSTEM\t";
		cout << "\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		for (i = 0; i < 4; i++)
		{
			cout << "\t" << (i + 1) << ": " << departments[i].departmentname;
		}
		cout << "\t5: Exit";
		cout << "\n\n\tPlease enter your choice : ";
		choice = readnumber();
		if (choice >= 1 && choice <= 4)
		{
			departmentmenu(&departments[choice - 1]);
		}

	}
	if (choice == 5)
		cout << "\n\t\t\n";
	exit(0);
}

