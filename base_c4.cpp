#include "base_c4.h"
#include <iostream>
using namespace std;
base_c4::base_c4(base* b, std::string n) :base(b, n) {}
void base_c4::ssignal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from" << get_abs_cord();
		mes += " (class: 4)";
	}
}
void base_c4::shandler(base* b, std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << b->get_abs_cord() << " Text: " << mes;
}