import serial


PORT = open('safe/PORT.txt', 'r')
for line in PORT:
    Port = line.split('\n')[0]

#info at https://maker.pro/pic/tutorial/introduction-to-python-serial-ports


serialPort = serial.Serial(port = Port, baudrate=9600, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)

serialString = ""                           # Used to hold data coming over UART


while(1):

    # Wait until there is data waiting in the serial buffer
    if(serialPort.in_waiting > 0):

        # Read data out of the buffer until a carraige return / new line is found

        serialString = serialPort.readline()        #only 1s and 0s
        serialString = serialString.decode('utf-8') #decode to text (string)
        serialString = serialString.split('\n')[0]     #remove new line \n

        # Print the contents of the serial data
        print(serialString)
