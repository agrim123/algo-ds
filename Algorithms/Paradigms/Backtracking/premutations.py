# Permutation


def toString(List):
    return ''.join(List)


def permute(a, l, r):
    if l == r:
        print(toString(a))
    else:
        for i in range(l, r+1):
            a[l], a[i] = a[i], a[l]
            permute(a, l+1, r)
            a[l], a[i] = a[i], a[l]  # backtrack

string = 'ABC'
permute(list(string), 0, len(string) - 1)
