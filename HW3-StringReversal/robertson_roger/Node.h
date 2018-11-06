/*
** Roger Robertson Jr.
** HW3 (Workspace)
** File description:
** Node class
*/

#ifndef NODE_H_
	#define NODE_H_
    #include <string>
    using namespace std;
class Node {

    public:
    Node(string word);
    ~Node();
    string getString() const;
    Node* next;

    private:
    string theWord;
};

#endif /* !NODE_H_ */
