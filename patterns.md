# Most common patterns in coding interviews


## Clone a linked list with random pointer
Leetcode: https://leetcode.com/problems/copy-list-with-random-pointer/

The list can be cloned in-place by interleaving the cloned nodes with the original nodes. This way, we can easily set the random pointers of the cloned nodes without using extra space for a hash map. After setting the random pointers, we can separate the cloned list from the original list.
- Step 1: Interleave cloned nodes with original nodes. [o-o-o-o-...] -> [o-c-o-c-o-c-...]
- Step 2: Set random pointers for the cloned nodes. For each original node, if it has a random pointer, set the random pointer of the cloned node (which is the next node) to point to the next node of the original node's random pointer.
- Step 3: Separate the cloned list from the original list. Restore the original list by skipping the cloned nodes and build the cloned list by skipping the original nodes.
<details>
    <summary>Pseudo code</summary>

```pseudocode
function cloneLinkedList(head):
    if head is null:
        return null

    // Step 1: Interleave cloned nodes with original nodes
    current = head
    while current is not null:
        clonedNode = new Node(current.value)
        clonedNode.next = current.next
        current.next = clonedNode
        current = clonedNode.next

    // Step 2: Set random pointers for the cloned nodes
    current = head
    while current is not null:
        if current.random is not null:
            current.next.random = current.random.next
        current = current.next.next

    // Step 3: Separate the cloned list from the original list
    originalCurrent = head
    clonedHead = head.next
    clonedCurrent = clonedHead

    while originalCurrent is not null:
        originalCurrent.next = originalCurrent.next.next
        if clonedCurrent.next is not null:
            clonedCurrent.next = clonedCurrent.next.next
        originalCurrent = originalCurrent.next
        clonedCurrent = clonedCurrent.next

    return clonedHead
```
</details>











<br>


Left and right running sum or product of an array.
https://leetcode.com/problems/product-of-array-except-self/
https://github.com/Shubham-Gaikwad23/Algorithms/blob/master/LeetCodeProblems/productOfArrayExceptSelf.c
