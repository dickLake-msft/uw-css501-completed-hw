/*
Author: Dan Vyenielo(dvyenielo@gmail.com)
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "particle.h"

class linked_list {
public:
	linked_list();
	linked_list(linked_list& source);
	linked_list& operator=(linked_list& source);
	
	int size() const;
	bool empty() const;
	
	particle& front() const;
	particle& back() const;

	particle& get(const int& position);
	void set(const int& position, const particle& value);
	
	int find(const particle& value) const;
	void sort_ascending();
	void sort_descending();

	void push_front(const particle& value);
	void push_back(const particle& value);
	void insert(const particle& value, const int& position);
	void pop_front();
	void pop_back();
	void erase(const int& position);

	~linked_list();
private:
	struct link {
		particle data;
		link* next_ptr{ nullptr };
		link* previous_ptr{ nullptr };
	};
	void initialize();
	void copy_linked_list(linked_list& source);
	void validate(const int& position) const;
	bool is_valid(const int& position) const;
	link* get_link(const int& position);
	link* head_ptr;
	link* tail_ptr;
	link* current_ptr;
	int current_position;
	int count;
	const static int EMPTY_CURRENT_POSITION_INDEX;
};
#endif // !LINKED_LIST_H