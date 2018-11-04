#include "DeliveryManager.h"

Node::~Node() {
    if (this->next) delete this->next;
    this->next = NULL;
    delete this->package;
}

DeliveryManager::DeliveryManager() {
    this->head = NULL;
    this->tail = NULL;
    this->numPackages = 0;
    this->numDrones = 0;
}

DeliveryManager::DeliveryManager(Package* pkg) {
    this->head = NULL;
    this->tail = NULL;
    this->numPackages = 0;
    this->numDrones = 0;
    this->add(pkg);
}

void DeliveryManager::add(Package* pkg) {
    this->numPackages++;
    this->numDrones += ((int)(pkg->getWeight() / 10) + 1); // FIXED
    Node* node = new Node(pkg);
    if (!this->head) {
        this->head = node;
        this->tail = node;
        return;
    }

    this->tail->next = node;
    node->prev = this->tail;
    this->tail = node;
}

int DeliveryManager::search(string desc) {
    if (!this->head) return -1;

    Node* current = this->head;
    int i = 0;
    while (current) {
        if (current->package->getDesc().find(desc) != string::npos) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}

void DeliveryManager::sort() { // Bubble sort
    if (!this->head) return;

    bool hasSwapped = false;
    Node* current = this->head;
    while (current->next) {
        if (*current->package > *current->next->package) {
            swap(current, current->next);
            hasSwapped = true;
        }
    }

    if (hasSwapped) sort();
}

// EXPANDED SINCE ORIGINAL SUBMISSION
void DeliveryManager::swap(Node* larger, Node* smaller) {
        Node* tmp = larger;
        smaller->prev = tmp->prev;
        if (smaller->prev) {
            smaller->prev->next = smaller;
        } else { // larger was head node
            this->head = smaller;
        }

        tmp->next = smaller->next;
        smaller->next = tmp;
        tmp->prev = smaller;

        if (tmp->next) {
            tmp->next->prev = tmp;
        } else { // smaller was tail node
            this->tail = tmp;
        }
}

// ADDED SINCE ORIGINAL SUBMISSION
ostream& operator<<(ostream &out, const DeliveryManager &dm) {
    if (!dm.head) return out;

    Node* current = dm.head;
    while (current) {
        out << *current->package;
        current = current->next;
    }
    return out;
}