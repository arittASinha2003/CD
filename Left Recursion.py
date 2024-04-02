def check_left_recursion(grammar):
    for non_terminal in grammar:
        for production in grammar[non_terminal]:
            # Split the production rule by spaces to get individual symbols
            symbols = production.split(' ')
            # Check if the first symbol in the production rule is the same as the non-terminal
            if symbols[0] == non_terminal:
                return True
    return False

# Example usage:
grammar = {
    'A': ['A a', 'b']
}
print(check_left_recursion(grammar))  # This will print: True
