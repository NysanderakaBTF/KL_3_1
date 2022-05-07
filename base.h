#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>

class base;
typedef void (base::*Tsignal)(std::string&);
typedef void (base::*Thandler)(const std::string& s);
#define SIGNALL(_signal) ((Tsignal) (&_signal))
#define HANDLERR(_handler) ((Thandler) (&_handler))
using namespace std;
class base
{
protected:
	std::string name;
	base* head;
	std::vector<base*> ar_p;
	int status;
	int n_class;
	struct connections {
		base* bas; // с каким объектом связан
		Tsignal sig; // какой сигнал у нашего вызывается
		Thandler hand; // каком обработчиком второго объекта обрабатывается
	};
	std::vector<connections> con;
public:

	base(base*, std::string = "Def_name");
	void set_name(std::string);
	std::string get_name();
	void display();
	void rebase(base* new_per);
	base* get_head_p();
	~base();
	base* find_n(std::string);
	void set_readiness(int stat);
	void print();
	void print_ready();
	base* find_cord(std::string="");
	std::string get_abs_cord();
	//void set_connection(signal, base*, handler);
	//void del_connection(signal,  base*, handler);
	//void emit_signal(signal, std::string&);
	void set_connection(Tsignal, base*, Thandler);
	void del_connection(Tsignal,  base*, Thandler);
	void emit_signal(Tsignal, std::string&);
	void set_ready_all();
	int get_n_class();
};
#endif 