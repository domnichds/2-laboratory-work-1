#include "firewall.hpp"
#include <iostream>
#include <sstream>

Firewall::Firewall(const string& name, unsigned char security_status)
{
	this->name = name;
	this->security_status = security_status;
}

bool Firewall::is_valid(unsigned char security_status) const
{
	return (this->security_status <= security_status);
}

void Firewall::print_info() const
{
	cout << this->name << " " << int(this->security_status) << endl;
}

string Firewall::get_info() const
{
	stringstream ss;
	ss << this->name << ";" << int(this->security_status) << "\n";
	return ss.str();
}
