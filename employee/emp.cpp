#include "emp.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

abstr_emp::~abstr_emp()
{
}

abstr_emp::abstr_emp()
{
	fname = "";
	lname = "";
	job = "";
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
{
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::showAll() const
{
	cout << "Name " << fname << "\tLastName " << lname << "\n job " << job << endl;
}

void abstr_emp::setAll()
{
	cout << "Eneter first name: ";
	cin.get();
	std::getline(std::cin, fname);
	cout << "Enter lastName: ";
	std::getline(std::cin, lname);
	cout << "enter job: ";
	std::getline(std::cin, job);
}

void abstr_emp::getALL(std::istream& in)
{
	std::getline(in, fname);
	std::getline(in, lname);
	std::getline(in, job);
}

void abstr_emp::writeAll(std::ostream& os) const
{
	os << fname << "\n" << lname << "\n" << job << std::endl;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "Name " << e.fname << "\tLastName " << e.lname << "\n job " << e.job << std::endl;
	return os;
}

employee::employee() : abstr_emp()
{
}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j)
{
}

manager::manager() : employee(), incargeof(0)
{
}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : employee(fn, ln, j), incargeof(ico)
{
}

manager::manager(const employee& e, int ico) : employee(e), incargeof(ico)
{
}

manager::manager(const manager& m) : employee(m)
{
}

void manager::showAll() const
{
	abstr_emp::showAll();
	cout << " incageof " << incargeof << endl;
}

void manager::setAll()
{
	abstr_emp::setAll();
	cout << "Enter incargeof: ";
	cin >> incargeof;
}

void manager::writeAll(std::ostream& os) const
{
	abstr_emp::writeAll(os);
	os << incargeof << std::endl;
}

void manager::getALL(std::istream& in)
{
	abstr_emp::getALL(in);
	in >> incargeof;
}

fink::fink() : employee(), reportsto("")
{
}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : employee(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const employee& e, const std::string& rpo) : employee(e), reportsto(rpo)
{
}

fink::fink(const fink& f) : employee(f)
{
}

void fink::showAll() const
{
	abstr_emp::showAll();
	cout << " reports to: " << reportsto << endl;
}

void fink::setAll()
{
	abstr_emp::setAll();
	cout << "reports to: ";
	getline(cin, reportsto);
}

void fink::writeAll(std::ostream& os) const
{
	abstr_emp::writeAll(os);
	os << reportsto << endl;
}

void fink::getALL(std::istream& in)
{
	abstr_emp::getALL(in);
	getline(in, reportsto);

}


highfink::highfink() :employee(), manager(), fink()
{
}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) : employee(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const employee& e, const std::string& rpo, int ico) : employee(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink& f, int ico) : employee(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager& m, const std::string& rpo) : employee(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink& h) : employee(h), manager(h), fink(h)
{
}

void highfink::showAll() const
{
	manager::showAll();
	cout << " reports to: " << reportsTo() << endl;
}

void highfink::setAll()
{
	manager::setAll();
	cout << "enetr reports to: ";
	cin.get();
	std::getline(std::cin, reportsTo());
}

void highfink::writeAll(std::ostream& os) const
{
	manager::writeAll(os);
	os << reportsTo() << std::endl;
}

void highfink::getALL(std::istream& in)
{
	manager::getALL(in);
	in.get();
	getline(in, reportsTo());
}

