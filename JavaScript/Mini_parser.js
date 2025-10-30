// 385. Mini Parser
// Problem Statement: Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.
// Each element is either an integer or a list whose elements may also be integers or other lists.

// Time Complexity: O(n)

// Space Complexity: O(n)


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation.
 * function NestedInteger(value) {
 *     ...
 * };
 * 
 * @return {NestedInteger}
 */
var deserialize = function(s) {
    if (s === '' || s === '[]') {
        return new NestedInteger();
    }
    if (s[0] !== '[') {
        return new NestedInteger(+s);
    }

    const ans = new NestedInteger();
    let depth = 0;

    for (let i = 1, j = 1; i < s.length; ++i) {
        if (depth === 0 && (s[i] === ',' || i === s.length - 1)) {
            ans.add(deserialize(s.slice(j, i)));
            j = i + 1;
        } else if (s[i] === '[') {
            ++depth;
        } else if (s[i] === ']') {
            --depth;
        }
    }

    return ans;
};


// Input:

// s = "[123,[456,[789]]]";


// Output (conceptual representation):
// A NestedInteger object structured as:

// [
//   123,
//   [
//     456,
//     [789]
//   ]
// ]


// Explanation:
// The function recursively deserializes the string:
// If the string starts with '[', it represents a nested list.
// Numbers are converted to integer elements.
// Sub-lists (enclosed in brackets) are recursively parsed and added using add().