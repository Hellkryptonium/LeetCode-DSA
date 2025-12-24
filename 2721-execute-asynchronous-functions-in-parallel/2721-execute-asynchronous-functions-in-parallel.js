/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        if(functions.length === 0) {
            resolve([]);
            return;
        }

        let count = 0;
        let result = [];

        for(let i=0; i<functions.length; i++) {
            let asyncFn = functions[i];
            asyncFn()
                .then(value => {
                    result[i] = value;
                    count++;
                    if(count === functions.length) {
                        resolve(result);
                    }
                })
                .catch(error => {
                    reject(error);
                })
        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */