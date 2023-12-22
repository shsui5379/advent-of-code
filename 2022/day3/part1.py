# core problem here is finding a character that exists in both the first and second half of a string

# one approach
# insert all characters of the first half into a set
# then look up each character from the second half
# runtime:
# inserting into the set should take O(n/2), where n is length of string
# the lookups should take O(n/2)
# total O(n)
# space:
# O(n/2), as half of the string will be put into a set

# second approach
# for each character in the first half, search its existence in the second half
# runtime:
# O(n^2), nested loop idiom
# space:
# O(1), nothing new has to be stored

# which approach is better depends on the environment's constraints
# saving runtime or saving memory

import sys


def read_input(path):
    """
    Reads the contents of the input file,
    and returns a list of all the rows as strings
    """
    file = open(path, "r")
    output = file.readlines()
    file.close()
    return output


def solve(path):
    input_data = read_input(path)
    priorities = 0

    # O(m)
    for row in input_data:
        first_half_set = set()
        row = row[:-1]

        # O(n/2)
        for letter in row[0 : int(len(row) / 2)]:
            first_half_set.add(letter)

        # O(n/2)
        for letter in row[int(len(row) / 2) :]:
            if letter in first_half_set:
                if letter.isupper():
                    priorities += ord(letter) - ord("A") + 27
                else:
                    priorities += ord(letter) - ord("a") + 1
                break

    return priorities


assert solve("sample.txt") == 157

if len(sys.argv) < 2:
    print("privide input file path")
else:
    print(solve(sys.argv[1]))
