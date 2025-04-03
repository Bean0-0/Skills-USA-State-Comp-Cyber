from sympy import isprime

current_prime = 7948992548489485950921349586776478634516625616506621719276263753

next_number = current_prime + 1
while not isprime(next_number):
    next_number += 1

print(f"Next prime after {current_prime} is {next_number}")
print(f"Flag: gigem{{{next_number}}}")