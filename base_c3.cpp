#include "base_c3.h"
#include <iostream>
using namespace std;
base_c3::base_c3(base* b, std::string n) :base(b, n) { n_class = 3; }
void base_c3::signal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		mes += " (class: 3)";
	}
}
void base_c3::handler(std::string& mes)
{
	if (status)
	cout << endl << "Signal to " <<get_abs_cord() << " Text: " << mes;
}