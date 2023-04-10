class Solution:
    def reverse(self, x: int) -> int:
        
        x = str(x)
        y = x
        x = x[::-1]
        if x[len(x)-1]=='-':
            x = x.replace("-","")
        if y[0]=='-':
            x = -1*int(x)
        else:
            x = int(x)
        print(x)
        if x>=pow(-2,31) and x<=(pow(2,31)-1):
            return x
        else:
            return 0