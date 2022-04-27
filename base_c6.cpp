#include "base_c6.h"
#include <iostream>
using namespace std;
base_c6::base_c6(base* b, std::string n) :base(b, n) {}
void base_c6::ssignal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from" << get_abs_cord();
		mes += " (class: 6)";
	}
}
void base_c6::shandler(base* b, std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << b->get_abs_cord() << " Text: " << mes;
}