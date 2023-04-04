class Solution:
    def partitionString(self, s: str) -> int:
        # i=0
        temp=""
        count=0
        for i in range(len(s)):
            if s[i] in temp:
                count+=1
                temp=s[i]
            else:
                temp = temp+s[i]
        return count+1