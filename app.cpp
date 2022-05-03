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
		//from->set_connection((signal*)SIGNALL(from), to, (handler*)HANDLERR(to));
		//from->set_connection(SIGNALL(from), to, HANDLERR(to));
		//from->set_connection(SIGNALL(base_c2::signal), to, HANDLERR(base_c2::handler));
		from->set_connection((SIGNALL(base_c2::signal)), to, HANDLERR(base_c2::handler));
		cin >> n_a;
	}
}

int app::exec_app()
{
	Tsignal sigs[] = {SIGNALL(base_c2::signal), SIGNALL(base_c3::signal),SIGNALL(base_c4::signal),SIGNALL(base_c5::signal),SIGNALL(base_c6::signal) };
	Thandler hans[] = {HANDLERR(base_c2::handler),HANDLERR(base_c3::handler), HANDLERR(base_c4::handler), HANDLERR(base_c5::handler), HANDLERR(base_c6::handler) };
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
			if (com == "EMIT") {// для каждого вызова нужно определить класс и вызывать именно его методы
				tem = find_cord(p);
				tem->emit_signal(&sigs[tem->get_n_class()-2], mes);
				//tem->emit_signal((signal*)SIGNALL(tem), mes);
				//tem->emit_signal(SIGNALL(tem), mes);
			}
			else if (com == "SET_CONNECT") {
				now = find_cord(p);
				tem = find_cord(mes);
				now->set_connection(&sigs[tem->get_n_class() - 2],tem, &hans[tem->get_n_class()-2]);
				//now->set_connection((signal*)SIGNALL(now), tem, (handler*)HANDLERR(tem));
				//now->set_connection(SIGNALL(now), tem, HANDLERR(tem));
			}
			else if (com == "DELETE_CONNECT") {
				now = find_cord(p);
				tem = find_cord(mes);
				now->del_connection(&sigs[tem->get_n_class() - 2], (base_c2*)tem, &hans[tem->get_n_class() - 2]);
				//now->del_connection((signal*)SIGNALL(now), tem, (handler*)HANDLERR(tem));
				//now->del_connection(SIGNALL(now), tem, HANDLERR(tem));
			}
			else if (com == "SET_CONDITION") {
				now = find_cord(p);
				now->set_readiness(stoi(mes, nullptr, 10));
			}
		}
	}while (com != "END");

	return 0;
}



