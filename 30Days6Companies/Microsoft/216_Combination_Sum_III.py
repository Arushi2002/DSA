class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res=[]
        candidates=[i for i in range(1,10)]
        def dfs(pos,cur,target,size):
            if target==0 and size==k:
                res.append(cur.copy())
                return
            if size>k or target<0:
                return

            prev=-1
            for i in range(pos,len(candidates)):
                if(candidates[i]==prev):
                    continue
                cur.append(candidates[i])
                dfs(i+1,cur,target-candidates[i],size+1)
                cur.pop()
                prev=candidates[i]

        dfs(0,[],n,0)
        return res
            
