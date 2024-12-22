# Singly Linked List Implementation in C++

## Overview
This project provides a basic implementation of a singly linked list in C++. It supports core linked list operations such as insertion, deletion, accessing elements, and displaying the list contents. 

## Features
1. **Insert Operations**:
   - Append a node to the end of the list.
   - Insert a node at a specified index.

2. **Remove Operation**:
   - Remove a node by its index.

3. **Access Operation**:
   - Retrieve the value of a node by its index.

4. **Utility Functions**:
   - Calculate the length of the list.
   - Display all the nodes in the list in a readable format.

## Class and Methods
### `Node` Class
- Represents an individual node in the linked list.
- Attributes:
  - `data`: Stores the data for the node.
  - `next`: Pointer to the next node in the list.

### `singlely_Linked` Class
#### Private Methods
- `Node* get_newNode(int data)`: Creates and returns a new node with the given data.

#### Public Methods
- **`void insert(int data)`**
  - Inserts a new node with the given data at the end of the list.

- **`void insert_at(int data, int req_index)`**
  - Inserts a new node with the given data at the specified index.

- **`void remove(int index)`**
  - Removes the node at the specified index.

- **`int get(int index)`**
  - Returns the value of the node at the specified index.
  - Returns `INT_MAX` if the index is invalid.

- **`int lenght()`**
  - Returns the length of the linked list.

- **`void display_items()`**
  - Displays all the elements of the linked list in a comma-separated format.

## Example Usage
```cpp
#include <iostream>
#define LIST_SIZE (10)

int main() {
    singlely_Linked linked_list;

    // Insert elements into the list
    for (int i = 0; i < LIST_SIZE; i++) {
        linked_list.insert(i);
    }

    // Display the list
    linked_list.display_items(); // Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    // Insert at a specific index
    linked_list.insert_at(99, 5);
    linked_list.display_items(); // Output: [0, 1, 2, 3, 4, 99, 5, 6, 7, 8, 9]

    // Remove an element
    linked_list.remove(5);
    linked_list.display_items(); // Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    // Get the value at a specific index
    int value = linked_list.get(3);
    std::cout << "Value at index 3: " << value << std::endl; // Output: 3

    // Get the length of the list
    std::cout << "Length of list: " << linked_list.lenght() << std::endl; // Output: 10

    return 0;
}
```

## Notes
- The list is zero-indexed.
- Ensure valid indices when using `insert_at`, `remove`, or `get` methods to avoid unexpected behavior.

## Requirements
- C++ compiler (e.g., g++)

## Compilation and Execution
To compile and run the program:
```bash
g++ -o linked_list linked_list.cpp
./linked_list
```

## Author
This implementation was created for educational purposes to understand and work with linked lists in C++.
