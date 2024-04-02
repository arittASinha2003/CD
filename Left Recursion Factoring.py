# left recursion 
def eliminate_left_recursion(grammar):
  non_terminals = list(grammar.keys())
  new_grammar = {}
  for A in non_terminals:
      productions = grammar[A]
      # Divide productions into those with and without left recursion
      alpha_productions = []
      beta_productions = []
      for prod in productions:
          if prod.startswith(A):
              alpha_productions.append(prod[len(A):])
          else:
              beta_productions.append(prod)
      if alpha_productions:
          new_non_terminal = A + "'"
          new_grammar[new_non_terminal] = [prod + new_non_terminal for prod in alpha_productions] + ["ε"]
          new_productions = [prod + new_non_terminal for prod in beta_productions]
          new_grammar[A] = new_productions
      else:
          new_grammar[A] = productions

  return new_grammar
# Example grammar
grammar = {
  'S': ['S A', 'A'],
  'A': ['A a', 'b']
}

eliminated_grammar = eliminate_left_recursion(grammar)
for non_terminal, productions in eliminated_grammar.items():
  print(non_terminal, '->', ' | '.join(productions))

# left factoring

def left_factor(grammar):
  new_grammar = {}
  for non_terminal, productions in grammar.items():
      common_prefix = longest_common_prefix(productions)
      if common_prefix:
          new_non_terminal = non_terminal + "_factored"
          new_grammar[new_non_terminal] = [prod[len(common_prefix):].strip() or "ε" for prod in productions]
          new_grammar[non_terminal] = [common_prefix + " " + new_non_terminal]
      else:
          new_grammar[non_terminal] = productions
  return new_grammar
def longest_common_prefix(strings):
  if not strings:
      return ""
  prefix = strings[0]
  for string in strings[1:]:
      while string[:len(prefix)] != prefix and len(prefix) > 0:
          prefix = prefix[:-1]
  return prefix
# Example grammar
grammar = {
  'S': ['abcde', 'abcdxyz', 'abpq'],
  'A': ['ab', 'acd', 'ade']
}
factored_grammar = left_factor(grammar)
for non_terminal, productions in factored_grammar.items():
  print(non_terminal, '->', ' | '.join(productions))
