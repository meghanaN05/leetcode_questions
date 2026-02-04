class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        maxi=0

        for i in left:
            maxi=max(maxi,i)

        for i in right:
            maxi=max(maxi,n-i) 

        return maxi