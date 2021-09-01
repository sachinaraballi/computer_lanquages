#include <iostream>

using namespace std;

class Node {
    public: 
        int data;
        //pointer to next node
        Node *next;
        //constructor
        Node(){
            next = NULL;
        }
};

class LinkedList {
    Node *head;
    public:
    void insert_first(int data){
	    Node *cur = new Node();
	    cur->data = data;
	    cur->next = head;
	    head = cur;
    }
    
    void insert_end (int data) {
        Node *cur = new Node();
        cur->data = data;
        if(head == NULL){
            //if list is empty make cur as head
            head = cur;
        }else{
            Node *node = head;
            //traverse till end 
            while (node->next != NULL){
			    node = node->next;
		    }
		    node->next = cur;
        }
    }
    
    void insert_at (int data, int position) {
        Node *cur = new Node();
        cur->data = data;
        if(position == 0) {
            cur->next = head;
            head = cur;
        } else {
            Node *node = head; 
            while(position > 1) {
                node = node->next;
                position--;
            }
            cur->next = node->next;
            node->next = cur;
        }
    }
    
    void delete_at(int position) {
        if(head == NULL){
            cout << "list is empty" << endl;
        }else {
            Node *cur, *node;
            if(position == 0) {
                cout << "Element" << head->data << "deleted";
                cur = head;
                head = head->next;
                delete(node);
            } else {
                cur = node = head;
			        while(position>0){
				        position--;
				    cur = node;
				    node = node->next;
			}
			cout<<"Element "<<node->data<<" Deleted."<<endl;
			cur->next = node->next;
			free(node);
            }
        }
    }
    
    void print(){
    	if (head == NULL){
	    	cout<<"List is empty"<<endl;
	    }
	    else {
		    Node *cur = head;
		    cout<<"List: ";
		    while (cur != NULL){
		    	cout << cur->data <<"---";
			    cur = cur->next;
		    }
		   cout<<"NULL"<<endl;
	}
}
    
    
};


int main()
{
   LinkedList linkedList;
   linkedList.insert_first(1);
   linkedList.print();
   linkedList.insert_first(2);
   linkedList.print();
   linkedList.insert_first(3);
   linkedList.print();
   linkedList.insert_at(4, 2);
   linkedList.print();
   linkedList.delete_at(1);
   linkedList.print();
   return 0;
}


