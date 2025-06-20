class Stack: 
    size = 0
    arr = []

    def __init__(self, size): 
        self.size = size 
        self.arr = [0] * self.size 

    def __str__(self): 
        return f"{self.arr}"

    
s = Stack(5) 


print(s)
