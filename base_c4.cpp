#include "base_c4.h"
#include <iostream>
using namespace std;
base_c4::base_c4(base* b, std::string n) :base(b, n) { n_class = 4; }
void base_c4::signal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from" << get_abs_cord();
		mes += " (class: 4)";
	}
}
void base_c4::handler(const std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << get_abs_cord() << " Text: " << mes;
}