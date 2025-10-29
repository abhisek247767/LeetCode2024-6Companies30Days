// 2627. Debounce

// Problem Statement:Given a function fn and a time in milliseconds t, return a debounced version of that function.
// A debounced function is a function whose execution is delayed by t milliseconds and whose execution is cancelled if it is called again within that window of time. The debounced function should also receive the passed parameters.
// For example, let's say t = 50ms, and the function was called at 30ms, 60ms, and 100ms.
// The first 2 function calls would be cancelled, and the 3rd function call would be executed at 150ms.
// If instead t = 35ms, The 1st call would be cancelled, the 2nd would be executed at 95ms, and the 3rd would be executed at 135ms.

// Time Complexity: O(1) per call
// Space Complexity: O(1)

function debounce(fn, t) {
    let timeout;

    return function (...args) {
        if (timeout !== undefined) {
            clearTimeout(timeout);
        }
        timeout = setTimeout(() => {
            fn.apply(this, args);
        }, t);
    };
}

// Input (Example Usage):

// const log = debounce(console.log, 100);
// log("Hello");
// log("Hello");
// log("Hello");


// Output (Console):

// Hello


// Explanation:
// Each time log is called, the timer resets.
// Only the last call (after no new calls for 100 ms) executes console.log("Hello").
