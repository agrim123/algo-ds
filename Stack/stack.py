from sys import maxsize


def create_stack():
    stack = []
    return stack


def is_stack_empty(stack):
    return len(stack) == 0


def push(stack, e):
    stack.append(e)


def pop(stack):
    if is_stack_empty(stack):
        return str(-maxsize -1)
    return stack.pop()

stack = create_stack()
push(stack, 1)
push(stack, 2)
push(stack, 3)
print(pop(stack))

