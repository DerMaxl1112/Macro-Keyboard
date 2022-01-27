import serial

#info auf https://maker.pro/pic/tutorial/introduction-to-python-serial-ports


serialPort = serial.Serial(port = "COM4", baudrate=9800, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)
