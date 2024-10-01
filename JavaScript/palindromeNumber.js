function isPalindrome(num) {
    // Convert the number to a string
    const str = num.toString();
    // Initialize pointers for the start and end of the string
    let left = 0;
    let right = str.length - 1;

    // Check for palindrome by comparing characters
    while (left < right) {
        if (str[left] !== str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; // It's a palindrome
}

// Example usage
const number = 12321;
console.log(`Is ${number} a palindrome? `, isPalindrome(number)); // Output: true

const anotherNumber = 12345;
console.log(`Is ${anotherNumber} a palindrome? `, isPalindrome(anotherNumber)); // Output: false

// Example usage:
console.log('12321', isPalindrome(12321))
console.log('54345', isPalindrome(54345))
console.log('1000003545', isPalindrome(1000003545))
console.log('121', isPalindrome(121))
