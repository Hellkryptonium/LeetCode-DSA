/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if(obj == null || typeof(obj) !== "object") {
        return obj ? obj : undefined;
    }

    if(Array.isArray(obj)) {
        const result = [];
        for(let item of obj) {
            const compacted = compactObject(item);
            if(compacted !== undefined) {
                result.push(compacted);
            }
        }
        return result;
    }

    const result = {};
    for(let key in obj) {
        const compacted = compactObject(obj[key]);
        if(compacted !== undefined) {
            result[key] = compacted;
        }
    }
    return result;
};