#include <bits/stdc++.h>
using namespace std;

// Function to calculate the hash value of a string containing digits 0-9
int calculateHash(const string& str, int len, int q) {
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        hash = (hash * 10 + (str[i] - '0')) % q; // Using 10 as the base for digits 0-9
    }
    return hash;
}

// Function to update the hash value for rolling hash
int updateHash(int oldHash, char oldChar, char newChar, int len, int q) {
    int newHash = (oldHash - (oldChar - '0') * static_cast<int>(pow(10, len - 1))) % q;
    newHash = (newHash * 10 + (newChar - '0')) % q;
    return newHash >= 0 ? newHash : newHash + q; // Ensure new hash is positive
}

// Function to perform Rabin-Karp pattern matching for strings containing digits 0-9
void rabinKarpMatcher(const string& T, const string& P, int q) {
    int n = T.length();
    int m = P.length();
    int pHash = calculateHash(P, m, q); // Hash value of pattern
    int tHash = calculateHash(T, m, q); // Hash value of initial substring of text

    int spuriousHits = 0; // Counter for spurious hits

    // Iterate over the text
    for (int i = 0; i <= n - m; ++i) {
        if (pHash == tHash) { // If hashes match, check character by character
            int j;
            for (j = 0; j < m; ++j) {
                if (T[i + j] != P[j])
                    break;
            }
            if (j == m) { // Pattern matches at index i
                cout << "Pattern found at index " << i << endl;
            } else {
                ++spuriousHits; // Spurious hit encountered
            }
        }
        // Update hash for next substring
        if (i < n - m) {
            tHash = updateHash(tHash, T[i], T[i + m], m, q);
        }
    }
    cout << "Total spurious hits: " << spuriousHits << endl;
}

int main() {
    string T, P;
    int q;

    cout << "Enter the modulus (q): ";
    cin >> q;
    cout << "Enter the text string (T): ";
    cin >> T;
    cout << "Enter the pattern (P): ";
    cin >> P;

    rabinKarpMatcher(T, P, q);

    return 0;
}
