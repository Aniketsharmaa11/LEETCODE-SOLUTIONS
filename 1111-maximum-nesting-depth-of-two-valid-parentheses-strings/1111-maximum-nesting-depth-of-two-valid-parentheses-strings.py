class Solution(object):
    def maxDepthAfterSplit(self, seq):
        answer = []
        depth = 0
        
        for char in seq:
            if char == '(':
                answer.append(depth % 2)
                depth += 1
            else:
                depth -= 1
                answer.append(depth % 2)
                
        return answer
