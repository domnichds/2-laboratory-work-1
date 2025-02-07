#ifndef FIREWALL_HPP
#define FIREWALL_HPP

#include <string>

using namespace std;

class Firewall
{
private:
	string name;
	unsigned char security_status;

public:
	Firewall(const string&, unsigned char);
	bool is_valid(unsigned char) const;
};

#endif