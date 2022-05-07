#include "app.h"
#include <iostream>
#include <string>
#include"base_c2.h"
#include"base_c3.h"
#include"base_c4.h"
#include"base_c5.h"
#include"base_c6.h"
using namespace std;
app::app(base* p) :base(p, "root")
{
	n_class = 1;
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
				cout << "Object tree" << endl;
				print();
				cout << endl << "The head object " << n_a << " is not found";
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
	Tsignal sigs[] = {SIGNALL(app::signal), SIGNALL(base_c2::signal),
					  SIGNALL(base_c3::signal),SIGNALL(base_c4::signal),
					  SIGNALL(base_c5::signal),SIGNALL(base_c6::signal) };

	Thandler hans[] = {HANDLERR(app::handler), HANDLERR(base_c2::handler),
					   HANDLERR(base_c3::handler), HANDLERR(base_c4::handler),
					   HANDLERR(base_c5::handler), HANDLERR(base_c6::handler) };
	while (n_a != "end_of_connections") {
		cin >> n_b;
		base* from = find_cord(n_a);
		base* to = find_cord(n_b);
		from->set_connection(sigs[from->get_n_class() - 1], to, hans[to->get_n_class() - 1]);
		cin >> n_a;
	}
}
void app::signal(std::string& mes)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		mes += " (class: 1)";
	}
}
void app::handler(const std::string& mes)
{
	if (status)
		cout << endl << "Signal to " << get_abs_cord() << " Text: " << mes;
}

int app::exec_app()
{
	Tsignal sigs[] = { SIGNALL(app::signal), SIGNALL(base_c2::signal),
					SIGNALL(base_c3::signal),SIGNALL(base_c4::signal),
					SIGNALL(base_c5::signal),SIGNALL(base_c6::signal) };

	Thandler hans[] = { HANDLERR(app::handler), HANDLERR(base_c2::handler),
					HANDLERR(base_c3::handler), HANDLERR(base_c4::handler),
					HANDLERR(base_c5::handler), HANDLERR(base_c6::handler) };
	cout << "Object tree" << endl;
	print();
	std::string com, p,mes;
	int re;
	base* now = this;
	base* tem = nullptr;
	this->set_ready_all();
	do{
		cin >> com;
		if (com != "END") {
			cin >> p;
			if (com == "EMIT") {// для каждого вызова нужно определить класс и вызывать именно его методы
				getline(cin, mes);
				tem = find_cord(p);
				if (tem != nullptr)
					tem->emit_signal(sigs[tem->get_n_class() - 1], mes);
				else
					cout << endl << "Object " << p << " not found";
			}
			else if (com == "SET_CONNECT") {
				cin >> mes;
				now = find_cord(p);
				tem = find_cord(mes);
				if(now==nullptr)
					cout << endl << "Object " << p << " not found";
				if (tem == nullptr)
					cout << endl << "Handler object " << mes << " not found";
				if(tem!=nullptr && now!=nullptr)
					now->set_connection(sigs[now->get_n_class() - 1],tem, hans[tem->get_n_class()-1]);
			}
			else if (com == "DELETE_CONNECT") {
				cin >> mes;
				now = find_cord(p);
				tem = find_cord(mes);
				if (now == nullptr)
					cout << endl << "Object " << p << " not found";
				if (tem == nullptr)
					cout << endl << "Handler object " << mes << " not found";
				if (tem != nullptr && now != nullptr)
				now->del_connection(sigs[now->get_n_class() - 1], tem, hans[tem->get_n_class() - 1]);
			}
			else if (com == "SET_CONDITION") {
				cin >> re;
				now = find_cord(p);
				if(now != nullptr)
					now->set_readiness(re);
				else 
					cout << endl << "Object " << p << " not found";
			}
		}
	}while (com != "END");

	return 0;
}



