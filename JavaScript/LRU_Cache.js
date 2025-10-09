// Problem Statement: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache. Implement the LRUCache class which supports `get(key)` and `put(key, value)` operations.
// Time Complexity: O(1) for both get and put operations. This is achieved by using a hash map for fast lookups and a doubly linked list for fast additions/removals.
// Space Complexity: O(capacity), as we store up to the specified capacity of items in both the map and the list.


// Node class for the doubly linked list.
class Node {
    constructor(key, value) {
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    /**
     * @param {number} capacity
     */
    constructor(capacity) {
        this.capacity = capacity;
        this.map = new Map(); // For O(1) lookup of nodes.
        
        // Dummy head and tail nodes to handle edge cases easily.
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }
    
    // Helper to remove a node from the list.
    _remove(node) {
        const prevNode = node.prev;
        const nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }

    // Helper to add a node to the front of the list (most recently used).
    _addToFront(node) {
        const nextNode = this.head.next;
        this.head.next = node;
        node.prev = this.head;
        node.next = nextNode;
        nextNode.prev = node;
    }

    /** * @param {number} key
     * @return {number}
     */
    get(key) {
        if (!this.map.has(key)) {
            return -1;
        }

        const node = this.map.get(key);
        // Move the accessed node to the front to mark it as most recently used.
        this._remove(node);
        this._addToFront(node);
        
        return node.value;
    }

    /** * @param {number} key 
     * @param {number} value
     * @return {void}
     */
    put(key, value) {
        // If key already exists, update its value and move it to the front.
        if (this.map.has(key)) {
            const node = this.map.get(key);
            node.value = value;
            this._remove(node);
            this._addToFront(node);
            return;
        }

        // If the cache is full, evict the least recently used item.
        if (this.map.size === this.capacity) {
            const lruNode = this.tail.prev;
            this._remove(lruNode);
            this.map.delete(lruNode.key);
        }

        // Add the new item.
        const newNode = new Node(key, value);
        this.map.set(key, newNode);
        this._addToFront(newNode);
    }
}


// --- Example ---
console.log("--- LRU Cache Example ---");
const lruCache = new LRUCache(2); // Capacity of 2

lruCache.put(1, 1); // cache is {1=1}
console.log("put(1, 1)");

lruCache.put(2, 2); // cache is {1=1, 2=2}
console.log("put(2, 2)");

let val = lruCache.get(1); // returns 1, cache is {2=2, 1=1} (1 is now most recent)
console.log(`get(1): ${val}`); // output: 1

lruCache.put(3, 3); // LRU key 2 was evicted, cache is {1=1, 3=3}
console.log("put(3, 3)");

val = lruCache.get(2); // returns -1 (not found)
console.log(`get(2): ${val}`); // output: -1

lruCache.put(4, 4); // LRU key 1 was evicted, cache is {3=3, 4=4}
console.log("put(4, 4)");

val = lruCache.get(1); // returns -1 (not found)
console.log(`get(1): ${val}`); // output: -1

val = lruCache.get(3); // returns 3
console.log(`get(3): ${val}`); // output: 3

val = lruCache.get(4); // returns 4
console.log(`get(4): ${val}`); // output: 4
