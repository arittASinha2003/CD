def first(grammar, term):
    first_set = set()
    if term not in grammar:
        return set(term)
    for prod in grammar[term]:
        first_sym = prod[0]
        if first_sym not in grammar:
            first_set.add(first_sym)
        else:
            first_set |= first(grammar, first_sym)
    return first_set

def follow(grammar, term, checked=None):
    if checked is None:
        checked = set()
    if term in checked:
        return set()
    checked.add(term)
    follow_set = set()
    if term == list(grammar.keys())[0]:
        follow_set.add('$')
    for key, productions in grammar.items():
        for prod in productions:
            if term in prod:
                next_sym_pos = prod.index(term) + 1
                if next_sym_pos < len(prod):
                    next_sym = prod[next_sym_pos]
                    follow_set |= first(grammar, next_sym)
                else:
                    follow_set |= follow(grammar, key, checked)
    return follow_set

# Example usage:
# grammar = {
#     'E': ['TG'],
#     'G': ['+TG', 'ε'],
#     'T': ['FS'],
#     'S': ['*FS', 'ε'],
#     'F': ['(E)', 'i']
# }
# Output:
# FIRST(E) = {'(', 'i'}
# FOLLOW(E) = {')', '$'}
# FIRST(G) = {'ε', '+'}
# FOLLOW(G) = {')', '$'}
# FIRST(T) = {'(', 'i'}
# FOLLOW(T) = {'ε', '+'}
# FIRST(S) = {'*', 'ε'}
# FOLLOW(S) = {'ε', '+'}
# FIRST(F) = {'(', 'i'}
# FOLLOW(F) = {'*', 'ε'}

grammar = {
    'E': ['AB'],
    'A': ['ilove'],
    'B': ['jtptutorials']
}
# Output:
# FIRST(E) = {'i'}
# FOLLOW(E) = {'$'}
# FIRST(A) = {'i'}
# FOLLOW(A) = {'j'}
# FIRST(B) = {'j'}
# FOLLOW(B) = {'$'}

for non_terminal in grammar:
    print(f'FIRST({non_terminal}) = {first(grammar, non_terminal)}')
    print(f'FOLLOW({non_terminal}) = {follow(grammar, non_terminal)}')
