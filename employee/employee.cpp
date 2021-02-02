#include <iostream>
#include <fstream>
#include <vector>
#include "emp.h"

enum { EMPLOYEE = 1, MANAGER, FINK, HIGHFINK };

using namespace std;

int main()
{
	fstream file("output.txt");
	vector<shared_ptr<abstr_emp>> vot;
	int idEmp;



	while (file >> idEmp)
	{

		switch (idEmp)
		{
		case EMPLOYEE:
			vot.push_back(shared_ptr<abstr_emp>(new employee()));
			vot[vot.size() - 1]->getALL(file);
			vot[vot.size() - 1]->showAll();
			break;
		case MANAGER:
			vot.push_back(shared_ptr<abstr_emp>(new manager()));
			vot[vot.size() - 1]->getALL(file);
			vot[vot.size() - 1]->showAll();
			break;
		case FINK:
			vot.push_back(shared_ptr<abstr_emp>(new fink()));
			vot[vot.size() - 1]->getALL(file);
			vot[vot.size() - 1]->showAll();
			break;
		case HIGHFINK:
			vot.push_back(shared_ptr<abstr_emp>(new highfink()));
			vot[vot.size() - 1]->getALL(file);
			vot[vot.size() - 1]->showAll();
			break;
		default:
			break;
		}
	}
	file.clear();



	std::cout << "Enter: \n"
		<< EMPLOYEE << ": employee\t"
		<< MANAGER << ": manager\n"
		<< FINK << ": fink\t\t"
		<< HIGHFINK << ": highfink\n";

	employee* temp;

	while (std::cin >> idEmp)
	{


		switch (idEmp)
		{
		case EMPLOYEE:
			temp = new employee();
			temp->setAll();
			file << EMPLOYEE << ' ';
			temp->writeAll(file);
			delete temp;
			break;
		case MANAGER:
			temp = new manager();
			temp->setAll();
			file << MANAGER << ' ';
			temp->writeAll(file);
			delete temp;
			break;
		case FINK:
			temp = new fink();
			temp->setAll();
			file << FINK << ' ';
			temp->writeAll(file);
			delete temp;
			break;
		case HIGHFINK:
			temp = new highfink();
			temp->setAll();
			file << HIGHFINK << ' ';
			temp->writeAll(file);
			delete temp;
			break;

		default:
			break;
		}
		std::cout << "Enter:\n"
			<< EMPLOYEE << ": employee\t"
			<< MANAGER << ": manager\n"
			<< FINK << ": fink\t\t"
			<< HIGHFINK << ": highfink\n" << "q for quit: ";

	}

}


