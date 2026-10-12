class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        
        # Step 1: Count the total number of 1s at each bit position
        bit_counts = [0] * 32
        for num in nums:
            for i in range(32):
                if (num >> i) & 1:
                    bit_counts[i] += 1
                    
        # Step 2 & 3: Greedily construct the k largest numbers and sum their squares
        total_sum_squares = 0
        
        for _ in range(k):
            current_num = 0
            for i in range(32):
                if bit_counts[i] > 0:
                    current_num |= (1 << i)
                    bit_counts[i] -= 1
            
            total_sum_squares = (total_sum_squares + current_num * current_num) % MOD
            
        return total_sum_squares
