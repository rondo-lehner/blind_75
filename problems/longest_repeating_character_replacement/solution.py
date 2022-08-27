class Solution:

    # Idea:
    # 1. Identify the set of characters in the string -> add all chars to set
    # 2. For each character c find the first occurence in the string and attempt to build the longest substring by skipping at most k characters != c
    # 3. Return the longest substring

    # Time complexity: O(n)
    # Note: despite there being a nested for loop, the outer for loop is executed at most 26 times which can be considered a constant.

    def characterReplacement(s: str, k: int) -> int:
        characters = set(s)

        substring_longest = 0
        substring_current = 0
        replacements_remaining = k

        for c_focus in characters:
            for i, c in enumerate(s):
                if c == c_focus:
                    substring_current += 1
                    continue

                if replacements_remaining > 0:
                    replacements_remaining -= 1
                    continue

                if replacements_remaining == 0 or i == len(s) - 1:
                    substring_current = min(len(s), substring_current + k)  #Constrain the value to be no longer than the string itself
                    substring_longest = max(substring_longest, substring_current)
                    replacements_remaining = k
                    substring_current = 0
        
        return substring_longest


def main():
    print(Solution.characterReplacement("AABABBA", 1))

main()




        