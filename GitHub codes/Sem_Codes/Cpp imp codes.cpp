// linear search
#include <iostream>
using namespace std;
int main()
{
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements: ";
        cin >> arr[i];
    }
    cout << "Enter element you want to search: ";
    cin >> key;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == key)
        {
            cout << "Element " << key << " found at " << j + 1;
            return 0;
        }
    }
    cout << "Element not found";
}

// binary search
#include <iostream>
using namespace std;
int main()
{
    int n, upper, lower, mid, key;
    cout << "Enter no. of elements to enter: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element in sorted form: ";
        cin >> a[i];
    }
    upper = n - 1;
    lower = 0;
    cout << "Enter element to search: ";
    cin >> key;
    while (lower <= upper)
    {
        mid = (upper + lower) / 2;
        if (a[mid] == key)
        {
            cout << "Element " << key << " found at " << mid;
            break;
        }
        else if (a[mid] > key)
        {
            upper = mid - 1;
        }
        else
        {
            lower = mid + 1;
        }
    }
    return 0;
}

// bubble sort
#include <iostream>
using namespace std;
int main()
{
    int n, j, i, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter elements: ";
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

// selection sort
#include <iostream>
using namespace std;
int main()
{
    int n, min, i, temp;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter elements: ";
        cin >> arr[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n + 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

// insertion sort
#include <iostream>
using namespace std;
int main()
{
    int n, key, j, i;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter elements: ";
        cin >> arr[i];
    }
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "SORTED ELEMENTS " << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

// quick sort - pivot is last element
#include <iostream>
using namespace std;
int a[] = {30, 50, 20, 60, 40, 25, 70, 35};
int n = 8;
int partition(int p, int r)
{
    int i = p;
    int j = p - 1;
    int k;
    int pivot = a[r];
    for (i = p; i < n - 1; i++)
    {
        if (a[i] < pivot)
        {
            j++;
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    k = a[j + 1];
    a[j + 1] = a[r];
    a[r] = k;
    return (j + 1);
}
int quick_sort(int p, int r)
{
    if (p < r)
    {
        int q = partition(p, r);
        quick_sort(p, q - 1);
        quick_sort(q + 1, r);
    }
}
int main()
{
    quick_sort(0, n - 1);
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << endl;
    cout << "Arnav Tiwari" << endl;
    cout << "21BCE10048";
}

//pivot is 1st element
#include <iostream>
using namespace std;
int partition(int arr[], int p, int r)
{
    int pivot = arr[p];
    int k = 0;
    for (int i = p + 1; i <= r; i++)
    {
        if (arr[i] <= pivot)
        {
            k++;
        }
    }
    int pivotIndex = p + k;
    swap(arr[pivotIndex], arr[p]);
    int i = p, j = r;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int p, int r)
{
    if (p >= r)
    {
        return;
    }
    int q = partition(arr, p, r);
    quickSort(arr, p, q - 1);
    quickSort(arr, q + 1, r);
}
int main()
{
    int arr[] = {90, 100, 50, 30, 70, 40, 60, 20, 10, 80};
    int n = 10;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }
    return 0;
}

// Merge sort code
#include <stdio.h>
int a[] = {67, 23, 45, 79, 15, 46, 78, 34};
void merge(int a[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = a[p + i];
    }
    for (int j = 0; j < n2; j++)
    {

        right[j] = a[q + 1 + j];
    }

    i = 0,
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
merge_sort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
int main()
{
    int p = 0;
    int r = 7;
    int i;
    merge_sort(a, p, r);
    printf("the sorted array\n");
    for (i = 0; i < r + 1; i++)
        printf("%d\n", a[i]);
    return 0;
}

// singly linked list normal order
#include <iostream>
#include <cstdlib> //for malloc
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
struct node *insert(struct node *head, int k)
{
    struct node *temp;
    temp = create(k);
    if (head == NULL)
        head = temp;
    else
    {
        struct node *k;
        k = head;
        while (k->next != NULL)
        {
            k = k->next;
        }
        k->next = temp;
    }
    return head;
}
traverse(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}
int main()
{
    struct node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    traverse(head);
}

// SLL C syntax reverse order
#include <stdio.h>
#include <malloc.h> //for malloc
struct node
{
    int data;
    struct node *next;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
struct node *insert(struct node *head, int k)
{
    struct node *temp;
    temp = create(k);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}
int traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
}
int main()
{
    struct node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    traverse(head);
}

// inserting element in SLL
struct node *insert_ele(struct node *head, int k, int p)
{
    struct node *temp, *trav;
    temp = create(k);
    if (head == NULL)
        head = temp;
    else
    {
        trav = head;
        while (trav != NULL)
        {
            if (trav->data == p)
            {
                break;
            }
            trav = trav->next;
        }
        if (trav == NULL)
        {
            cout << "seraching element is not found";
        }
        temp->next = trav->next;
        trav->next = temp;
    }
    return head;
}

// deleting first node
struct node *del_beg(struct node *head)
{
    if (head == NULL)
        printf("we do not have any node");
    else
    {
        struct node *k;
        k = head;
        head = head->next;
        free(k);
    }
    return head;
}

// deleting last node
struct node *del_last(struct node *head)
{
    if (head == NULL)
        printf("we do not have any node");
    else
    {
        struct node *p, *q;
        p = head;
        while (p->next->next != NULL)
            p = p->next;
        q = p->next;
        p->next = NULL;
        free(q);
    }
    return head;
}

// given singly linked list in reverse order
#include <iostream>
#include <cstdlib> //for malloc
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
struct node *insert(struct node *head, int k)
{
    struct node *temp;
    temp = create(k);
    if (head == NULL)
        head = temp;
    else
    {
        struct node *k;
        k = head;
        while (k->next != NULL)
        {
            k = k->next;
        }
        k->next = temp;
    }
    return head;
}
traverse(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

// to print alternate nodes in SLL
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

// Function to reverse the list
void reverse(struct node **head_ref)
{
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}
int main()
{
    struct node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    traverse(head);
    reverse(&head);
    cout << endl;
    cout << "Reversed Linked List" << endl;
    traverse(head);
    return 0;
}

//remove duplicate from sorted SLL
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void removeDuplicates(Node *head)
{
    Node *current = head;
    Node *next_next;
    if (current == NULL)
    {
        return;
    }
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
    cout << "Linked list before duplicate removal ";
    printList(head);
    removeDuplicates(head);
    cout << "\nLinked list after duplicate removal ";
    printList(head);
    return 0;
}

//intersection of 2 given LL 
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **head_ref, int new_data);
bool isPresent(struct Node *head, int data);
struct Node *getUnion(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;
    while (t1 != NULL)
    {
        push(&result, t1->data);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
    return result;
}
struct Node *getIntersection(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1;
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push(&result, t1->data);
        t1 = t1->next;
    }
    return result;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
bool isPresent(struct Node *head, int data)
{
    struct Node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *intersecn = NULL;
    struct Node *unin = NULL;
    push(&head1, 4);
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);
    push(&head2, 7);
    push(&head2, 6);
    push(&head2, 5);
    push(&head2, 4);
    push(&head2, 3);
    intersecn = getIntersection(head1, head2);
    cout << "\n First list is " << endl;
    printList(head1);
    cout << "\n Second list is " << endl;
    printList(head2);
    cout << "\n Intersection list is " << endl;
    printList(intersecn);
    return 0;
}

// doubly linked list basic (dll)
#include <iostream>
#include <cstdlib> //for malloc
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
int main()
{
    struct node *p, *q, *r;
    p = create(100);
    q = create(200);
    r = create(300);
    p->next = q;
    q->next = r;
    q->prev = p;
    r->prev = q;
    cout << q->prev->data << endl;
    cout << q->data << endl;
    cout << q->next->data << endl; // data access from any node
    // cout << q->data << endl;
    // cout << q->prev->data << endl; for reverse
    return 0;
}

// insert node at begenning dll
#include <iostream>
#include <cstdlib> //for malloc
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
struct node *insert_beg(struct node *head, int k)
{
    struct node *temp;
    temp = create(k);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}
display(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    struct node *head = NULL;
    head = insert_beg(head, 100);
    head = insert_beg(head, 200);
    display(head);
    return 0;
}

// node at end dll (some error)
#include <iostream>
#include <cstdlib> //for malloc
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
struct node *insert_end(struct node *head, int k)
{
    struct node *temp, *p;
    temp = create(k);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
            p->next = temp;
            temp->prev = p;
        }
    }
    return head;
}
display(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}
int main()
{
    struct node *head = NULL;
    head = insert_end(head, 100);
    head = insert_end(head, 200);
    display(head);
    return 0;
}

// all operations dll
#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
struct node *insert_atno(struct node *head, int k, int no)
{
    struct node *temp, *p;
    temp = create(k);
    if (head == NULL)
        head = temp;
    else
    {
        p = head;
        while (p->data != no)
            p = p->next;
        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
        temp->prev = p;
    }
    return head;
}
struct node *insert_atlast(struct node *head, int k)
{
    struct node *temp, *p;
    temp = create(k);
    if (head == NULL)
        head = temp;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
        temp->prev = p;
    }
    return head;
}
void display(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    struct node *head = NULL;
    int k, p;
    head = insert_atlast(head, 100);
    head = insert_atlast(head, 200);
    head = insert_atlast(head, 500);
    head = insert_atlast(head, 600);
    head = insert_atlast(head, 700);
    display(head);
    cout << "enter the value of node: ";
    cin >> k;
    cout << "enter the number value: ";
    cin >> p;
    head = insert_atno(head, k, p);
    display(head);
    return 0;
}

// all operations (print in reverse)
#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
struct node *insert_atbeg(struct node *head, int k)
{
    struct node *temp;
    temp = create(k);
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}
void display(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}
struct node *del_beg(struct node *head)
{
    struct node *p;
    if (head == NULL)
        cout << "no nodes avilable" << endl;
    else
    {
        p = head;
        head = head->next;
        free(p);
    }
    return head;
}
struct node *del_last(struct node *head)
{
    struct node *p;
    p = head;
    if (head == NULL)
        cout << "no nodes avilable" << endl;
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->prev->next = NULL;
        free(p);
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    head = insert_atbeg(head, 100);
    head = insert_atbeg(head, 200);
    head = insert_atbeg(head, 300);
    head = insert_atbeg(head, 400);
    head = insert_atbeg(head, 500);
    head = insert_atbeg(head, 600);
    head = insert_atbeg(head, 700);
    head = insert_atbeg(head, 800);
    display(head);
    head = del_beg(head);
    display(head);
    head = del_last(head);
    display(head);
    return 0;
}

//delete duplicate nodes from sorted DLL
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void push(struct node **headr, int newval)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = newval;
    newnode->prev = nullptr;
    newnode->next = (*headr);
    if ((*headr) != nullptr)
    {
        (*headr)->prev = newnode;
    }
    (*headr) = newnode;
}
void delete_node(struct node **headr, struct node *to_delete)
{
    if (*headr == nullptr || to_delete == nullptr)
    {
        return;
    }
    if (*headr == to_delete)
    {
        *headr = to_delete->next;
    }
    if (to_delete->next != nullptr)
    {
        to_delete->next->prev = to_delete->prev;
    }
    if (to_delete->prev != nullptr)
    {
        to_delete->prev->next = to_delete->next;
    }
    free(to_delete);
}
void remove_duplicates(node **headr)
{
    if ((*headr) == nullptr || (*headr)->next == nullptr)
    {
        return;
    }
    struct node *temp1, *temp2;
    for (temp1 = *headr; temp1 != nullptr; temp1 = temp1->next)
    {
        temp2 = temp1->next;
        while (temp2 != nullptr)
        {
            if (temp1->data == temp2->data)
            {
                struct node *curr = temp2->next;
                delete_node(headr, temp2);
                temp2 = curr;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
    }
}
int main()
{
    struct node *head = nullptr;
    int size;
    cout << "Enter the number of nodes in the list- ";
    cin >> size;
    cout << "Enter the nodes in the list- ";
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        push(&head, a);
    }
    remove_duplicates(&head);
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}

// stack basic
#include <iostream>
using namespace std;
int s[5];
int n = 5;
int top = -1;
void push(int k)
{
    if (top == n - 1)
        cout << "stack overflow";
    else
    {
        top = top + 1;
        s[top] = k;
    }
}
int pop()
{
    if (top == -1)
        cout << "stack underflow";
    else
        top = top - 1;
    return s[top + 1];
}
int main()
{
    int k;
    push(10);
    push(20);
    push(30);
    k = pop();
    cout << k << endl;
    pop();
    push(50);
    push(100);
    push(200);
    k = pop();
    k = pop();
    cout << k << endl;
    cout << (s[top]) << endl;
    return 0;
}

// stack main codes
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
struct node *push(struct node *head, int k)
{
    struct node *temp;
    temp = create(k);
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}
struct node *pop(struct node *head)
{
    struct node *p;
    if (head == NULL)
        cout << "no node is avilable" << endl;
    else
    {
        p = head;
        head = head->next;
        free(p);
    }
    return head;
}
traverse(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    struct node *head = NULL;
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);
    cout << "top element: " << head->data << endl;
    head = pop(head);
    cout << "top element: " << head->data << endl;
    head = push(head, 40);
    head = pop(head);
    traverse(head);
}

// enque deque codes
#include <iostream>
using namespace std;
int a[5], f = -1, r = -1, size = 5;
void enque(int k)
{
    if (r == size - 1)
    {
        cout << "Queue is full";
    }
    else
    {
        if (f == -1)
        {
            f += 1;
            r += 1;
        }
        else
        {
            r += 1;
        }
        a[r] = k;
    }
}
void deque()
{
    int k;
    if (f == -1)
    {
        cout << "Queue is empty";
    }
    else
    {
        k = a[f];
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f += 1;
        }
    }
    cout << "Deleted element: " << k << endl;
}
int main()
{
    enque(10);
    enque(20);
    deque();
    enque(30);
    enque(40);
    enque(50);
    cout << "Front value (f): " << f << endl;
    cout << "Rear value (r): " << r;
    // enque(60);
    return 0;
}

// tree
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *l;
    struct node *r;
};
struct node *create(int k)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}
struct node *insert(struct node *root, int k)
{
    struct node *temp;
    temp = create(k);
    if (root == NULL)
    {
        root = temp;
    }
    else if (root->data < k)
    {
        root->r = insert(root->r, k);
    }
    else
    {
        root->l = insert(root->l, k);
    }
    return root;
}
preorder(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        cout << root->data << endl;
        preorder(root->l);
        preorder(root->r);
    }
}
inorder(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        inorder(root->l);
        cout << root->data << endl;
        inorder(root->r);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 20);
    cout << "Preorder: " << endl;
    preorder(root);
    cout << "Inorder: " << endl;
    inorder(root);
    return 0;
}
