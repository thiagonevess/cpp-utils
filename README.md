#Utilities written in C++

### 1. LinkedList: Simple generic linked list implementation in C++

*Usage*

```c++
#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

int main() 
{
  LinkedList<string>* list = new LinkedList<string>();
  list->Insert("Jack");
  list->Insert("Daniel");
  list->Insert("Samantha");
  list->Insert("Tealc");
  cout << list->ToString();
  list->RemoveAt(0);
  cout << list->ToString();
  delete(list);
}
```

*Output*
```
LIST...
0077A528 is Jack <HEAD>
0077A560 is Daniel
0077A598 is Samantha
0077A5D0 is Tealc

LIST...
0077A560 is Daniel <HEAD>
0077A598 is Samantha
0077A5D0 is Tealc
```