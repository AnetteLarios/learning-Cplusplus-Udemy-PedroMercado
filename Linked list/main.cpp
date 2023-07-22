#include <iostream>

using namespace std;
//Class node
class Node{
public:
    int data;
    //This node is pointing to the next node
    Node *next;

    //Constructor
    Node(int data){
         this->data = data;
         next = NULL;;
    }
};
//Class Linked List
class LinkedList{
    //As elements has node objects, header and Tail. Also has an integer that stores the size of the linked list.
    private:
        Node *header;
        Node *tail;
        int size;
        //Linked List  constructor
    public:
        LinkedList(){
            //Initializes the header and tail node as NULL, and the size of the Linked list as 0.
            header = NULL;
            tail = NULL;
            size = 0;
        }

    //Class destructor
    ~LinkedList(){
        Node *deleteNext;

        while(header != NULL){
            deleteNext = header->next;
            delete header;
            header = deleteNext;
        }
    }

    //Integer method that return the size of the linked list
     int getSize(){
        return size;
    }

    //Append method
    void append(int data){
        //Create a new node
        Node *n = new Node(data);

        //If the list is empty
        if (header ==  NULL){
            //As the node that we are just adding is the first and last node, header and tail have to point to that new node
            header = n;
            tail = n;
        }
        //If the list is not empty
        else{
            //The last element is going to point to this new element, which is its NEXT element
            tail->next = n;
            //And the tail is going to point to this new element as it is the last element added on within the list
            tail = n;
        }
        //Increment the size of the list
        size++;
    }
    //Prepend method
    void prepend(int data){

        //Create a new node with the constructor
        Node *n = new Node(data);

        //Case 1: Empty list
        if(header == NULL){
           header = n;
           tail = n;
        }

        //Case 2: If the list is not empty
        else{
            Node *temp = header;
            header = n;
            n->next = temp;
        }

        size++;
    }
    //printLinkedList method
    void printLinkedList(){
        Node *temp = header;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void removeFirstElementLinkedList(){

        if(header != NULL){
            Node *temp = header;
            header = header ->next;
            delete temp;
            size--;
        }
    }

    void removeLastElementLinkedList(){

        //Case 2: One element within the list
        if(header ->next == NULL){
            removeFirstElementLinkedList();
        }

        //Case 3: More than one node within the list
        else if(header != NULL){
            Node *current = header;
            Node *previous;

         while(current->next != NULL){
            previous = current;
            current = current->next;
         }
        tail = previous;
        previous->next = NULL;
        delete current;
        size--;

        }
    }

    void removeCertainElementLinkedList(int position){

        //Case 1: Invalid position
        if(position == 0 || position > size){
           cout<<"Invalid position";
        }

        //Case 2: First Element
        if(position == 1){
            removeFirstElementLinkedList();
        }

        //Case 3: Last Element
        if(position == size){
            removeLastElementLinkedList();
        }

        //Case 4: Valid element between the first and the last
        else if ( header != NULL){
            Node *previous;
            Node *current = header;
            for(int i = 1; i < position; i++){
                previous = current;
                current = current->next;
            }
            previous->next = current-> next;
            delete current;
        }
        size--;
    }

    void insertNodeAtACertainPositionWithinLinkedList(int position, int data){

        //Case 1: Verify a valid position
        if(position > size +1 || position < 1){
            cout<<"Please enter a valid position."<<endl;
        }
        //Case 2: Insert node at the beginning of the list
        else if (position == 1){
            prepend(data);
        }

        //Case 3: Insert node at the end of the list.
        else if (position == size + 1){
            append(data);
        }

        //Case 4: If the user wants to insert a node in a position between the first and last node.
        else{
            Node *node = new Node(data);
            Node *previous;
            Node *current = header;

            for(int i = 1; i < position; i++){
                previous = current;
                current = current -> next;
            }
            previous->next = node;
            node->next = current;
        }
        size++;
    }
};

int main(){
    //Operations with Linked list;
    LinkedList list;
    int position=0;
    int data=0;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5),
    list.prepend(0);
    list.printLinkedList();
    cout<<"The size of the list is: "<<list.getSize();
    cout<<endl;
    list.removeFirstElementLinkedList();
    list.printLinkedList();
    cout<<"Size of the linked list after deletion: "<<list.getSize()<<endl;
    list.removeLastElementLinkedList();
    list.printLinkedList();
    cout<<"Size of the list after deletion: "<<list.getSize()<<endl;
    position = 0;
    cout<<"Please select a certain node to delete: "<<endl;
    cin>>position;
    list.removeCertainElementLinkedList(position);
    list.printLinkedList();
    cout<<"Size of the linked list after deletion: "<<list.getSize()<<endl;
    cout<<"Please insert the position you want to insert the node in:"<<endl;
    cin>>position;
    cout<<"Please insert the data you want to insert within the node:"<<endl;
    cin>>data;
    list.insertNodeAtACertainPositionWithinLinkedList(position, data);
    cout<<"List after the insertion: "<< endl;
    list.printLinkedList();
    cout<<"Size after the insertion: "<< list.getSize();
}
