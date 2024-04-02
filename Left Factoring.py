def check_left_factoring(grammar):
    for non_terminal in grammar:
        productions = grammar[non_terminal]
        for i in range(len(productions)):
            for j in range(i + 1, len(productions)):
                # Split the production rules by spaces to get individual symbols
                symbols_i = productions[i].split(' ')
                symbols_j = productions[j].split(' ')
                # Check if the first symbol in both production rules is the same
                if symbols_i[0] == symbols_j[0]:
                    return True
    return False

# Example usage:
grammar = {
    'A': ['a b', 'a c']
}
print(check_left_factoring(grammar))  # This will print: True
