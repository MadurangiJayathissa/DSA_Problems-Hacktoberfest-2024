import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {5, 3, 4, 1, 2}; // Array to be sorted
        bubbleSort(arr); // Call to the sorting method
        System.out.println(Arrays.toString(arr)); // Print the sorted array
    }

    static void bubbleSort(int[] arr) {
        boolean swapped; // Flag to check if any elements were swapped
        // Loop through the array for n-1 passes
        for (int i = 0; i < arr.length - 1; i++) {
            swapped = false; // Reset swap flag for this pass
            // Compare adjacent elements
            for (int j = 1; j < arr.length - i; j++) {
                // Swap if the current element is smaller than the previous one
                if (arr[j] < arr[j - 1]) {
                    // Perform the swap
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    swapped = true; // Set flag to true if a swap occurred
                }
            }
            // If no swaps were made, the array is sorted
            if (!swapped) { // If swapped is false, the array is already sorted
                break;
            }
        }
    }
}
