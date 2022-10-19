# https://leetcode.com/problems/top-k-frequent-elements/
#TC:nlogn
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m=defaultdict(lambda:0)
        nums.sort()
        for num in nums:
            m[num]+=1
        a=[k for k,v in sorted(m.items(),key=lambda item: item[1],reverse=True)]
        return a[:k]
   
#Bucket sort(Best time complexity)
#TC: O(n)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count_m={}
        for num in nums:
             count_m[num]=1+count_m.get(num,0)
        
        freq=[[] for i in range(len(nums)+1)]
        for ke,v in count_m.items():
            freq[v].append(ke)
            
        res=[]
        for i in range(len(freq)-1,0,-1):
            for j in freq[i]:
                #print(j)
                res.append(j)
                #print(res)
                if(len(res)==k):
                    return res
        
#Using heap
#TC: O(klogn)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        maxHeap = [[-freq, num] for num, freq in cnt.items()]
        heapify(maxHeap)
        
        ans = []
        for i in range(k):
            _, num = heappop(maxHeap)
            ans.append(num)
        return ans
            
