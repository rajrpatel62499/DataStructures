class TreeNode: 
    def __init__(self, value): 
        self.left = None 
        self.right = None 
        self.value = value

    def __str__(self): 
        return f"TreeNode({str(self.value)})"

    def get_dict(self):
        return { "data": self.value}

# Binary search Tree Rules 
# - Given node "X" all left nodes of "X" should be lesser than X value 
# - Given node "X" all right nodes of "X" should be greater than X value 
# - Given node "X" all decendents node of left and right should also be Binary Search Tree 


# Make a tree 
root = TreeNode(13)
node7 = TreeNode(7)
node15 = TreeNode(15)
node3 = TreeNode(3)
node8 = TreeNode(8)
node14 = TreeNode(14)
node19 = TreeNode(19)
node18 = TreeNode(18)

root.left = node7
root.right = node15

node7.left = node3
node7.right = node8

node15.left = node14
node15.right = node19

node19.left = node18


class BST: 

    def __init__(self): 
        pass 

    def search(self, node, target): 
        # traverse until the value is found 
        # DFS - InOrderTraversal 
        if node is None: 
            return None
        elif node.value == target: 
            return node
        elif target < node.value: 
            return self.search(node.left, target)
        elif target > node.value: 
            return self.search(node.right, target)

    def min(self, node): 
        current = node 
        while current.left is not None: 
            current = current.left 
        return current.value 
    def max(self, node): 
        current = node 
        while current.right is not None: 
            current = current.right 
        return current.value 
        
    def delete(self, node, data):
        if not node:
            return None
    
        if data < node.value:
            node.left = self.delete(node.left, data)
        elif data > node.value:
            node.right = self.delete(node.right, data)
        else:
            # Node with only one child or no child
            if not node.left:
              temp = node.right
              node = None
              return temp
            elif not node.right:
              temp = node.left
              node = None
              return temp
    
            # Node with two children, get the in-order successor
            # first find the min value on right side - cause next successor will be greather than current value that's why need to look on right side             
            node.value = self.min(node.right)
            # after finding and setting value, delete that node recursively - and it will be leaf node or one node (if right node exist) deletion 
            node.right = self.delete(node.right, node.value)

        # must return it - whether it's modified or not modified by the sub problems 
        return node
    # Traversal 
    def in_order_traversal(self, node): 
        # traverse until node is not none 
        if node is None: 
            return None
        self.in_order_traversal(node.left)
        print(node.value, end=", ")
        self.in_order_traversal(node.right)
    
    
    def pre_order_traversal(self, node): 
        # traverse until node is not none 
        if node is None: 
            return None
        print(node.value, end=", ")
        self.pre_order_traversal(node.left)
        self.pre_order_traversal(node.right)
    
    
    def post_order_traversal(self,node): 
        # traverse until node is not none 
        if node is None: 
            return None
        self.post_order_traversal(node.left)
        self.post_order_traversal(node.right)
        print(node.value, end=", ")

bst = BST() 

result = bst.search(root, 8)
print(result)
if result: 
    print(result.get_dict())
print(bst.search(root,8))
bst.delete(root, 8)
print(bst.search(root,8))
# print("In Order traversal: ", end="")
# bst.in_order_traversal(root)


# print("\n\nPre Order Traversal: ", end="")
# bst.pre_order_traversal(root)

# print("\n\nPost Order Traversal: ", end="")
# bst.post_order_traversal(root)
