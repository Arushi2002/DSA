#Even better sol
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        MAX = max(nums) ### Find the largest number in nums.
        res = 0			 
        count = 0		### Used to count the length of the continues subarray that only contains MAX
        for n in nums:
        	### If the current number is MAX, increase count
            if n==MAX:
                count +=1
            ### Otherwise, reset count.
            else:
                count = 0
            ### store the maximum count as result.
            res = max(res, count)
        return res

#Similar to kadens algo
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        m=max(nums)
        ind=[]
        for i in range(len(nums)):
            if(nums[i]==m):
                ind.append(i)
        curr_len=1
        max_len=1
        for i in range(0,len(ind)-1):
            if(ind[i]+1==ind[i+1]):
                curr_len+=1
                if(max_len<curr_len):
                    max_len=curr_len
            else:
                curr_len=1
        return max_len
    
#Brute force
#Not accpeted TLE
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        d=defaultdict(lambda:[])
        # arr=[]
        for i in range(len(nums)):
            a=[nums[i]]
            band=nums[i]
            b=a.copy()
            d[band].append(b)
            for j in range(i+1,len(nums)):
                band=band & nums[j]
                a.append(nums[j])
                # arr.append(a)
                b=a.copy()
                d[band].append(b)
        
        #print(d)
        # print(arr)
        max_key=max(d.keys())
        max_li=max(d[max_key],key=len)
        #print(max_li)
        return len(max_li)
            
            
                
                
