#include <stdio.h>

int climbStairs(int n) {
    if (n < 0)
        return 0; // No way to climb negative steps
    if (n == 0)
        return 1; // 1 way to stay at the ground
    if (n == 1)
        return 1; // 1 way to climb one step
    if (n == 2)
        return 2; // 2 ways to climb two steps

    int prev2 = 1;  // Ways to climb 0 steps
    int prev1 = 2;  // Ways to climb 1 step
    int curr;       // Variable to store current number of ways

    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2; // The current ways to climb to step i
        prev2 = prev1;        // Move to the next step
        prev1 = curr;        // Update previous for next iteration
    }

    return prev1; // Return the total ways
}

int main() {
    int n;
    // Takes input from the user
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    // Stores the number of ways
    int ways = climbStairs(n);
    printf("Number of distinct ways to climb %d steps: %d\n", n, ways);
    return 0;
}

// Test Cases
// Test case 1: n = 0
// Expected output: 1 (1 way to stay at the ground)

// Test case 2: n = 1
// Expected output: 1 (1 way to climb one step)

// Test case 3: n = 2
// Expected output: 2 (1 step + 1 step, 2 steps)

// Test case 4: n = 3
// Expected output: 3 (1+1+1, 1+2, 2+1)

// Test case 5: n = 4
// Expected output: 5 (1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2)

// Test case 6: n = 5
// Expected output: 8 (1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 1+2+2, 2+1+2, 2+2+1)
