// 127. Word Ladder

// Problem Statement : A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// Time Complexity: O(N × L²)
// N = number of words in wordList
// L = length of each word
// (Because we create patterns for each word and traverse them in BFS.)

// Space Complexity: O(N × L)
// (for the graph g, word derivatives, and visited set)

function ladderLength(beginWord, endWord, wordList) {
    if (!wordList.includes(endWord)) return 0;

    const replace = (s, i, ch) => s.slice(0, i) + ch + s.slice(i + 1);
    const { length } = beginWord;
    const words = {};
    const g = {};

    for (const w of [beginWord, ...wordList]) {
        const derivatives = [];

        for (let i = 0; i < length; i++) {
            const nextW = replace(w, i, '*');
            derivatives.push(nextW);

            g[nextW] ??= [];
            g[nextW].push(w);
        }

        words[w] = derivatives;
    }

    let ans = 0;
    let q = words[beginWord];
    const vis = new Set([beginWord]);

    while (q.length) {
        const nextQ = [];
        ans++;

        for (const variant of q) {
            for (const w of g[variant]) {
                if (w === endWord) return ans + 1;

                if (vis.has(w)) continue;
                vis.add(w);

                nextQ.push(...words[w]);
            }
        }

        q = nextQ;
    }

    return 0;
}


// Input:

// beginWord = "hit";
// endWord = "cog";
// wordList = ["hot", "dot", "dog", "lot", "log", "cog"];


// Output:
// 5

// Explanation:
// The shortest transformation sequence is:
// "hit" → "hot" → "dot" → "dog" → "cog"
// Each step changes exactly one letter and results in a valid word from the list.
// Length of the sequence = 5.