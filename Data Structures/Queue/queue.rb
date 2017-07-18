=begin
    Queue
       - Array Implementation
       - First In First Out (FIFO)
       - Basic operations on Queues:
            1. Enqueue -> add item to rear
            2. Dequeue -> remove item from front
            3. Front
            4. Rear
=end

class Queue
  def initialize(size)
    @size = size
    @store = Array.new(@size)
    @head, @tail = -1, 0
  end

  def dequeue
    if empty?
      nil
    else
      @tail = @tail.succ

      dequeued = @store[@head]
      @store.unshift(nil)
      @store.pop
      dequeued
    end
  end

  def enqueue(element)
    if full? or element.nil?
      nil
    else
      @tail = @tail.pred
      @store[@tail] = element
      self
    end
  end

  def front
    if empty?
      nil
    end
    @store[@head]
  end

  def rear
    if empty?
      nil
    end
    @store[@tail]
  end

  def size
    @size
  end

  private

  def empty?
    @head == -1 and @tail == 0
  end

  def full?
    @tail.abs == (@size)
  end
end

q = Queue.new(5)
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)
q.dequeue()
puts q.front
puts q.rear
