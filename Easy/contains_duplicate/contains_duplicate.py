def containsDuplicate(self, nums):
    if(len(nums) == len(set(nums))):
        return False
    else:
        return True
    
if __name__ == "__main__":
    print("Testing containsDuplicate function:")
    print("For the input [1, 2, 3, 1], the output is:", containsDuplicate(None, [1, 2, 3, 1])) #Output: True
    print("For the input [1, 2, 3, 4], the output is:", containsDuplicate(None, [1, 2, 3, 4])) #Output: False
    print("For the input [1, 1, 1, 3, 3, 4, 3, 2, 4, 2], the output is:", containsDuplicate(None, [1, 1, 1, 3, 3, 4, 3, 2, 4, 2])) #Output: True
