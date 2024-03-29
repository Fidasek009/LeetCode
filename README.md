# LeetCode
This is my repo for solving LeetCode challenges

[![LeetCode Stats](https://leetcard.jacoblin.cool/fidasek009?theme=dark)](https://leetcode.com/fidasek009/)

# CheatSheet

## The Big-O notation
- always count the worst case scenario
- don't use multiplications **O(2n)** -> **O(n)**

![O](https://leetcode.com/explore/interview/card/cheatsheets/720/resources/Figures/DSA/Chapter_11/big_o.png)

### Expected time complexity based on input size
| input size | time complexity |
| :---: | :---: |
| 0 - 10 | O( n! ) |
| 10 - 20 | O( 2<sup>n</sup> ) |
| 20 - 100 | O( n<sup>3</sup> ) |
| 100 - 1,000 | O( n<sup>2</sup> ) |
| 1,000 - 10<sup>5</sup> | O( n log n ) |
| 10<sup>5</sup> - 10<sup>6</sup> | O( n ) |
| 10<sup>6</sup> - ∞ | O( log n ) |


## Data structures & common algorithms

### Array:
- Accessing an element by index: **O(1)**
- Searching for an element (unsorted): **O(n)**
- Searching for an element (sorted): **O(log n)** with binary search
- Inserting or deleting an element at the beginning: **O(n)**
- Inserting or deleting an element at the end: **O(1)**
- Inserting or deleting an element in the middle: **O(n)**
```cpp
int arr[5] = {0};
std::vector<int> arr(5, 0);
```


### String:
- Finding the length of a string: **O(1)**
- Appending a string at the end: **O(m)**, where **m** is the length of the string being appended
- Concatenating two strings: **O(n + m)**, where **n** and **m** are the lengths of the two strings being concatenated
- Substring extraction: **O(k)**, where **k** is the length of the extracted substring
- Searching for a substring: **O(n * m)**, where **n** is the length of the main string and **m** is the length of the substring being searched
- Replacing a substring: **O(n + m)**, where **n** is the length of the main string and **m** is the length of the substring being replaced
```cpp
std::string s = "Hello, friend.";
std::string s(5, '0');
```


### Linked List:
- Accessing an element by index: **O(n)**
- Searching for an element: **O(n)**
- Inserting or deleting an element at the beginning: **O(1)**
- Inserting or deleting an element at the end: **O(n)** (**O(1)** if maintaining a tail reference)
- Inserting or deleting an element in the middle: **O(n)** (**O(1)** if maintaining references to nodes)
```cpp
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::forward_list<int> singlyLinkedList (5, 0);
std::list<int> doublyLinkedList (5, 0);
```


### Stack & Queue:
- Push (inserting an element): **O(1)**
- Pop (removing the first element): **O(1)**
- Peek (viewing the first element): **O(1)**
```cpp
std::deque<int> deck (5, 0);

std::stack<int> lifo (deck);
std::queue<int> fifo (deck);
```


### Hash Table:
- Insertion: **O(1)** on average (**O(n)** in worst case if collisions occur)
- Deletion: **O(1)** on average (**O(n)** in worst case if collisions occur)
- Search: **O(1)** on average (**O(n)** in worst case if collisions occur)
```cpp
std::unordered_set<int> nums ({3,4,2,5,1});

std::unordered_map<char, int> ascii ({
    {'a', 97},
    {'b', 98}
});
```


### Binary Search Tree (BST):
- Insertion: **O(log n)** on average (**O(n)** in worst case if the tree is unbalanced)
- Deletion: **O(log n)** on average (**O(n)** in worst case if the tree is unbalanced)
- Search: **O(log n)** on average (**O(n)** in worst case if the tree is unbalanced)
```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```


### Heap:
- Insertion: **O(log n)**
- Deletion (extracting the minimum or maximum element): **O(log n)**
- Search: **O(n)** (heaps are not designed for efficient searching)
```cpp
int arr[]= {2,4,3,5,1};
std::priority_queue<int> nums (arr,arr+3);
```


### Graph Traversal (BFS and DFS)
- Both BFS and DFS: **O(V + E)**, where V is the number of vertices and E is the number of edges



### Sorting algorithms

![](https://leetcode.com/explore/interview/card/cheatsheets/720/resources/Figures/DSA/Chapter_11/sorting.png)
```cpp
int nums[] = {3,4,1,5,2};
std::sort(nums, nums+5);
```


## Flowchart

![](https://leetcode.com/explore/interview/card/cheatsheets/720/resources/Figures/DSA/Chapter_11/flowchart.png)

