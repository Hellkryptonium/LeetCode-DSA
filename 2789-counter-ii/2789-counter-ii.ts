type Counter = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): Counter {
    let current = init;
    
    return {
        increment() {
            current++;
            return current;
        },

        decrement() {
            current--;
            return current;
        },

        reset() {
            current = init;
            return current;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */