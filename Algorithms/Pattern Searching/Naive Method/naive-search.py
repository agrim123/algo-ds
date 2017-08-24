"""
    Naive Pattern Searching
"""


def search(pattern, txt):
    M = len(pattern)
    N = len(txt)

    # A loop to slide pattern[] one by one
    for i in range(N-M+1):
        for j in range(M):
            if txt[i+j] != pattern[j]:
                break
        if j == M-1:  # if pattern[0...M-1] = txt[i, i+1, ...i+M-1]
            print("Pattern found at index " + str(i))


txt = "AABAACAADAABAAABAA"
pattern = "AABA"
search(pattern, txt)
