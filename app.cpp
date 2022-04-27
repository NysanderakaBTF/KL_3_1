#include "app.h"
#include <iostream>
#include <string>
#include"base_c2.h"
#include"base_c3.h"
#include"base_c4.h"
#include"base_c5.h"
#include"base_c6.h"
using namespace std;
app::app(base_c2* p) :base(p, "root")
{
}

void app::build_tree_objects()
{
	base* temp = nullptr;
	std::string n_a, n_b;
	int class_n;
	std::cin >> n_a;
	if(n_a !="endtree"){
	this->set_name(n_a);
	
	do {
		std::cin >> n_a;

		if (n_a != "endtree") {
			cin >> n_b >> class_n;
			base* to_push = find_cord(n_a);
			if (to_push == nullptr) {
				cout<<"The head object "<<n_a<<" is not found"<<endl;
				cout<<"Object tree"<<endl;
				print();
				exit(0);
			}
			switch (class_n)
			{
			case 2:
				temp = new base_c2(to_push, n_b);
				break;
			case 3:
				temp = new base_c3(to_push, n_b);
				break;
			case 4:
				temp = new base_c4(to_push, n_b);
				break;
			case 5:
				temp = new base_c5(to_push, n_b);
				break;
			case 6:
				temp = new base_c6(to_push, n_b);
				break;
			default:
				break;
			}
		}
	} while (n_a != "endtree");
	}
	cin >> n_a;
	while (n_a != "end_of_connections") {
		cin >> n_b;
		base* from = find_cord(n_a);
		base* to = find_cord(n_b);
		from->set_connection((signal*)SIGNALL(from), to, (handler*)HANDLERR(to));
		cin >> n_a;
	}
}

int app::exec_app()
{
	cout << "Object tree" << endl;
	print();
	std::string com, p,mes;
	base* now = this;
	base* tem = nullptr;
	this->set_ready_all();
	do{
		cin >> com;
		if (com != "END") {
			cin >> p >> mes;
			if (com == "EMIT") {
				tem = find_cord(p);
				tem->emit_signal((signal*)SIGNALL(tem), mes);
			}
			else if (com == "SET_CONNECT") {
				now = find_cord(p);
				tem = find_cord(mes);
				now->set_connection((signal*)SIGNALL(now), tem, (handler*)HANDLERR(tem));
			}
			else if (com == "DELETE_CONNECT") {
				now = find_cord(p);
				tem = find_cord(mes);
				now->del_connection((signal*)SIGNALL(now), tem, (handler*)HANDLERR(tem));
			}
			else if (com == "SET_CONDITION") {
				now = find_cord(p);
				now->set_readiness(stoi(mes, nullptr, 10));
			}
		}
	}while (com != "END");

	return 0;
}



