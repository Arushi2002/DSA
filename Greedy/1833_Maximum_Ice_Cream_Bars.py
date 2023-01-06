#Can try dp like knapsack but its very high TC
#So use DP

#Greedy sort
#TC: O(nlogn)
# #SC:O(n)
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        
        i=0
        while(i<len(costs) and coins>=costs[i]):
            coins-=costs[i]
            i+=1

        return i
    
#Counting Sort(Greedy)
#TC: O(n+m)
#SC: O(m)
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        m=max(costs)
        costFrequency=[0]*(m+1)
        icecreams = 0
        for cost in costs:
            costFrequency[cost]+=1
        
        for cost in range(1,m+1):
            count=min(costFrequency[cost],coins//cost)
            coins-=cost*count
            icecreams+=count
            
        return icecreams

            
            
        
            
            



    
            

        
        
        
                
            
        
