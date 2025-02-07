#include "firewall.hpp"

Firewall::Firewall(const string& name, unsigned char security_status)
{
	this->name = name;
	this->security_status = security_status;
}

bool Firewall::is_valid(unsigned char security_status) const
{
	return this->security_status <= security_status;
}
