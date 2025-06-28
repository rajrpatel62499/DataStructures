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

# print("In Order traversal: ", end="")
# bst.in_order_traversal(root)


# print("\n\nPre Order Traversal: ", end="")
# bst.pre_order_traversal(root)

# print("\n\nPost Order Traversal: ", end="")
# bst.post_order_traversal(root)
