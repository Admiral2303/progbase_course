#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <progbase/net.h>
#include <string.h>

#define BUFFER_LEN 10000
// create <filename> "text" - створити файл з заданим текстом ПРИКЛАД: create output.txt Hello!!!
// read <filename> - зчитати з файла ПРИКЛАД: read input.txt


int main(void) {
	//
    // initialize all data
    UdpClient * client = UdpClient_init(&(UdpClient){});
    IpAddress * serverAddress = IpAddress_init(
        &(IpAddress){},  // value on stack
        "127.0.0.1",  // server host IP-address (localhost)
        9994);  // server port
    
    NetMessage * message = NetMessage_init(
        &(NetMessage){},  // value on stack
        (char[BUFFER_LEN]){},  // array on stack 
        BUFFER_LEN); 

while (1) {
        puts("q-exit \nPlease, input request:");
        char request[1000] = "";

        // @todo Read user input and create request message
        fgets(request, 100, stdin);
        NetMessage_setDataString(message, request);
        //
       
        // send request to server
        UdpClient_sendTo(client, message, serverAddress);
        //
        // blocking call to receive response data from server
        UdpClient_receiveFrom(client, message, serverAddress);

        printf("Received message from server (%d bytes): `%s`\n",
            NetMessage_dataLength(message),
            NetMessage_data(message));
               

        if(strcmp(NetMessage_data(message), "exit") == 0){
            break;
        }
        // @todo Show server response to user
        
    }
    //
    // close client
    UdpClient_close(client);
    return 0;
}
