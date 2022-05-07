#include "base_c6.h"
#include <iostream>
using namespace std;
base_c6::base_c6(base* b, std::string n) :base(b, n) { n_class = 6; }
void base_c6::signal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		mes += " (class: 6)";
	}
}
void base_c6::handler(std::string& mes)
{
	if (status)
	cout << endl << "Signal to " << get_abs_cord() << " Text: " << mes;
}