"""
    Interpolation Search
"""


def InterpolationSearch(l, search_item):
    high = len(l) - 1
    low = 0

    while low <= high and search_item >= l[low] and search_item <= l[high]:
        r = high - low
        run = l[high] - l[low]
        x = search_item - l[low]
        pos = low + int(r / run) * x

        if l[pos] == search_item:
            return pos
        elif search_item < l[pos]:
            high = pos - 1
        else:
            low = pos + 1

    return -1

print(InterpolationSearch([1, 3, 12, 4, 5, 6, 7, 8, 9, 10], 10))
