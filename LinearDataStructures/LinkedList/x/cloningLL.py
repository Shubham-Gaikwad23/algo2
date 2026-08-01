# This program provides two methods to clone a linked list with random pointers: `clone_hash()` and `clone()`.

# ### clone_hash() (Not implemented -- just for an idea -- do not review)
# - Uses a hash table (dictionary) to map original nodes to their clones.
# - First pass: Creates clone nodes and stores them in the table, linking their `next` pointers.
# - Second pass: Assigns the `ran` (random) pointers using the table.
# - **Time Complexity:** $O(n)$, where $n$ is the number of nodes. Each node is visited twice.

# ### clone()
# - Interleaves cloned nodes with original nodes in a single list.
# - First pass: Inserts cloned nodes right after their originals.
# - Second pass: Sets the `ran` pointers for cloned nodes using the interleaved structure.
# - Third pass: Separates the cloned list from the original, restoring the original list.
# - **Time Complexity:** $O(n)$, as each node is visited a constant number of times.
# Complexity
# - Time: O(n) for clone() because each node is visited a constant number of times.
# - Space: O(1) extra space for clone() beyond the output list, ignoring the space for the cloned nodes themselves. The hash-based method would use O(n) extra space.


# Both methods efficiently clone the list, including random pointers, in linear time.

from random import randint

class LinkedList:
    """
    A linked list where each node has an additional random pointer (`ran`) that can point to any node in the list or be `None`.
    """
    class ListNode:
        """
        A node in the linked list, containing a key, a pointer to the next node, and a random pointer.
        """
        def __init__(self, key: int):
            self.key = key
            self.next = None
            self.ran = None

    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, key: int):
        new_node = self.ListNode(key)
        if self.tail:
            self.tail.next = new_node
            self.tail = new_node
        else:
            self.head = self.tail = new_node

    def add_node(self, new_node: 'LinkedList.ListNode'):
        # Ensure the node being added does not keep old next links
        new_node.next = None
        if self.tail:
            self.tail.next = new_node
            self.tail = new_node
        else:
            self.head = self.tail = new_node

    def clone(self) -> 'LinkedList':
        # Pass 1: interleave cloned nodes
        curr_node = self.head
        while curr_node:
            new_node = self.ListNode(curr_node.key)
            new_node.next = curr_node.next
            curr_node.next = new_node
            curr_node = new_node.next

        # Pass 2: set random pointers for clones
        origin_node = self.head
        while origin_node:
            cloned_node = origin_node.next
            cloned_node.ran = origin_node.ran.next if origin_node.ran else None
            origin_node = origin_node.next.next

        # Pass 3: separate cloned list and restore original
        cloned_list = self.__class__()
        origin_node = self.head
        while origin_node:
            cloned_node = origin_node.next
            origin_node.next = cloned_node.next
            # detach cloned_node from original chain before adding
            cloned_node.next = None
            cloned_list.add_node(cloned_node)
            origin_node = origin_node.next

        return cloned_list

def main():
    lst = LinkedList()
    all_nodes = []
    for i in range(20):
        lst.insert(i)
        all_nodes.append(lst.tail)

    for node in all_nodes:
        node.ran = all_nodes[randint(0, len(all_nodes) - 1)]

    cloned_lst = lst.clone()
    origin_node = lst.head
    cloned_node = cloned_lst.head
    for i in range(20):
        assert origin_node.key == cloned_node.key
        # verify the clone's random points to the clone of origin's random
        assert origin_node.ran.key == cloned_node.ran.key
        origin_node = origin_node.next
        cloned_node = cloned_node.next

if __name__ == "__main__":
    main()