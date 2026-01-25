# C++ STL Data Structures Hierarchy

This repository contains examples and explanations of commonly used **C++ Standard Template Library (STL) data structures** for competitive programming and general usage. Each file demonstrates syntax, operations, and usage patterns with clear comments.

---

## Key Characteristics

### Containers
- Can store multiple elements
- Have methods to add/remove elements (except fixed-size `array`)
- Provide iterators
- Can dynamically resize (except `array`)
- Are template classes

### Non-containers
- Fixed number of elements (`pair`: always 2, `tuple`: fixed at construction)
- Simple aggregation of values
- No dynamic resizing
- Used for grouping related data

---

## STL Data Structures Covered

### Sequence Containers
| Container      | Description                                                                                  | Complexity Notes                  |
|----------------|----------------------------------------------------------------------------------------------|----------------------------------|
| `vector`       | Dynamic array, supports random access, efficient at back insertion/deletion                  | push_back/pop_back O(1), insert O(n) |
| `deque`        | Double-ended queue, supports insert/delete at both ends efficiently                           | push/pop front/back O(1)         |
| `list`         | Doubly linked list, supports efficient insertion/deletion anywhere                            | O(1) for insert/erase via iterator |
| `forward_list` | Singly linked list, lightweight, only forward traversal                                      | O(1) for insert/erase via iterator |

### Container Adapters
| Adapter        | Description                                                                                  |
|----------------|----------------------------------------------------------------------------------------------|
| `stack`        | LIFO (Last In, First Out), access only top element                                           |
| `queue`        | FIFO (First In, First Out), access only front/back                                           |
| `priority_queue` | Heap-based, default max-heap, min-heap with comparator                                      |

### Associative Containers
| Container        | Description                                                                                  | Key Characteristics              |
|------------------|----------------------------------------------------------------------------------------------|---------------------------------|
| `set`            | Stores unique ordered elements                                                               | Balanced tree, O(log n) ops     |
| `multiset`       | Like `set` but allows duplicates                                                             | Balanced tree, O(log n) ops     |
| `map`            | Key-value store, unique keys, ordered by key                                                 | Balanced tree, O(log n) ops     |
| `multimap`       | Like `map` but allows duplicate keys                                                         | Balanced tree, O(log n) ops     |
| `unordered_set`  | Unique elements, hash table based, average O(1)                                              | No ordering                     |
| `unordered_multiset` | Like `unordered_set` but allows duplicates                                               | No ordering                     |
| `unordered_map`  | Key-value store, unique keys, hash table based                                              | Average O(1), worst O(n)        |
| `unordered_multimap` | Like `unordered_map` but allows duplicate keys                                           | Average O(1), worst O(n)        |

### Non-Container Utilities
| Utility        | Description                                                                                  |
|----------------|----------------------------------------------------------------------------------------------|
| `pair`         | Aggregates two heterogeneous values, accessed via `.first` and `.second`                    |
| `tuple`        | Aggregates fixed number of heterogeneous values                                             |
| `array`        | Fixed-size array, behaves like a lightweight container with random access                    |

---

## Usage Notes

- Sequence containers are preferred when element order matters.
- Associative containers are preferred for fast search, insertion, and deletion by key.
- Container adapters provide restricted access interfaces on top of sequence containers.
- Non-container utilities like `pair` and `tuple` are useful for grouping related data without creating a struct/class.

---

## Files Included

| File                         | Description                             |
|-------------------------------|-----------------------------------------|
| `vector.cpp`                  | Examples of `vector` usage              |
| `stack.cpp`                   | Examples of `stack` usage               |
| `queue.cpp`                   | Examples of `queue` usage               |
| `priority_queue.cpp`          | Examples of `priority_queue` usage      |
| `deque.cpp`                   | Examples of `deque` usage               |
| `list.cpp`                    | Examples of `list` usage                |
| `set.cpp`                     | Examples of `set`, `multiset`, `unordered_set` |
| `map.cpp`                     | Examples of `map`, `multimap`, `unordered_map` |
| `pair.cpp`                    | Examples of `pair` usage                |

---

## Reference

- [C++ STL Documentation (cppreference.com)](https://en.cppreference.com/w/cpp/container)
- [C++ STL Tutorial (GeeksforGeeks)](https://www.geeksforgeeks.org/cpp-stl/)

---

## License

This repository is open-source and available under the MIT License.
