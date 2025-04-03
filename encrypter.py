# By submitting this assignment, I agree to the following:
# “Aggies do not lie, cheat, or steal, or tolerate those who do”
# “I have not given or received any unauthorized aid on this assignment”
#
# Name: flocto
# Section: 1001
# Assignment: Lab 0
# Date: 12/25/2024

# Encrypts a message by shifting the ASCII value of each character by 13
def encrypt(msg):
    return ''.join([hex(ord(c) - 13 if i%2 == 0 else ord(c) + 13)[2:].zfill(2) for i, c in enumerate(msg)])

def decrypt(msg):
    return ''.join([chr(int(msg[i:i+2], 16) + 13 if (i//2)%2 == 0 else int(msg[i:i+2], 16) - 13) for i in range(0, len(msg), 2)])

line = input("Enter a message you want to encrypt: ")
print(f"Your encrypted message is: {decrypt(line)}")

#Your encrypted message is: 4775582d597954741376664713745c74587a6e54233d576c3d7c556c6c3d686c5641616c65405471525d4c815b3d618a
