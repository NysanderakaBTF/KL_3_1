#include "base_c2.h"
#include <iostream>
using namespace std;
base_c2::base_c2(base* b, std::string n) :base(b, n) {}

void base_c2::ssignal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from" << get_abs_cord();
		mes += " (class: 2)";
	}
}
void base_c2::shandler(base* b, std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << b->get_abs_cord() << " Text: " << mes;
}