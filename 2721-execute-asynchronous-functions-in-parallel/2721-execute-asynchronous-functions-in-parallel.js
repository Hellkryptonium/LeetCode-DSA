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

        functions.forEach((asyncFn, index) => {
            asyncFn()
                .then(value => {
                    result[index] = value;
                    count++;
                    if(count === functions.length) {
                        resolve(result);
                    }
                })
                .catch(error => {
                    reject(error);
                });

        })
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */