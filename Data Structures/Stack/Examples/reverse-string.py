"""
    Reverse a string using stack
"""


def createStack():
    stack = []
    return stack


def size(stack):
    return len(stack)


def isEmpty(stack):
    if size(stack) == 0:
        return True


def push(stack, item):
    stack.append(item)


def pop(stack):
    if isEmpty(stack):
        return
    return stack.pop()


# A stack based function to reverse a string
def reverseString(string):
    n = len(string)

    # Create a empty stack
    stack = createStack()

    # Push all characters of string to stack
    for i in range(0, n, 1):
        push(stack, string[i])

    # Making the string empty since all characters are saved in stack
    string = ""

    # Pop all characters of string and put them back to string
    for i in range(0, n, 1):
        string += pop(stack)

    return string


string = "SOME RANDOM STRING"
string = reverseString(string)
print("Reversed string is " + string)
