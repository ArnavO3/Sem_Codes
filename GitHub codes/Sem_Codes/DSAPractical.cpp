#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void printAlternateNode(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        if (count % 2 == 0)
        {
            cout << head->data << " ";
        }
        count++;
        head = head->next;
    }
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    struct Node *head = NULL;
    push(&head, 100);
    push(&head, 80);
    push(&head, 60);
    push(&head, 40);
    push(&head, 20);
    push(&head, 0);
    printAlternateNode(head);
    cout << endl;
    cout << "Arnav Tiwari" << endl;
    cout << "21BCE10048";
    return 0;
}