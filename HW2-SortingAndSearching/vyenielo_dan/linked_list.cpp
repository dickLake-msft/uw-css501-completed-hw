/*
A linked list data structure composed of link nodes containing data particles.
Implemented for CSS501 at UWB HW2.
Author: Dan Vyenielo(dvyenielo@gmail.com)
*/
#include "linked_list.h"
#include <algorithm> // for min(), nothing else
#include <cstdlib>	//for abs()
#include <stdexcept>

const int linked_list::EMPTY_CURRENT_POSITION_INDEX = -1;

linked_list::linked_list() {
	initialize();
}

linked_list::linked_list(linked_list& source) {
	copy_linked_list(source);
}

linked_list& linked_list::operator=(linked_list& source) {
	copy_linked_list(source);
	return *this;
}

/*
Initialize to default invariants.
*/
void linked_list::initialize() {
	head_ptr = nullptr;
	tail_ptr = nullptr;
	current_ptr = nullptr;
	current_position = EMPTY_CURRENT_POSITION_INDEX;
	count = 0;
}

void linked_list::copy_linked_list(linked_list& source) {
	initialize();
	if (!source.empty()) {
		int source_size = source.size();
		for (int i = 0; i < source_size; i++) {
			push_back(source.get(i));
		}
	}
}

void linked_list::validate(const int& position) const {
	if (!is_valid(position))
		throw std::out_of_range("position out of range");
}

bool linked_list::is_valid(const int& position) const {
	return !(position < 0 || position >= count);
}

int linked_list::size() const {
	return count;
}

/*
An empty list has default invariants. 
*/
bool linked_list::empty() const {
	return !head_ptr && !tail_ptr && !current_ptr
		&& current_position == EMPTY_CURRENT_POSITION_INDEX && !count;
}

particle& linked_list::front() const {
	return head_ptr->data;
}

particle& linked_list::back() const {
	return tail_ptr->data;
}

linked_list::link* linked_list::get_link(const int& position) {
	validate(position);
	link* node = nullptr;
	if (!position) {
		node = head_ptr;
	}
	else if(current_position - position == 1) {
		node = current_ptr->previous_ptr;
	}
	else if (current_position == position) {
		node = current_ptr;
	}
	else if (position - current_position == 1) {
		node = current_ptr->next_ptr;
	}
	else if (position == count - 1) {
		node = tail_ptr;
	}
	else {	//traverse the list from the minimum distance pointer
		const int num_ptr_distances = 3;
		int distances[num_ptr_distances];
		distances[0] = position;	//distance from head
		distances[1] = abs(position - current_position);	//absolute distance from current
		distances[2] = size() - 1 - position;	//distance from tail
		int min_distance = distances[0];
		for (int distance : distances) {
			if (distance < min_distance)
				min_distance = distance;
		}
		if (min_distance == distances[0]) {	//iterate from head
			node = head_ptr;
			int i = 0;
			while (i < distances[0]) {
				node = node->next_ptr;
				i++;
			}
		}
		else if (min_distance == distances[1]) {	//iterate from current
			node = current_ptr;
			int i = 0;
			if (current_position - position > 0) {	//current positon is to the right of position -> move left
				while (i < min_distance) {
					node = node->previous_ptr;
					i++;
				}
			}
			else {	//move right
				while (i < min_distance) {
					node = node->next_ptr;
					i++;
				}
			}
		}
		else {	//iterate from tail
			node = tail_ptr;
			int i = 0;
			while (i < distances[2]) {
				node = node->previous_ptr;
				i++;
			}
		}
	}
	current_ptr = node;
	current_position = position;
	return node;
}

particle& linked_list::get(const int& position) {
	return get_link(position)->data;
}

void linked_list::set(const int& position, const particle& value) {
	current_ptr = get_link(position);
	current_ptr->data = value;
	current_position = position;
}


/*
BigO analysis:
1 node* assignment 
+
1 i initialization
+
N i < count comparisions
+
N i increments
+
N node->data == value comparisons (worst case)
+
1 return
== O(1 + 1 + N + N + N + 1) = O(3 + 3N) -> O(N)

linked_list::find is BigO(N) where N is the number of items in the list.
*/
int linked_list::find(const particle& value) const {
	link* node = head_ptr; 
	for (int i = 0; i < count; i++) {
		if (node->data == value)
			return i;
	}
	return EMPTY_CURRENT_POSITION_INDEX;
}

