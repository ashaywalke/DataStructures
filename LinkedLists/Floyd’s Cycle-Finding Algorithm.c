#include<stdio.h>
#include<stdlib.h>
// Floyd’s Cycle-Finding Algorithm: To Detect loops in a linkedlist

struct Node{
  int data;
  struct Node* next;
};

void push(struct Node**head_ref, int new_data){
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node -> data = new_data;
  new_node -> next = (*head_ref);
  (*head_ref) = new_node;
}

// Declaring 2 pointers one which will traverse fast and other which will traverse slow

int checkloop(struct Node*head){
  struct Node *fast = head;
  struct Node *slow = head;

  while(slow && fast && fast-> next){
    slow = slow -> next;
    fast = fast -> next -> next;
    if(fast == slow){
      puts("\n\n");
      puts("Found Loop");
      return 1;
    }
}
puts("\n\n");
puts("Loop Not Found");
return 0;
}

// Driver Programme 
int main()
{
struct Node* head = NULL;
push(&head, 20);
push(&head, 4);
push(&head, 15);
push(&head, 10);
checkloop(head);
return 0;
}
