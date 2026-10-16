from typing import List

def minStickers(stickers: List[str], target: str) -> int:
    queue = [(target, 0)]
    visited = set()
    visited.add(target)

    while queue:
        remaining, count = queue.pop(0)
        if remaining == "":
            return count
        for sticker in stickers:
            available = {}

            for char in sticker:
                available[char] = available.get(char, 0) + 1
            new_remaining = ""
            for char in remaining:
                if available.get(char, 0) > 0:
                    available[char] -= 1
                else:
                    new_remaining += char
            if new_remaining == "":
                return count + 1
            if new_remaining not in visited:
                visited.add(new_remaining)
                queue.append((new_remaining, count + 1))
    return -1

if __name__ == "__main__":
    print("Testing minStickers function:")
    print("For the input stickers = ['with', 'example', 'science'] and target = 'thehat', the output is:", minStickers(['with', 'example', 'science'], 'thehat'))  # Output: 3
    print("For the input stickers = ['notice', 'possible'] and target = 'basicbasic', the output is:", minStickers(['notice', 'possible'], 'basicbasic'))  # Output: -1