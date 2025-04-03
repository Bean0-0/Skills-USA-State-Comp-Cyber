from Crypto.Util.number import getPrime
from Crypto.Util.number import getRandomRange as getRandomInteger

class FlipCongruentialGenerator:
    def __init__(self, m, a, c, state):
        self.m = m
        self.a = a
        self.c = c
        self.state = state
        self.flip = False

    def next(self):
        m, a, c, state = self.m, self.a, self.c, self.state
        if self.flip:
            self.state = (a * state + c) % m
        else:
            self.state = (c * state + a) % m

        self.flip = not self.flip
        return self.state
    
m = getPrime(64)
a = getRandomInteger(1, 2**64-1)
c = getRandomInteger(1, 2**64-1)
state = getRandomInteger(1, 2**64-1)

fcg = FlipCongruentialGenerator(m, a, c, state)

print(f'{m = }')

flag = list(open('flag.txt', 'rb').read())

for i in range(len(flag)):
    flag[i] ^= fcg.next()

print(f'{flag = }')
