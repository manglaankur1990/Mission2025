#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
    //node(): data(0), next(nullptr) {}    
    node() {
        data = 0;
        next = nullptr;
    }
};

#define struct node node;

void print_node(node* start) {
    while(start) {
        cout << start->data << '\t';
        start = start->next;
    }
    cout << endl;
}

node* create_node(int data) {
    node *temp = new node;
    temp->data = data;
    return temp;
}

void insert_node_at_start(node** start, int data) {
    if(nullptr == *start) {
        *start = create_node(data);
        return;
    }
    node *temp = create_node(data); 
    temp->next = *start;
    *start = temp;
}

void insert_node_at_end(node** start, int data) {
    if(nullptr == *start) {
        *start = create_node(data);
        return;
    }
    node* curr = (*start);
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = create_node(data);
}

void reverse_list(node **start) {
    if(*start == nullptr || (*start)->next == nullptr) {
        return;
    }

    node* temp = *start;
    node* temp1 = nullptr;
    node* temp2 = nullptr;

    while(temp) {
        temp1 = temp->next;
        temp->next = temp2;
        temp2 = temp;
        temp = temp1;
    }
    *start = temp2;
}

int main() {
    node* start = nullptr;
    insert_node_at_end(&start, 5);
    insert_node_at_end(&start, 4);
    insert_node_at_end(&start, 3);
    insert_node_at_end(&start, 2);
    insert_node_at_end(&start, 1);
    insert_node_at_start(&start, 6);
    insert_node_at_start(&start, 7);
    insert_node_at_start(&start, 8);
    insert_node_at_start(&start, 9);

    print_node(start);

    reverse_list(&start);

    print_node(start); 
    return 0;
}