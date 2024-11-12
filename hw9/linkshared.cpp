#include <cmath>

#include <iostream>
using std::cin, std::cout;

#include <memory>
using std::make_shared, std::shared_ptr;

#include <cassert>

class Node; // forward definition
class List {
private:
  shared_ptr<Node> head{nullptr};
public:
  List() {};
  auto headnode() { return head; };
  void insert(int value);
  int length();
  int length_iterative();
  bool contains_value(int v);
  void print();
};

class Node {
private:
  int datavalue{0},datacount{0};
  shared_ptr<Node> next{nullptr};
public:
  Node() {};
  Node(int value,shared_ptr<Node> next=nullptr)
    : datavalue(value),datacount(1),next(next) {};
  int value() {
    return datavalue; };
  auto nextnode() {
    return next; };
  int length();
  int count() {
    return datacount; };
  bool contains_value(int v); // <<<<< needs to be added
  bool has_next() {
    return next!=nullptr; };
  void insert(int value);
  void print();
};


int main() {

  List mylist;
  cout << "Empty list has length: "
       << mylist.length() << '\n';
  cout << '\n';

  mylist.insert(3);
  cout << "After inserting 3 the length is: "
       << mylist.length() << '\n';

  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  if (mylist.contains_value(4))
    cout << "Hm. Should not contain 4" << '\n';
  else
    cout << "Indeed: does not contain 4" << '\n';
  cout << '\n';
 
  mylist.insert(3);
  cout << "Inserting the same item gives length: "
       << mylist.length() << '\n';
  if (mylist.contains_value(3)) {
    cout << "Indeed: contains 3" << '\n';
    auto headnode = mylist.headnode();
    cout << "head node has value " << headnode->value()
         << " and count " << headnode->count() << '\n';
  } else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';
 
  mylist.insert(2);
  cout << "Inserting 2 goes at the head;\nnow the length is: "
       << mylist.length() << '\n';
  if (mylist.contains_value(2))
    cout << "Indeed: contains 2" << '\n';
  else
    cout << "Hm. Should contain 2" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

    mylist.insert(6);
  cout << "Inserting 6 goes at the tail;\nnow the length is: "
       << mylist.length()
       << '\n';
  if (mylist.contains_value(6))
    cout << "Indeed: contains 6" << '\n';
  else
    cout << "Hm. Should contain 6" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  mylist.insert(4);
  cout << "Inserting 4 goes in the middle;\nnow the length is: "
       << mylist.length()
       << '\n';
  if (mylist.contains_value(4))
    cout << "Indeed: contains 4" << '\n';
  else
    cout << "Hm. Should contain 4" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  cout << "List has length: " << mylist.length() << '\n';
  cout << '\n';

  {
    cout << "Another check.\n";
    List mylist;
    for ( auto i : { 15,23,11,75,11,65,3} ) {
      cout << "insert: " << i << '\n';
      mylist.insert(i);
    }
    mylist.print();
  }

  cout << "\n";
  cout << "Lets Build a Linked List Together\n";

  List myList;
  int value;
  cout << "Enter values to add to the list (enter 0 to stop): ";
  cout << "\n";
  while (cin >> value && value != 0) {
    myList.insert(value);
    myList.print();  // Print list after each insertion
  }


  return 0;
}

/*
 * Compute the length of a list recursively
 * See below for an iterative solution
 */
int List::length() {
  if (head==nullptr)
    return 0;
  else
    return head->length();
};

int Node::length() {
  if (!has_next())
    return 1;
  else
    return 1+next->length();
};

/*
 * Iterative alternative
 * to recursive computation
 */
int List::length_iterative() {
  int count = 0;
  if (head!=nullptr) {
    auto current_node = head;
    while (current_node->has_next()) {
      current_node = current_node->nextnode(); count += 1;
    }
  }
  return count;
};

/*
 * Auxiliary functions
 */
void Node::print() {
  cout << datavalue << ":" << datacount;
  if (has_next()) {
    cout << ", "; next->print();
  }
};

void List::print() {
  cout << "List:";
  if (head!=nullptr)
    cout << " => "; head->print();
  cout << '\n';
};

void List::insert(int value) {
  if (head==nullptr)
    head = make_shared<Node>(value); // assigns a new node to head w val = value, count = 1, and next=nullptr
  else head->insert(value); // calls on the node insert func to handle other types of inserts
};

void Node::insert(int value) {
    if (value == datavalue) {
        // Updates the datacoutn whent he same value is added again to the list
        datacount++;
    }
    // takes care if the val needs to be added at the end of the list
    else if (!has_next()) {
        next = make_shared<Node>(value);
    }
    // inserts val at either head or at some point in the list in ascending order
    else if (value < next->value()) {
        auto new_node = make_shared<Node>(value, next);
        next = new_node;
    }
    // moves onto the next node till the val is either inserted at a new node or a new end node is created for it
    else {
        next->insert(value);
    }
};

bool List::contains_value(int v) {
  if (head==nullptr)
    return false;
  else
    return head->contains_value(v); // calls on the node contains val to check through each node of the list
};

bool Node::contains_value(int v) {
  if (datavalue==v)
    return true;
  else if (next==nullptr)
    return false;
  else
    return next->contains_value(v); // recursively calls contains val on the node to loop thru each elem of the list
};
