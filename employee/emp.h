#pragma once
#include <iostream>
#include <string>
class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln,
		const std::string& j);
	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() = 0;
	virtual void getALL(std::istream& in);
};

class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string& fn, const std::string& ln,
		const std::string& j);
};

class manager : virtual public employee
{
private:
	int incargeof;
protected:
	int inCargeOf() const { return incargeof; }
	int& incargeOf() { return incargeof; }
public:
	manager();
	manager(const std::string& fn, const std::string& ln,
		const std::string& j, int ico = 0);
	manager(const employee& e, int ico);
	manager(const manager& m);
	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::ostream& os) const;
	virtual void getALL(std::istream& in);
};

class fink : virtual public employee
{
public:
	fink();
	fink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo);
	fink(const employee& e, const std::string& rpo);
	fink(const fink& f);
	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::ostream& os) const;
	virtual void getALL(std::istream& in);
private:
	std::string reportsto;
protected:
	const std::string reportsTo() const { return reportsto; }
	std::string& reportsTo() { return reportsto; }
};

class highfink : public fink, public manager
{
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo, int ico);
	highfink(const employee& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);
	virtual void showAll() const;
	virtual void setAll();
	virtual void writeAll(std::ostream& os) const;
	virtual void getALL(std::istream& in);
};

