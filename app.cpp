#include "app.h"
#include <iostream>
#include <string>
using namespace std;
app::app(base_c2* p) :base(p, "root")
{
}


//void app::build_tree_objects()
//{
//	base* temp = nullptr;
//	std::string n_a, n_b;
//	int class_n;
//	std::cin >> n_a;
//	this->set_name(n_a);
//	do {
//		std::cin >> n_a;
//		
//		if (n_a != "endtree") { 
//			cin>> n_b>>class_n;
//			base* to_push = find_n(n_a);
//			switch (class_n)
//				{
//				case 2:
//					temp = new base_c2(to_push, n_b);
//					break;
//				case 3:
//					temp = new base_c3(to_push, n_b);
//					break;
//				case 4:
//					temp = new base_c4(to_push, n_b);
//					break;
//				case 5:
//					temp = new base_c5(to_push, n_b);
//					break;
//				case 6:
//					temp = new base_c6(to_push, n_b);
//					break;
//				default:
//					break;
//				}
//		}
//	} while (n_a != "endtree");
//}
void app::build_tree_objects()
{
	base* temp = nullptr;
	std::string n_a, n_b;
	int class_n;
	std::cin >> n_a;
	this->set_name(n_a);
	do {
		std::cin >> n_a;

		if (n_a != "endtree") {
			cin >> n_b >> class_n;
			base* to_push = find_cord(n_a);
			if (to_push == nullptr) {
				cout << "The head object " << n_a << " is not found";
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

//int app::exec_app()
//{
//	cout<<"Object tree"<<endl;
//	std::string k; 
//	int n;
//	base* set;
//	while (cin >> k >> n) {
//		set = find_n(k);
//		if(set!=nullptr)
//			set->set_readiness(n);
//	}
//	print();
//	cout<< endl << "The tree of objects and their readiness"<<endl ;
//	print_ready();
//	return 0;
//}
int app::exec_app()
{
	cout << "Object tree" << endl;
	print();
	std::string com="", p;
	int n;
	base* now = this;
	base* tem = nullptr;
	do {
		cin >> com;
		if(com!="END"){
			cin >> p;
			if (com == "SET") {
				tem = now->find_cord(p);
				if (tem == nullptr) {
					cout <<endl<< "Object is not found: " << now->get_name() << p;
				}
				else {
					now = tem;
					cout << endl << "Object is set : " << now->get_name();
				}
			}
			if (com == "FIND") {
				tem = now->find_cord(p);
				if (tem == nullptr) {
					cout << endl << p<<"     Object is not found";
				}
				else {
					cout << endl << p << "     Object name: " << tem->get_name();
				}
			}
		}
	} while (com != "END");
	return 0;
}



