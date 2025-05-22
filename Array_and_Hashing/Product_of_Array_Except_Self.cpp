class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        vector<int> result(n); // Initialize the result array with size 'n'

        int prefix = 1;
        // First pass: Calculate prefix product for each element
        // result[i] will hold the product of all elements to the left of index i
        for(int i = 0; i < n; i++){
            result[i] = prefix;    // Store the current prefix product
            prefix *= nums[i];     // Update prefix product by multiplying with current element
        }

        int postfix = 1;
        // Second pass: Multiply with postfix products
        // result[i] will now hold the product of all elements to the left and right of index i
        for(int j = n - 1; j >= 0; j--){
            result[j] *= postfix;  // Multiply with the postfix product (elements to the right)
            postfix *= nums[j];    // Update postfix product by multiplying with current element
        }

        return result; // Return the final result
    }
};
