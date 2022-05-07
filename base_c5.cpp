#include "base_c5.h"
#include <iostream>
using namespace std;
base_c5::base_c5(base* b, std::string n) :base(b, n) { n_class = 5; }
void base_c5::signal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		mes += " (class: 5)";
	}
}
void base_c5::handler(const std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << get_abs_cord() << " Text: " << mes;
}