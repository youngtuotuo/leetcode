class Solution:
    def isValid(self, s: str) -> bool:
        left = []
        pair = {'(':')', '[':']', '{':'}'}
        for p in s:
            if p in pair:
                left.append(p)
            else:
                if len(left) == 0 or pair[left.pop()] != p:
                    return False
        return len(left) == 0







if __name__ == "__main__":
    s = "]"
    print(Solution().isValid(s))
