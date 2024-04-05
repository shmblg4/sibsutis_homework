import socket

SERVER = socket.socket()
SERVER_ADDR = ('172.26.32.1', 3000)
SERVER.bind(SERVER_ADDR)

SERVER.listen(1)
print(f"Server in ON with address: {SERVER_ADDR}")

CLIENT, CLIENT_ADDR = SERVER.accept()
print(f"Connection established with: {CLIENT_ADDR}")

data = CLIENT.recv(1024)
print(f"Get data from user: {data}")

CLIENT.close()
SERVER.close()
