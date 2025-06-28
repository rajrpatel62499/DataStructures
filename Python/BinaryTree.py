class TreeNode: 
    def __init__(self, value): 
        self.left = None 
        self.right = None 
        self.value = value

# Make a tree 
root = TreeNode("A")
bNode = TreeNode("B")
cNode = TreeNode("C")
dNode = TreeNode("D")
eNode = TreeNode("E")
fNode = TreeNode("F")
gNode = TreeNode("G")

root.left = bNode 
root.right = cNode 

root.left.left = dNode 
root.left.right = eNode 

root.right.left = fNode 
root.right.right = gNode 


# Traversal 
def in_order_traversal(node): 
    # traverse until node is not none 
    if node is None: 
        return None
    in_order_traversal(node.left)
    print(node.value, end=", ")
    in_order_traversal(node.right)


def pre_order_traversal(node): 
    # traverse until node is not none 
    if node is None: 
        return None
    print(node.value, end=", ")
    in_order_traversal(node.left)
    in_order_traversal(node.right)


def post_order_traversal(node): 
    # traverse until node is not none 
    if node is None: 
        return None
    in_order_traversal(node.left)
    in_order_traversal(node.right)
    print(node.value, end=", ")

print("In Order traversal: ", end="")
in_order_traversal(root)

print("\n\nPre Order Traversal: ", end="")
pre_order_traversal(root)

print("\n\nPost Order Traversal: ", end="")
post_order_traversal(root)
