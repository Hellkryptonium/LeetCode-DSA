var TimeLimitedCache = function() {
    this.map = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const entry = this.map.get(key);

    const existed = 
        entry !== undefined && entry.expiryTime > now;

    this.map.set(key, {
        value,
        expiryTime: now + duration
    })

    return existed;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    const now = Date.now();
    const entry = this.map.get(key);

    if(entry === undefined) return -1;

    if(entry.expiryTime <= now) {
        this.map.delete(key);
        return -1;
    }
    return entry.value;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let count = 0;

    for(const [key, entry] of this.map) {
        if(entry.expiryTime <= now) {
            this.map.delete(key);
        } else {
            count++;
        }
    }
    return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */