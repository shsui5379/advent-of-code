# core problem here is finding the common character from 3 lines

# one approach
# insert all characters of each line into their own set
# then find the intersection of the 3 sets
# runtime:
# inserting into the set should take O(n), where n is length of the 3 string
# the intersection: O(2n)
# total O(3n)
# space:
# O(3n)

# second approach
# for each character in the first line, search its existence in the second and third line
# runtime:
# O(n^3), nested loop idiom
# space:
# O(1), nothing new has to be stored

# third approach
# store first and second line in their own sets
# take intersect, then lookup elements of the intersect in third line
# prob no difference from first approach, since that's what's happening under the hood

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
    for i in range(0, len(input_data), 3):
        first_set = set()
        second_set = set()
        third_set = set()

        # O(3n)
        for letter in input_data[i][:-1]:
            first_set.add(letter)

        for letter in input_data[i + 1][:-1]:
            second_set.add(letter)

        for letter in input_data[i + 2][:-1]:
            third_set.add(letter)

        # O(3n)
        for letter in first_set.intersection(second_set).intersection(third_set):
            if letter.isupper():
                priorities += ord(letter) - ord("A") + 27
            else:
                priorities += ord(letter) - ord("a") + 1

    return priorities


assert solve("sample.txt") == 70

if len(sys.argv) < 2:
    print("privide input file path")
else:
    print(solve(sys.argv[1]))
