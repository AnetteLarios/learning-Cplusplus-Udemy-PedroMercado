#include <iostream>
/* Linked list program by Pedro Mercado | Udemy Course.
*/

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
        //Class constructor
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
            //declares a temp node that points to what header is pointing
            Node *temp = header;
            //Header points to the next node that was pointing before
            header = header ->next;
            //deletes what temp is pointing, the first node.
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
            //declares a current node that points to what header is pointing
            Node *current = header;
            //declares a node called previous
            Node *previous;
            //while current is not pointing to null
            while(current->next != NULL){
                    //previous will point to what current is pointing
                previous = current;
                    //current will point to what its next node is pointing
                current = current->next;
         }
        //the tail will point to what previous is pointing
        tail = previous;
        //the node contained in previous will point to null
        previous->next = NULL;
        //delete current node
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
            //declares a node called previous
            Node *previous;
            //declares a node called current that is pointing to the node that header is pointing
            Node *current = header;
            //the cycle will be executed from the first node to the node the user wants to delete
            for(int i = 1; i < position; i++){
                //previous will point to the node that current is pointing
                previous = current;
                //current will acquire its next node
                current = current->next;
            }
            //previous will point to the node that current is pointing
            previous->next = current-> next;
            //delete current node
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
            //creates a new node by the constructor and assigns the data inserted by the user.
            Node *node = new Node(data);
            //declares a new node called previous
            Node *previous;
            //declares a new node called current that points to what header is pointing
            Node *current = header;

            //the cycle will be executed from the first node to the position that the user wants to insert a node in.
            for(int i = 1; i < position; i++){
                //previous will store the node that current is storing
                previous = current;
                //current will store its next node
                current = current -> next;
            }
            //previous will point to the node the user created
            previous->next = node;
            //the new node will point to current
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
