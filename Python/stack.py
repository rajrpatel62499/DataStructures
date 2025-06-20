
class Stack: 
    size = 0
    arr = []
    index = -1

    def __init__(self, size): 
        self.size = size 
        self.arr = [0] * self.size 

    def peek(self): 
        if not self.isEmpty(): 
            return self.arr[self.index]
        
    def isEmpty(self): 
        return True if self.index == -1 else False 

    def isFull(self): 
        return True if self.index == (self.size - 1) else False
        
    def push(self, item): 
        if not self.isFull(): 
            self.index += 1 
            self.arr[self.index] = item
        else: 
            print("Stack is full")

    
    def pop(self): 
        if not self.isEmpty(): 
            self.arr[self.index] = 0 
            self.index -= 1 
        else: 
            print("Stack is Empty")
        
    def __str__(self): 
        return f"{self.arr}"
    
s = Stack(5) 

s.push(3)
s.push(5)
s.push(53)
s.push(533)
s.push(534)
s.pop()
print(s)
s.push(5344)
print(s)
print(s.isFull())
print(s.isEmpty())
print(s.peek())
