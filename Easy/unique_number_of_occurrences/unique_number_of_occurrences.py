from typing import List

def uniqueOccurrences(arr: List[int]) -> bool:
    count = {}
    for num in arr:
        count[num] = count.get(num, 0) + 1
    occurrences = set()
    for freq in count.values():
        if freq in occurrences:
            return False
        occurrences.add(freq)
    return True

if __name__ == "__main__":
    print("Testing uniqueOccurrences function:")
    print("For the input arr = [1,2,2,1,1,3], the output is:", uniqueOccurrences([1,2,2,1,1,3])) 
    print("For the input arr = [1,2], the output is:", uniqueOccurrences([1,2]))
    print("For the input arr = [-3,0,1,-3,1,1,1,-3,10,0], the output is:", uniqueOccurrences([-3,0,1,-3,1,1,1,-3,10,0]))