from smbus import SMBus


bus = SMBus(3) # Raspberry Pi revision 2
address = 100

while True:
    data = bus.read_i2c_block_data(address,0)
    print data