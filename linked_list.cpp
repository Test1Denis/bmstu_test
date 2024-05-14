#include "linked_list.h"

int Node::countNodes_ = 0;
int Node::id_node_ = 0;

Node::Node() {
	next_ = nullptr;
	prev_ = nullptr;
	countNodes_++;
	numNode_ = ++id_node_;
}

Node::Node(const struct Data& data) : Node() {
	data_ = new Data(data.str_);
}

Node::Node(Node* prev) : Node() {
	prev_ = prev;
}

Node::~Node() {
	countNodes_--;
	delete data_;

	if (next_ != nullptr) {
		delete next_;
	}
}

LinkedList::LinkedList() {
	Head = nullptr;
	CurrNode = nullptr;
	countNodes = 0;
}

LinkedList::~LinkedList() {
	delete Head;
}

int LinkedList::Push(const Data& data) {
	Node* temp = new Node(data);
	++countNodes;
	
	if (Head == nullptr) {
		Head = temp;
		CurrNode = temp;
		return 0;
	}

	temp->prev_ = CurrNode;
	CurrNode->next_ = temp;
	CurrNode = temp;

	return 0;
}

void LinkedList::ShowElements() const {
	Node* tempHead = Head;

	std::cout << "count nodes = " << tempHead->countNodes_ << std::endl;
	
	while(tempHead != nullptr) {
		std::cout << tempHead->numNode_ << ": " << tempHead->data_->str_ << std::endl;
		tempHead = tempHead->next_;
	}
}

int LinkedList::Pull(Data* data) {
	if (CurrNode == nullptr) {
		return -1;	
	}

	if (data->str_ != nullptr) {
		delete [] data->str_;
	}
	data->str_ = new char [strlen(CurrNode->data_->str_) + 1];
	strcpy(data->str_, CurrNode->data_->str_);

	CurrNode = CurrNode->prev_;
	if (CurrNode == nullptr) {
		return 0;
	}
	if (CurrNode->next_ != nullptr) {
		delete CurrNode->next_;
		CurrNode->next_ = nullptr;
	}
	return 0;
}


void LinkedList::ShowElemFromTail(const Node* curNode) const {
	static int countEl = 0;
	if (curNode->next_ != nullptr) {
		countEl++;
		
		std::cout << countEl-- << " " << curNode->data_->str_ << std::endl;
		ShowElemFromTail(curNode->next_);
	}

}

void LinkedList::ShowElementFromTail_asOneLL() const {
	ShowElemFromTail(Head);	
}


int LinkedList::SwapElement(int node_a, int node_b) {

	if (node_a == node_b) {
		return 0;
	}
	if (node_a < 0 || node_b < 0) {
		return -1;
	}

	if (node_a > node_b) {
		std::swap(node_a, node_b);
	}

	/* ndX_m1 - minus 1, previous element
	 * ndX_p1 - plus 1, next element
	 * nda, ndb -- elements for swap
	 */
	Node* nda_m1 = getNode(node_a - 1);
	Node* ndb_m1 = getNode(node_b - 1);	//bf3 = el3
	
	Node* ndb = ndb_m1->next_;
	Node* nda = nda_m1->next_;

	if (node_a == 0) {
		nda = nda_m1;
	}
	else {
		nda_m1->next_ = ndb;
	}

	Node* ndb_p1 = ndb->next_;

	if (nda != ndb_m1) {
		ndb->next_ = nda->next_;
		ndb_m1->next_ = nda;
	}
	else {
		ndb->next_ = nda;
	}
	nda->next_ = ndb_p1;

	return 0;
}


Node* LinkedList::getNode(int numNode) const {
	Node* temp = Head;

	while(--numNode >= 0) {
		temp = temp->next_;
		if (temp == nullptr) {
			return nullptr;
		}
	}
	return temp;
}

void LinkedList::getDataNode(int num_node, char* data) const {
	Node* temp = getNode(num_node);
	if (temp == nullptr) {
		data[0] = '\0';
		return;
	}
	strcpy(data, temp->data_->str_); 
}

