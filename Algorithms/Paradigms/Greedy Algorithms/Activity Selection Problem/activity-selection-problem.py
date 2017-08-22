"""
    Activity Selection Problem
"""

# n --> Total number of activities
# s[]--> An array that contains start time of all activities
# f[] --> An array that conatins finish time of all activities


def print_max_activities(s , f ):
    print("The following activities are selected")

    # The first activity is always selected
    i = 0
    print(i)

    for j in range(len(f)):

        # If this activity has start time greater than
        # or equal to the finish time of previously
        # selected activity, then select it
        if s[j] >= f[i]:
            print(j)
            i = j


s = [1, 3, 0, 5, 8, 5]
f = [2, 4, 6, 7, 9, 9]
print_max_activities(s, f)
