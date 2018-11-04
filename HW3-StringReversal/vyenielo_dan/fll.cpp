#include "fll.h"

fll::fll() {
	link* head = nullptr;
}

/*
Big O Analysis :: Copy Constructor
1 create iter*
+
1 create new head link
+
1 assign head data
+
1 assign head next
+
1 increment iter
+
N iter checks
+
N tmps created
+
N data assignments
+
N next assignments
+
N increments
== O (1 + 1 + 1 + 1 + 1 + N + N + N + N + N) == O(5 + 5N) == O(N)

The fll copy constructor is O(N) where N is the number of links in the list.
*/
fll::fll(const fll& source) {
	if (source.empty()) {
		head = nullptr;
		return;
	}
	link* iter = source.front();
	head = new link;
	head->data = iter->data;
	head->next = iter->next;
	iter = iter->next;
	while (iter) {
		link* tmp = new link();
		tmp->data = iter->data;
		tmp->next = iter->next;
		iter = iter->next;
	}
}

void fll::push_back(const std::string data) {
	link* back = new link;
	back->data = data;
	back->next = nullptr;
	link* iter = head;
	if (!iter) {
		head = back;
	}
	else {
		while (iter->next) {
			iter = iter->next;
		}
		iter->next = back;
	}
}

link* fll::front() const {
	return head;
}


void fll::pop_front() {
	if (!empty()) {
		link* old_head = head;
		head = head->next;
		delete old_head;
	}
	else
	{
		delete head;
		head = nullptr;
	}
}

bool fll::empty() const {
	return !head;
}
