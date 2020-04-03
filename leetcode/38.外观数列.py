#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#

# @lc code=start
class Solution:
    def countAndSay(self, n: int) -> str:
        a=[1]
        b=[]
        i=1
        while i<n:
            k=0
            q=1
            p=0
            b=[]
            while k<len(a)-1:
                if a[k]==a[k+1]:
                    q+=1
                else:
                    b.append(q)
                    b.append(a[k])
                    q=1
                k+=1

            b.append(q)
            b.append(a[k])
            a=b[:]
            i+=1
        st = ''.join(str(i) for i in a)
        return st


# @lc code=end

