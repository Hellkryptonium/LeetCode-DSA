/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const result = [];

    function helper(currentArray, depth) {
        for(let item of currentArray) {
            if(Array.isArray(item) && depth < n) {
                helper(item, depth+1);
            } else {
                result.push(item);
            }
        }
    }

    helper(arr, 0);
    return result;
};