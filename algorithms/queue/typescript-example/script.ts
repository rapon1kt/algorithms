// Define the structure that will be stored in the queue
export interface Point {
	x: number;
	y: number;
}

export class Queue {
	private start: number;
	private end: number;
	private values: (Point | null)[];
	private readonly MAX_CAP: number;

	constructor(maxCapacity: number = 100) {
		this.MAX_CAP = maxCapacity;
		this.values = new Array(this.MAX_CAP).fill(null);
		this.start = 0;
		this.end = 0;
	}

	// Check if the queue is empty
	isEmpty(): boolean {
		return this.start === this.end;
	}

	// Check if the queue is full
	isFull(): boolean {
		return (this.end + 1) % this.MAX_CAP === this.start;
	}

	// Insert a new point at the end of the queue
	enqueue(p: Point): void {
		if (this.isFull()) {
			console.error("ERROR: queue is full");
			return;
		}
		this.values[this.end] = p;
		this.end = (this.end + 1) % this.MAX_CAP;
	}

	// Remove and return the first point in the queue
	dequeue(): Point | null {
		if (this.isEmpty()) {
			console.error("ERROR: queue is empty");
			return null;
		}
		const p = this.values[this.start];
		this.start = (this.start + 1) % this.MAX_CAP;
		return p;
	}
}
