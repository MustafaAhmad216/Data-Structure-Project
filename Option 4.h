#pragma once
#include <iostream>
using namespace std;

// implementation of queue (queue using liked list)

template<class T> // dyvamic data type 
class queue {
    struct nod {
        T item; //dynamic item
        nod* next; // the pointer of next node
    };
    nod* front, * rear;
    int count;
public:
    //constrcture
    queue() {
        front = rear = NULL; // when program run
        count = 0;
    }
    bool empty() {
        return count == 0;  // return front==NULL;
    }
    // to traverse and Know the node^s size
    int size() {
        return count;
    }
    T getfront() {
        return front->item;
    }
    T getrear() {
        return rear->item;
    }
    void push(T element) { // enqueue >>  T-> indicate that dynamic element
        if (empty()) {
            front = new nod; // creat new node
            front->item = element; // equal the value of element to node
            front->next = NULL; // next of the new node = null
            rear = front; // because of The firt new node -> front = rear
            ++count;
        }
        else {
            nod* newnode = new nod; //creat new node
            newnode->item = element;// next of the new node = null
            newnode->next = NULL;
            rear->next = newnode;
            rear = newnode;
            ++count;
        }
    }
    void pop() {
        if (count == 0)cout << "queue is empty on dequeu..\n"; // if (empty())
        else {
            if (count == 1) {// front == rear }

                front = NULL;
                rear = NULL;
                --count;
            }
            else {
                nod* temp = front; // temp as a continar
                front = front->next;
                temp->next = NULL;
                delete temp;
                --count;
            }
        }
    }

};
//  4)  implementation of  level order  of BST traverse using queue *********************************
// A Binary Tree Node
struct nod {
    int h_left, h_right, bf, value;
    nod* left, * right;
};
class tree {
private:
    nod* get_node(int key) { //key => the value ''
        nod* new_node;
        new_node = new nod;                          //create a new node dynamically

        new_node->h_left = 0; new_node->h_right = 0;
        new_node->bf = 0;
        new_node->value = key;                       //store the value from given key

        new_node->left = NULL; new_node->right = NULL;
        return new_node;
    }


public:
    nod* root;
    tree() {
        root = NULL;                           //set root as NULL at the beginning
    }

    void levelorder_traversal(nod* root) {

        queue <nod*> que; //que => the data type is node
        nod* item; // traversal item 
        que.push(root); //insert the root at first (root is node)
        while (!que.empty()) //get the element from the front end
        {
            item = que.getfront();
            cout << item->value << "  ";

            if (item->left != NULL)             //When left child is present, insert into queue
                que.push(item->left);

            if (item->right != NULL)            //When right child is present, insert into queue
                que.push(item->right);

            que.pop();                          //remove the item from queue
        }
    }
    nod* insert_node(nod* root, int key) {
        if (root == NULL) {
            return (get_node(key));                          //when tree is empty, create a node as root
        }
        if (key < root->value) {                             //when key is smaller than root value, go to the left
            root->left = insert_node(root->left, key);
        }
        else if (key > root->value) {                       //when key is greater than root value, go to the right
            root->right = insert_node(root->right, key);
        }
        return root;                                        //when key is already present, do not insert it again
    }
};

void Option4()
{
       nod* root;
       tree my_tree;

       cout << "\t\t\t\t\t\t *Binary Search Tree option* \t\t\t\t\n\n\n\n";
       cout << " Please, Enter number of items you want to add: ";
       int s; cin >> s;   
       cout << endl;
       for (int i = 1; i <= s; i++){ 
       int item;
       cout << " Please, Enter the value of item " << i << " :  ";
       cin >> item;
       my_tree.root = my_tree.insert_node(my_tree.root, item);
       }
       cout << "\n You have entered (" << s << ") item(s) \n\n\n";
       cout << " BST in level order is : [ ";
       my_tree.levelorder_traversal(my_tree.root);
       cout << "]\n\n";
       cout << " Hit Enter To return\n";
     
}

