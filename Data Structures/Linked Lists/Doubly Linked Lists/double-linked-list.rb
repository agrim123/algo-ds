class Node
    attr_accessor :val, :prev, :next

    def initialize(val, prev_node, next_node)
        @val = val
        @prev = prev_node
        @next = next_node
    end
end

class DoubleLinkedList
    def initialize(val)
        @head = Node.new(val,nil,nil)
    end

    def push(val)
        new_node = Node.new(val, nil, @head)
        if @head != nil
            @head.prev = new_node
        end
        @head = new_node
    end

    def insert_node_at_end(val)
        current_node = @head

        while current_node.next != nil
          current_node = current_node.next
        end

        new_node = Node.new(val, nil,nil)

        current_node.next = new_node
    end

    def print_list
        current = @head
        while current != nil
            puts "#{current.val}"
            current = current.next
        end
    end
end

l = DoubleLinkedList.new(3)
l.push(2)
l.insert_node_at_end(4)
l.insert_node_at_end(5)
l.insert_node_at_end(6)
l.print_list()
