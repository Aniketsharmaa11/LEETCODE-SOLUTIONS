class Solution:
    def minInsertions(self, s: str) -> int:
        insertions = 0
        needed_rights = 0
        
        for char in s:
            if char == '(':
                needed_rights += 2
                if needed_rights % 2 != 0:
                    insertions += 1
                    needed_rights -= 1
            else:  # char == ')'
                if needed_rights == 0:
                    insertions += 1
                    needed_rights += 1
                else:
                    needed_rights -= 1
                    
        return insertions + needed_rights
