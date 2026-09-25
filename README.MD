An LRU (Least Recently Used) Cache stores a limited number of items and removes the item that has not been used for the longest time when the cache becomes full.

 For example, if the cache capacity is 2:

 `put("A", 10)` → stores A\
 `put("B", 20)` → stores B\
 `get("A")` → returns 10 and makes A recently used\
 `put("C", 30)` → cache is full, so B (the least recently used item) is removed\
 `get("B")` → returns -1 because B was removed\
 `get("C")` → returns 30\
 `get("A")` → returns 10

 The main idea is: **recently used items stay in the cache, while the least recently used item is removed when the cache is full.**