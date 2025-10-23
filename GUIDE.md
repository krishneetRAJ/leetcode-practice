# LeetCode Problem Solutions

## Quick Reference Guide

### How to Navigate This Repository

#### By Difficulty
- **Easy/**: Start here for foundational problems
- **Medium/**: Intermediate challenges
- **Hard/**: Advanced algorithmic problems

#### By Language
Each problem has two implementations:
- `.py` files: Python solutions
- `.cpp` files: C++ solutions

### Running Solutions

#### Python
```bash
cd Easy
python3 two_sum.py
```

#### C++
```bash
cd Easy
g++ -std=c++17 two_sum.cpp -o solution
./solution
```

### Problem List

#### Easy
1. **Two Sum** (#1)
   - Files: `two_sum.py`, `two_sum.cpp`
   - Technique: Hash Map
   - Complexity: O(n) time, O(n) space

2. **Valid Palindrome** (#125)
   - Files: `valid_palindrome.py`, `valid_palindrome.cpp`
   - Technique: Two Pointers
   - Complexity: O(n) time, O(1) space

#### Medium
1. **3Sum** (#15)
   - Files: `three_sum.py`, `three_sum.cpp`
   - Technique: Two Pointers with Sorting
   - Complexity: O(n²) time, O(1) space

2. **Number of Islands** (#200)
   - Files: `number_of_islands.py`, `number_of_islands.cpp`
   - Technique: DFS/Graph Traversal
   - Complexity: O(m*n) time, O(m*n) space

#### Hard
1. **Trapping Rain Water** (#42)
   - Files: `trapping_rain_water.py`, `trapping_rain_water.cpp`
   - Technique: Two Pointers
   - Complexity: O(n) time, O(1) space

2. **First Missing Positive** (#41)
   - Files: `first_missing_positive.py`, `first_missing_positive.cpp`
   - Technique: Index as Hash Key
   - Complexity: O(n) time, O(1) space

### Learning Path

**Week 1-2: Easy Problems**
- Focus on basic data structures (arrays, hash maps)
- Learn fundamental algorithms (two pointers, sliding window)
- Build consistency with daily practice

**Week 3-4: Medium Problems**
- Tackle more complex scenarios
- Learn advanced techniques (DFS, BFS, dynamic programming)
- Practice optimizing solutions

**Week 5+: Hard Problems**
- Master algorithmic thinking
- Understand edge cases deeply
- Focus on optimization and efficiency

### Common Patterns

#### Hash Map Pattern
- Used in: Two Sum
- When to use: O(1) lookup needed
- Space trade-off: O(n)

#### Two Pointers Pattern
- Used in: Valid Palindrome, 3Sum, Trapping Rain Water
- When to use: Array traversal from both ends
- Space efficiency: O(1)

#### DFS/BFS Pattern
- Used in: Number of Islands
- When to use: Graph/matrix traversal
- Applications: Connected components, shortest path

#### Index Manipulation Pattern
- Used in: First Missing Positive
- When to use: Array as data structure constraint
- Advanced technique: In-place modification

### Tips for Interviews

1. **Clarify requirements** before coding
2. **Discuss approach** with interviewer
3. **Start with brute force** then optimize
4. **Write clean code** with good variable names
5. **Test with examples** including edge cases
6. **Analyze complexity** time and space

### Next Steps

1. Add more problems from each category
2. Include problem variations
3. Add different solution approaches
4. Create topic-based collections (trees, graphs, etc.)
5. Add difficulty level README files with tips
