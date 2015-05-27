/*
 * This file is copyright 2015 Thiago Neves <thiago.nsantos@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THIAGO NEVES BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <sstream>
#include <stdexcept>

/*
LinkedList<string>* list = new LinkedList<string>();
list->Insert("Thiago");
list->Insert("Cida");
list->Insert("Arthur");
list->Insert("Vitor");

cout << list->ToString();

delete(list);
*/

using namespace std;

template <class T>
class Node
{
public:
    Node() {};
    Node(T data);
    T buffer;
    Node* next;
};

template <class T>
Node<T>::Node(T data)
{
    this->buffer = data;
    this->next = NULL;
}

template <class T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList();
    ~LinkedList();

    void Insert(T data);
    Node<T>* ItemAt(int index);
    void RemoveAt(int index);

    T GetBufferAt(int index);
    void SetHead(Node<T>* newHead);
    Node<T>* GetNext();
    unsigned long Count();
    string ToString();
};

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (head != NULL)
    {
      Node<T>* next = head->next;
      delete(head);
      head = next;
    }
}

template <class T>
void LinkedList<T>::Insert(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node<T>* headAux = head;
        while (head->next != NULL)
            head = head->next;

        head->next = newNode;
        head = headAux;
    }
}

template <class T>
Node<T>* LinkedList<T>::ItemAt(int index)
{
    Node<T>* headAux = this->head;
    Node<T>* ret = NULL;

    int count = 0;
    while (this->head != NULL)
    {
        if (index == count)
        {
            ret = head;
            break;
        }

        head = head->next;
        count++;
    }

    head = headAux;
    return ret;
}

template <class T>
void LinkedList<T>::RemoveAt(int index)
{
    if (index == 0)
    {
        Node<T>* removed = ItemAt(0);
        head = head->next;
        delete(removed);
    }
    else
    {
        Node<T>* prev = ItemAt(index - 1);
        Node<T>* removed = prev->next;

        if (removed == NULL)
            throw logic_error("List index out of bounds");

        prev->next = prev->next->next;

        delete(removed);
    }
}

template <class T>
T LinkedList<T>::GetBufferAt(int index)
{
    return ItemAt(index)->buffer;
}

template <class T>
void LinkedList<T>::SetHead(Node<T>* newHead)
{
    if (head == NULL)
        throw logic_error("Bad parameter");

    this->head = newHead;
}

template <class T>
Node<T>* LinkedList<T>::GetNext()
{
    return this->head->next;
}

template <class T>
unsigned long LinkedList<T>::Count()
{
    unsigned long count = 0;
    Node<T>* headAux = head;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    head = headAux;

    return count;
}

template <class T>
string LinkedList<T>::ToString()
{
    int i = 0;
    ostringstream ret;
    cout << "\n\nLIST...\n";
    string token = " <HEAD> ";
    Node<T>* headAux = head;
    while (head != NULL)
    {
        if (i++ > 0) token = "";
        ret << head << " is " << (T)head->buffer << token << endl;
        head = head->next;
    }

    head = headAux;
    return ret.str();
}

#endif //LINKEDLIST_H
