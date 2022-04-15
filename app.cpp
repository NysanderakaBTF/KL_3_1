#include "app.h"
#include <iostream>
#include <string>
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
	this->set_name(n_a);
	do {
		std::cin >> n_a;
		
		if (n_a != "endtree") { 
			cin>> n_b>>class_n;
			base* to_push = find_n(n_a);
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

int app::exec_app()
{
	cout<<"Object tree"<<endl;
	std::string k; 
	int n;
	base* set;
	while (cin >> k >> n) {
		set = find_n(k);
		if(set!=nullptr)
			set->set_readiness(n);
	}
	print();
	cout<< endl << "The tree of objects and their readiness"<<endl ;
	print_ready();
	return 0;
}


