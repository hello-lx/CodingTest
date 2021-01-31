def swap(string, i, j):
    temp = string[i]
    string[i] = string[j]
    string[j] = temp

def permu(string, start, result):
    if start == None or start < 0:
        return
    if start == len(string)-1:
        result.append(''.join(string))
    else:
        i = start
        while i < len(string):
            swap(string, start, i)
            permu(string, start+1, result)
            swap(string, start, i)
            i += 1

class Solution:
    def permutation(self, s: str) -> List[str]:
        if len(s) == 0:
            return []
        s = [t for t in s]
        result = []
        permu(s, 0, result)
        return list(set(result))