/*
BigO Analysis: "counting" operations performed
1 initialize left*
+
N while(left != tail) checks
+
N right* initializations
+
N max* assignments
+
N*N right checks
+
N*N if conditionals
+
N*N max assignments
+
N*N right increments
+
N tmp particles
+
N left->data
+
N max->data
+
N left increments

== O(1 + N + N + N + N*N + N*N + N*N + N*N + N + N + N + N )
== 0(1 + 7N + 4N^2)
-> O(N^2)

sort_ascending() is O(N^2) where N is the number of elements in the list.
*/
void linked_list::sort_ascending() {
	link* left = head_ptr;
	while (left != tail_ptr) {
		link* right = left->next_ptr;
		link* max = left;
		while (right) {
			if (right->data < max->data)
				max = right;
			right = right->next_ptr;
		}
		particle tmp = left->data;
		left->data = max->data;
		max->data = tmp;
		left = left->next_ptr;
	}
}

/*
BigO Analysis: "counting" operations performed
1 initialize left*
+
N while(left != tail) checks
+
N right* initializations
+
N max* assignments
+
N*N right checks
+
N*N if conditionals
+
N*N max assignments
+
N*N right increments
+
N tmp particles
+
N left->data
+
N max->data
+
N left increments

== O(1 + N + N + N + N*N + N*N + N*N + N*N + N + N + N + N )
== 0(1 + 7N + 4N^2)
-> O(N^2)

sort_descending() is O(N^2) where N is the number of elements in the list.
*/
void linked_list::sort_descending() {
	link* left = head_ptr;
	while (left != tail_ptr) {
		link* right = left->next_ptr;
		link* max = left;
		while (right) {
			if (right->data > max->data)
				max = right;
			right = right->next_ptr;
		}
		particle tmp = left->data;
		left->data = max->data;
		max->data = tmp;
		left = left->next_ptr;
	}
}

void linked_list::push_front(const particle& value) {
	insert(value, 0);
}

void linked_list::push_back(const particle& value) {
	insert(value, size());
}

void linked_list::insert(const particle& value, const int& position) {
	link* node = new link;
	node->data = value;
	if (empty() && !position) {	//empty
		head_ptr = node;
		tail_ptr = node;
	}
	else if (!position) {	//head
		node->next_ptr = head_ptr;
		head_ptr = node;
		head_ptr->next_ptr->previous_ptr = node;
	}
	else if (position == size()) {	//tail
		node->previous_ptr = tail_ptr;
		tail_ptr = node;
		tail_ptr->previous_ptr->next_ptr = node;
	}
	else {	//middle
		link* target = get_link(position);
		node->next_ptr = target;
		node->previous_ptr = target->previous_ptr;
		node->previous_ptr->next_ptr = node;
		node->next_ptr->previous_ptr = node;
	}
	count++;
	current_ptr = node;
	current_position = position;
}

void linked_list::pop_front() {
	erase(0);
}

void linked_list::pop_back() {
	erase(size() - 1);
}

void linked_list::erase(const int& position) {
	if (!empty()) {
		link* target = get_link(position);
		if (size() == 1 && !position) {
			initialize();
		}
		else if (!position) {	//head
			target->next_ptr->previous_ptr = nullptr;
			head_ptr = target->next_ptr;
			current_ptr = head_ptr;
			current_position = position;
			count--;
		}
		else if (position == size() - 1) {	//tail
			target->previous_ptr->next_ptr = nullptr;
			tail_ptr = target->previous_ptr;
			current_ptr = tail_ptr;
			current_position = position;
			count--;
		}
		else { // middle
			target->previous_ptr->next_ptr = target->next_ptr;
			target->next_ptr->previous_ptr = target->previous_ptr;
			current_ptr = target->next_ptr;
			current_position = position;
			count--;
		}
		delete target;
	}
}

linked_list::~linked_list() {
	if (!empty()) {
		link* lead = head_ptr;
		link* follow;
		if (lead->next_ptr) {
			follow = lead;
			lead = lead->next_ptr;
			delete follow;
			while (lead) {
				follow = lead;
				lead = lead->next_ptr;
				delete follow;
			}
		}
		else {
			delete lead;
		}
	}
}