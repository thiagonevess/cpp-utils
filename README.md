#Utilities written in C++

### 1. LinkedList: Simple generic linked list implementation in C++

*Usage*

```c++
LinkedList<string>* list = new LinkedList<string>();
list->Insert("Thiago");
list->Insert("Cida");
list->Insert("Arthur");
list->Insert("Vitor");
cout << list->ToString();
delete(list);
```
