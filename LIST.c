/*
Implement a list of strings using dynamic memory. The list consists of a header storing two items:
• the size of the list, and
• a dynamically allocated array capable of storing only the elements in the list.
In the picture below, the list consists of the strings apple, orange, banana, pear. Its size is 4, and
the dynamic array is large enough to store exactly four strings.

Define a structure to store the size of the list, and a dynamically allocated array that stores the
elements (strings) of the list. You may assume that each element (string) will contain at most 9
lowercase letters. Use a typedef to define LIST as the name of your structure.
Implement the following functions.
(a) create list(void): returns an empty list. For an empty list, the size is zero, and the array is
NULL.
(b) print list(LIST L): print the elements of the list separated by spaces, and terminated by a
newline.
(c) append(LIST L, char *a): appends the string a to the end of the list L, and returns the
modified list.
(d) prepend(LIST L, char *a): prepends the string a at the beginning of the list L, and returns
the modified list.
(e) deletelast(LIST L): deletes the last string of the list, and returns the modified list.
(f) deletefirst(LIST L): deletes the first string of the list, and returns the modified list.
(g) deleteall(LIST L, char *a): deletes all occurrences of the string a in L, and returns the
modified list. Note that the string a must occur as an element in L. If a is a non-trivial substring
of an element, then that element must not be removed. For example, if a is the string pea, and
pear is an element of L, the element pear should not be removed.
Do not forget to use free() where necessary.
Test your code using the following sequence of operations. Use print list to display the list after
each operation.
1 2 3 4
create list() append(banana) prepend(orange) deletefirst()
append(apple) append(pineapple) prepend(apple) deletefirst()
append(lemon) prepend(apple) prepend(lemon) deletefirst()
append(banana) prepend(banana) deletelast() deletefirst()
append(pineapple) prepend(cherry) deletelast() deleteall(plum)
append(pear) prepend(orange) deletelast() deleteall(banana)
append(mango) prepend(banana) deletelast() deleteall(apple)
append(orange) prepend(plum) deletelast() deleteall(cherry)
append(cherry) prepend(apple) deletefirst() deleteall(mango)
Sample output
()
(apple)
(apple,lemon)
(apple,lemon,banana)
(apple,lemon,banana,pineapple)
(apple,lemon,banana,pineapple,pear)
(apple,lemon,banana,pineapple,pear,mango)
(apple,lemon,banana,pineapple,pear,mango,orange)
(apple,lemon,banana,pineapple,pear,mango,orange,cherry)
(apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana)
(apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(lemon,apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana,pineapple)
(lemon,apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry,banana)
(lemon,apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange,cherry)
(lemon,apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango,orange)
(lemon,apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear,mango)
(lemon,apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear)
(apple,orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear)
(orange,apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear)
(apple,plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear)
(plum,banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear)
(banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear)
(banana,orange,cherry,banana,apple,apple,lemon,banana,pineapple,pear)
(orange,cherry,apple,apple,lemon,pineapple,pear)
(orange,cherry,lemon,pineapple,pear)
(orange,lemon,pineapple,pear)
(orange,lemon,pineapple,pear)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 10

typedef struct {
    int size;
    char **elements;
} LIST;

LIST createList() {
    LIST newList;
    newList.size = 0;
    newList.elements = NULL;
    return newList;
}

void printList(LIST L) {
    for (int i = 0; i < L.size; i++) {
        printf("%s", L.elements[i]);
        if (i < L.size - 1) {
            printf(",");
        }
    }
    printf("\n");
}

void append(LIST *L, char *a) {
    L->size++;
    L->elements = realloc(L->elements, L->size * sizeof(char *));
    L->elements[L->size - 1] = strdup(a);
}

void prepend(LIST *L, char *a) {
    L->size++;
    L->elements = realloc(L->elements, L->size * sizeof(char *));
    for (int i = L->size - 1; i > 0; i--) {
        L->elements[i] = L->elements[i - 1];
    }
    L->elements[0] = strdup(a);
}

void deleteLast(LIST *L) {
    if (L->size > 0) {
        free(L->elements[L->size - 1]);
        L->size--;
        L->elements = realloc(L->elements, L->size * sizeof(char *));
    }
}

void deleteFirst(LIST *L) {
    if (L->size > 0) {
        free(L->elements[0]);
        for (int i = 0; i < L->size - 1; i++) {
            L->elements[i] = L->elements[i + 1];
        }
        L->size--;
        L->elements = realloc(L->elements, L->size * sizeof(char *));
    }
}

void deleteAll(LIST *L, char *a) {
    int count = 0;
    for (int i = 0; i < L->size; i++) {
        if (strcmp(L->elements[i], a) == 0) {
            free(L->elements[i]);
            count++;
        }
    }
    
    int newIndex = 0;
    for (int i = 0; i < L->size; i++) {
        if (strcmp(L->elements[i], a) != 0) {
            L->elements[newIndex] = L->elements[i];
            newIndex++;
        }
    }
    
    L->size -= count;
    L->elements = realloc(L->elements, L->size * sizeof(char *));
}

int main() {
    LIST myList = createList();

    printList(myList);

    append(&myList, "banana");
    printList(myList);

    prepend(&myList, "orange");
    printList(myList);

    deleteFirst(&myList);
    printList(myList);

    append(&myList, "apple");
    append(&myList, "pineapple");
    prepend(&myList, "apple");
    deleteFirst(&myList);
    printList(myList);

    append(&myList, "lemon");
    prepend(&myList, "apple");
    prepend(&myList, "lemon");
    deleteFirst(&myList);
    printList(myList);

    append(&myList, "banana");
    prepend(&myList, "banana");
    deleteLast(&myList);
    deleteFirst(&myList);
    printList(myList);

    append(&myList, "pineapple");
    prepend(&myList, "cherry");
    deleteLast(&myList);
    deleteAll(&myList, "plum");
    printList(myList);

    append(&myList, "pear");
    prepend(&myList, "orange");
    deleteLast(&myList);
    deleteAll(&myList, "banana");
    printList(myList);

    append(&myList, "mango");
    prepend(&myList, "banana");
    deleteLast(&myList);
    deleteAll(&myList, "apple");
    printList(myList);

    append(&myList, "orange");
    prepend(&myList, "plum");
    deleteLast(&myList);
    deleteAll(&myList, "cherry");
    printList(myList);

    append(&myList, "cherry");
    prepend(&myList, "apple");
    deleteFirst(&myList);
    deleteAll(&myList, "mango");
    printList(myList);

    return 0;
}
