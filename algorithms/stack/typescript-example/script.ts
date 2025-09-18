/* Struct Element that store our "char" */
class Elem {
	c: string;
	next: Elem | null;

	constructor(c: string) {
		this.c = c;
		this.next = null;
	}
}

/* Stack Structure */
class Stack {
	private top: Elem | null;

	constructor() {
		this.top = null;
	}

	/* Insert element at the top */
	push(c: string): void {
		const node = new Elem(c);
		node.next = this.top;
		this.top = node;
	}

	/* Remove element from the top */
	pop(): string | null {
		if (this.isEmpty()) {
			throw new Error("Stack is empty!");
		}
		const node = this.top!;
		this.top = node.next;
		return node.c;
	}

	/* Check if stack is empty */
	isEmpty(): boolean {
		return this.top === null;
	}

	/* Free stack (optional in TypeScript, GC handles memory) */
	clear(): void {
		this.top = null;
	}
}
