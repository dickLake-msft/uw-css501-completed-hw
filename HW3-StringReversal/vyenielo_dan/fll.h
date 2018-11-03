#ifndef FLL_H
#define FLL_H
#include <string>

struct link
{
	std::string data;
	link* next;
};

class fll {	//forward linked list
public:
	fll();
	fll(const fll& source);
	void push_back(const std::string data);
	void pop_front();
	link* front() const;
	bool empty() const;
private:
	link* head;
};

#endif // !FLL_H

