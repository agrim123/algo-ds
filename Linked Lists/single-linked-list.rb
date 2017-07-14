class Node
    attr_accessor :val, :next

    def initialize(val, next_node)
        @val = val
        @next = next_node
    end
end

class SingleLinkedList
    def initialize(val)
        @head = Node.new(val,nil)
    end

    def add(val)
        current = @head
        while current.next != nil
            current = current.next
        end
        current.next = Node.new(val,nil)
    end

    def return_list
        el = []
        current = @head
        while current.next != nil
            el << current
            current = current.next
        end
        el << current
    end

    def print_list
        current = @head
        while current != nil
            puts "#{current.val}"
            current = current.next
        end
    end
end

l = SingleLinkedList.new(3)
l.add(4)
l.add(5)
l.print_list()
