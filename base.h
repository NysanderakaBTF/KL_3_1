#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>

class base;
typedef void (*signal)(std::string&);
typedef void (*handler)(base*, std::string& s);
#define SIGNALL(_signal) ((signal) (&_signal))
#define HANDLERR(_handler) ((handler) (&_handler))
class base
{
protected:
	std::string name;
	base* head;
	std::vector<base*> ar_p;
	int status;
	//struct connections {
	//	base* bas;
	//	signal sig;
	//	handler hand;
	//};
	struct connections {
		base* bas;
		signal sig;
		handler hand;
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
	void set_connection(signal*, base*, handler*);
	void del_connection(signal*,  base*, handler*);
	void emit_signal(signal*, std::string&);
	//void set_connection(signal, base*, handler);
	//void del_connection(signal,  base*, handler);
	//void emit_signal(signal, std::string&);
	void set_ready_all();

};
#endif 