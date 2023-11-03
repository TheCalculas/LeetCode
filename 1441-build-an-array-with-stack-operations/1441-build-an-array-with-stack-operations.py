class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        curr, result = 1, []
        for num in target:
            result += ['Push'] + ['Pop', 'Push'] * (num - curr)
            curr = num + 1
        return result