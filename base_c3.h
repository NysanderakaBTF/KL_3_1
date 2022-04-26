#ifndef BASE_C3_H
#define BASE_C3_H
#include "base.h"
class base_c3 :
	public base
{
public:
	base_c3(base*, std::string = "Default_name");
	void ssignal(std::string&);
	void shandler(base*, std::string&);
};
#endif
