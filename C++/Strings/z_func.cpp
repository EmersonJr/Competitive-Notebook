vector<int> Z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            x = i; y = i + z[i]; z[i]++;
        }
    }
    return z;
}


/*
The Z-function for this string is an array of length $n$ where the $i$-th element is equal to the greatest number of characters starting from the position $i$ that coincide with the first characters of

$s$.

In other words,
$z[i]$ is the length of the longest string that is, at the same time, a prefif of $s$ and a prefix of the suffix of $s$ starting at $i$.
Complexidade O(N)
*/