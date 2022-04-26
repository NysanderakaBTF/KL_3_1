#include "base_c3.h"
#include <iostream>
using namespace std;
base_c3::base_c3(base* b, std::string n) :base(b, n) {}
void base_c3::ssignal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from" << get_abs_cord();
		mes += " (class: 3)";
	}
}
void base_c3::shandler(base* b, std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << b->get_abs_cord() << " Text: " << mes;
}