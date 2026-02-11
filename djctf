from functools import lru_cache

class Node:
    def __init__(self, value, children=None):
        self.value = value
        self.children = children or []

    def evaluate(self):
        return self.value + sum(child.evaluate() for child in self.children)

@lru_cache(maxsize=None)
def pseudo_hash(x):
    if x <= 1:
        return 1
    return (pseudo_hash(x - 1) + pseudo_hash(x - 2)) % 256

def build_tree():
    values = [100,106,99,116,102,123,102,97,107,101,95,102,108,97,103,125]
    nodes = [Node(v) for v in values]
    root = Node(0, nodes)
    return root

def extract_flag(root):
    flat = root.children
    # делаем вид, что фильтруем “шум”
    filtered = [n for i, n in enumerate(flat) if pseudo_hash(i) >= 0]
    # бесполезная трансформация
    return ''.join(chr(n.value) for n in filtered[::2])

def main():
    tree = build_tree()
    _ = tree.evaluate()
    print(extract_flag(tree))

if __name__ == "__main__":
    main()
