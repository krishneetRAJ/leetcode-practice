from typing import List

def threeSumClosest(nums: List[int], target: int) -> int:
    nums.sort()
    closest = nums[0] + nums[1] + nums[2]

    for i in range(len(nums) - 2):
        left = i+1
        right = len(nums) - 1

        while left < right:
            current_sum = nums[i] + nums[left] + nums[right]

            if abs(current_sum - target) < abs(closest - target):
                closest = current_sum

            if current_sum < target:
                left += 1
            elif current_sum > target:
                right -= 1
            else:
                return current_sum

    return closest

if __name__ == "__main__":
    print("Testing threeSumClosest function:")
    nums = [-1, 2, 1, -4]
    target = 1
    print(f"For the input nums = {nums} and target = {target}, the output is: {threeSumClosest(nums, target)}")

    nums = [0, 0, 0]
    target = 1
    print(f"For the input nums = {nums} and target = {target}, the output is: {threeSumClosest(nums, target)}")