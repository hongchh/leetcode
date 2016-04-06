/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    return parseInt(num)-parseInt((num-1)/9)*9;
};