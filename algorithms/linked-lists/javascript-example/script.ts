/* Basic struct of a Linked List*/
class ListNode {
	val: number;
	next: ListNode | null;

	constructor(val: number) {
		this.val = val;
		this.next = null;
	}
}

/* Print all values of the list */
function printList(head: ListNode | null): void {
	const values: number[] = [];
	let current = head;
	while (current) {
		values.push(current.val);
		current = current.next;
	}
	console.log(values.join(" -> "));
}

/* Create the head of List */
function createList(val: number): ListNode {
	return new ListNode(val);
}

/* Insert one Node, but this node is the new head */
function insertList(head: ListNode | null, val: number): ListNode {
	const node = createList(val);
	node.next = head;
	return node;
}

/* Remove any node from the list */
function deleteNode(node: ListNode | null, val: number): void {
	if (!node || !node.next) return;

	if (node.val === val) {
		const aux = node.next;
		node.val = aux.val;
		node.next = aux.next;
	}
}

/*  
  This part of the code is intended to represent as closely 
  as possible what was done in C. It would not be necessary 
  to put all the functions inside a main and execute it.
*/
function main() {
	let head: ListNode | null = createList(50);
	head = insertList(head, 40);
	head = insertList(head, 30);
	head = insertList(head, 20);
	head = insertList(head, 10);

	deleteNode(head, 10);
	printList(head);
}

main();
