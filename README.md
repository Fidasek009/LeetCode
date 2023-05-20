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

### Arrays:
- Accessing an element by index: **O(1)**
- Searching for an element (unsorted): **O(n)**
- Searching for an element (sorted): **O(log n)** with binary search
- Inserting or deleting an element at the beginning: **O(n)**
- Inserting or deleting an element at the end: **O(1)**
- Inserting or deleting an element in the middle: **O(n)**
```
int arr[5] = {0};
std::vector<int> arr(5, 0);
```


### Linked Lists:
- Accessing an element by index: **O(n)**
- Searching for an element: **O(n)**
- Inserting or deleting an element at the beginning: **O(1)**
- Inserting or deleting an element at the end: **O(n)** (**O(1)** if maintaining a tail reference)
- Inserting or deleting an element in the middle: **O(n)** (**O(1)** if maintaining references to nodes)
```
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::forward_list<int> second (5, 0);
```


### Stacks & Queues:
- Push (inserting an element): **O(1)**
- Pop (removing the first element): **O(1)**
- Peek (viewing the first element): **O(1)**
```
std::deque<int> deck (5, 0);

std::stack<int> lifo (deck);
std::queue<int> fifo (deck);
```


### Hash Tables:
- Insertion: **O(1)** on average (**O(n)** in worst case if collisions occur)
- Deletion: **O(1)** on average (**O(n)** in worst case if collisions occur)
- Search: **O(1)** on average (**O(n)** in worst case if collisions occur)
```
std::unordered_set<int> nums ({3,4,2,5,1});

std::unordered_map<char, int> ascii ({
    {'a', 97},
    {'b', 98}
});
```


### Binary Search Trees (BST):
- Insertion: **O(log n)** on average (**O(n)** in worst case if the tree is unbalanced)
- Deletion: **O(log n)** on average (**O(n)** in worst case if the tree is unbalanced)
- Search: **O(log n)** on average (**O(n)** in worst case if the tree is unbalanced)
```
struct node {
  int key;
  node *left, *right;
};
```


### Heaps:
- Insertion: **O(log n)**
- Deletion (extracting the minimum or maximum element): **O(log n)**
- Search: **O(n)** (heaps are not designed for efficient searching)
```
int arr[]= {2,4,3,5,1};
std::priority_queue<int> nums (arr,arr+3);
```


### Graph Traversal (BFS and DFS)
- Both BFS and DFS: **O(V + E)**, where V is the number of vertices and E is the number of edges



### Sorting algorithms

![](https://leetcode.com/explore/interview/card/cheatsheets/720/resources/Figures/DSA/Chapter_11/sorting.png)
```
int nums[] = {3,4,1,5,2};
std::sort(nums, nums+5);
```


## Flowchart

![](https://leetcode.com/explore/interview/card/cheatsheets/720/resources/Figures/DSA/Chapter_11/flowchart.png)

