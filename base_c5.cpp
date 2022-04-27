#include "base_c5.h"
#include <iostream>
using namespace std;
base_c5::base_c5(base* b, std::string n) :base(b, n) {}
void base_c5::ssignal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from" << get_abs_cord();
		mes += " (class: 5)";
	}
}
void base_c5::shandler(base* b, std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << b->get_abs_cord() << " Text: " << mes;
}