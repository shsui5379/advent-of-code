def read_input(path):
    """
    Reads the contents of the input file, 
    and returns a list of all the rows as strings
    """
    file = open(path, "r")
    output = file.readlines()
    file.close()
    return output
