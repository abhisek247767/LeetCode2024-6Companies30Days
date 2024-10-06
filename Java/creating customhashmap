import java.util.LinkedList;

class CustomHashMap<K, V> {
    // Define the node class to hold key-value pairs
    private class Node {
        K key;
        V value;

        Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    private LinkedList<Node>[] buckets;
    private int capacity = 10; // Initial size of the array (bucket array)
    
    @SuppressWarnings("unchecked")
    public CustomHashMap() {
        // Initialize the array with empty linked lists
        buckets = new LinkedList[capacity];
        for (int i = 0; i < capacity; i++) {
            buckets[i] = new LinkedList<>();
        }
    }

    // Hash function to map a key to an index
    private int getBucketIndex(K key) {
        return Math.abs(key.hashCode()) % capacity;
    }

    // Insert a key-value pair into the HashMap
    public void put(K key, V value) {
        int index = getBucketIndex(key);
        LinkedList<Node> bucket = buckets[index];
        
        // Check if the key already exists and update the value
        for (Node node : bucket) {
            if (node.key.equals(key)) {
                node.value = value; // Update existing value
                return;
            }
        }

        // If the key does not exist, add a new node to the linked list
        bucket.add(new Node(key, value));
    }

    // Retrieve a value by key
    public V get(K key) {
        int index = getBucketIndex(key);
        LinkedList<Node> bucket = buckets[index];
        
        // Search the linked list for the key
        for (Node node : bucket) {
            if (node.key.equals(key)) {
                return node.value;
            }
        }
        
        // Return null if the key is not found
        return null;
    }

    // Remove a key-value pair by key
    public void remove(K key) {
        int index = getBucketIndex(key);
        LinkedList<Node> bucket = buckets[index];

        // Iterate over the linked list to find and remove the key
        for (Node node : bucket) {
            if (node.key.equals(key)) {
                bucket.remove(node);
                return;
            }
        }
    }

    // Check if the HashMap contains a key
    public boolean containsKey(K key) {
        int index = getBucketIndex(key);
        LinkedList<Node> bucket = buckets[index];
        
        // Search the linked list for the key
        for (Node node : bucket) {
            if (node.key.equals(key)) {
                return true;
            }
        }
        
        return false;
    }
    
    // Main method to test the CustomHashMap
    public static void main(String[] args) {
        CustomHashMap<String, Integer> map = new CustomHashMap<>();
        map.put("one", 1);
        map.put("two", 2);
        map.put("three", 3);

        System.out.println("Value for key 'one': " + map.get("one")); // Output: 1
        System.out.println("Value for key 'two': " + map.get("two")); // Output: 2
        System.out.println("Value for key 'three': " + map.get("three")); // Output: 3

        map.remove("two");
        System.out.println("Contains key 'two'? " + map.containsKey("two")); // Output: false
        System.out.println("Value for key 'two': " + map.get("two")); // Output: null
    }
}
