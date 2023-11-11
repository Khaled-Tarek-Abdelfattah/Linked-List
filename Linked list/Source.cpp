#include<iostream>
using namespace std;
class node {
private:
	int data;
	node* next;
public:
	node() { data = 0; next = NULL; }//constructor
	node(int d) { data = d; next = NULL; }//constructor
	void setdata(int d) { data = d; }
	void setnext(node* n) { next = n; }
	int getdata() { return data; }
	node* getnext() { return next; }
	friend class list;
};
class list {
private:
	node* chain;
public:
	list() { chain = new node(); }
	list(int d) { chain = new node(d); }//constructor
	void addfront(int d) {
		node* temp = new node(d);
		temp->next = chain;
		chain = temp;
	}
	void addend(int d){
		node* temp=chain;
		if (chain == NULL)
			chain = new node(d);
		else {
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new node(d);
		}
	}
	void removefront(){
		node* temp;
		temp = chain;
		chain = chain->next;
		delete temp;
	}
	void removeend() {
		if (chain->next == NULL)
			chain = NULL;
		else {
			node* temp2;
			node* temp = chain;
			while (temp->next->next != NULL)
				temp = temp->next;
			temp2 = temp->next;
			temp->next = NULL;
			delete temp2;
		}
	}
	node* getchain() { return chain; }
	node* getN() {
		return chain->next;
	}
	int getlastdata() {
		if (chain == NULL)
			cout << "list is empty";
		else {
			node* temp = chain;
			while (temp->next != NULL)
				temp = temp->next;
			return temp->data;
		}
	}
	int getD() {
		return chain->data;
	}
};
int main()
{
	list l1(2);
	l1.addend(3);
	l1.addend(8);
	l1.addend(7);
	cout << l1.getchain() << endl;
	l1.addfront(1);
	cout << l1.getchain()<<endl << l1.getN()<<endl;
	l1.removefront();
	cout << l1.getchain() << endl;
	cout << l1.getlastdata() << endl;
	l1.removeend();
	cout << l1.getlastdata() << endl;
	l1.removeend();
	cout << l1.getlastdata() << endl;
	l1.removeend();
	cout << l1.getlastdata() << endl;
	l1.removeend();
	cout << l1.getlastdata() << endl;
	return 0;
}