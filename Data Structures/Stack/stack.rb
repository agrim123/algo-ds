=begin
    Stacks
    - Array Implementation
    - LIFO or FILO
    - Basic operations on Stacks:
        1. Push
        2. Pop
        3. Peek
=end

class Stack
  def initialize(size)
    @size = size
    @store = Array.new(@size)
    @top = -1
  end
  
  def pop
    if empty?
      nil
    else
      popped = @store[@top]
      @store[@top] = nil
      @top = @top.pred
      popped
    end
  end
  
  def push(element)
    if full? or element.nil?
      nil
    else
      @top = @top.succ
      @store[@top] = element
      self
    end
  end
  
  def size
    @size
  end
  
  def peek
    @store[@top]
  end
  
  private
  
  def full?
    @top == (@size - 1)
  end
  
  def empty?
    @top == -1
  end
end

s = Stack.new(5)
s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)
s.pop()
puts s.peek