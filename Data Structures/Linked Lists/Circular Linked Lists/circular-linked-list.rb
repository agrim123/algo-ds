# Circular Linked List

class Node
    attr_accessor :val, :next

    def initialize(val, next_node)
        @val = val
        @next = next_node
    end
end

class CircularLinkedList
    def initialize(val)
        @head = Node.new(val, nil)
    end

    # still to fix
    def push(new_data)
        ptr = Node.new(new_data, @head)
        temp = @head

        if @head != nil
            while(temp.next != @head)
                temp = temp.next
            end
            temp.next = ptr
        else
            ptr.next = ptr
        end
        @head = ptr
    end

    def print_list
        current = @head
        if @head != nil
            while(1)
                puts "#{current.val}"
                current = current.next
                if current == @head
                    break
                end
            end
        end
    end
end

l = CircularLinkedList.new(3)
l.push(4)
l.push(5)
l.push(6)
l.push(7)
l.print_list()
