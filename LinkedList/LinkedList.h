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

using namespace std;

/** \brief Element of the Linked List
 *
 */

template <class T>
class Node
{
public:
    Node() {};
    Node(T data);
    T buffer;
    Node* next;
};

/** \brief Instantiate a new Node using data as the buffer
 *
 * \param  T: data
 *
 */

template <class T>
Node<T>::Node(T data)
{
    this->buffer = data;
    this->next = NULL;
}

/** \brief The Linked List class
 *
 */

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

/** \brief Instantiate a new Linked List
 *
 */

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

/** \brief Insert a new element on the linked list
 *
 * \param T data: new data to be inserted
 */

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

/** \brief Return the node at a given position
 *
 * \param index: index of the item to get
 * \return Node at a given position
 *
 */

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

/** \brief Removes an item at a given position
 *
 * \param index: item to be removed
 */
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

/** \brief Get the data of a given position
 *
 * \param index: item to search
 * \return Data of the given position
 *
 */
template <class T>
T LinkedList<T>::GetBufferAt(int index)
{
    return ItemAt(index)->buffer;
}

/** \brief Set the head (first item) of the linked list
 *
 * \param newHead: node of the new head
 */
template <class T>
void LinkedList<T>::SetHead(Node<T>* newHead)
{
    if (head == NULL)
        throw logic_error("Bad parameter");

    this->head = newHead;
}

/** \brief Get the next element of the list
 *
 * \return Next element of the list
 */
template <class T>
Node<T>* LinkedList<T>::GetNext()
{
    return this->head->next;
}

/** \brief Number of items in the list
 *
 * \return Number of items in the list
 *
 */
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

/** \brief Print the list
 *
 * \return string with elements of the list
 */
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
