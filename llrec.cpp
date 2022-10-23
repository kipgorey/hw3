#include "llrec.h"

#include <iostream>
#include <string>

using namespace std;



void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  // similar to odds / even linked list split

  if(head == nullptr)
  {
    head = NULL;
    return;
  }

  if(head->val <= pivot) // place into smaller list
  {
    
    smaller = head;
    head = head->next;
    smaller->next = NULL;
    llpivot(head, smaller->next, larger, pivot);

  } else if(head->val > pivot) { // place into larger list

    larger = head;
    head = head->next;
    larger->next = NULL;
    llpivot(head, smaller, larger->next, pivot);

  }

}








