#include <stdlib.h>
#include <stdio.h>
#include <progbase/net.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LEN 10000


int createFile(char * filename, char * text);


typedef struct ClientRequest {
	char action[40];
	char str[10200];
    char content[10200];
} ClientRequest;

ClientRequest parseRequest(const char * msgStr) {
	ClientRequest request = {
		.action = "",
		.str = "",
        .content = ""
	};
	int chIndex = 0;
	while (isalpha(msgStr[chIndex])) {
		chIndex ++;
	}
	strncpy(request.action, msgStr, chIndex);
	while (isspace(msgStr[chIndex])) {
		chIndex ++;
	}
    int space1 = chIndex;
    while(!isspace(msgStr[space1] )){
        space1++;
    }
    int i = 0;
    while(chIndex != space1){
        request.str[i] = msgStr[chIndex];
        i++;
        chIndex++;
    }
    int space = strlen(request.str) - 1;
    while (isspace(request.str[space])) space--;
	request.str[space + 1] = '\0';
    if(strlen(msgStr) > space1 + 1){
        while (isspace(msgStr[chIndex])) {
                chIndex ++;
            }
            int space2 = chIndex;
            while(!isspace(msgStr[space2] )){
                space2++;
            }
            int j = 0;
            while(chIndex != space2){
                request.content[j] = msgStr[chIndex];
                j++;
                chIndex++;
            }
            int space3 = strlen(request.content) - 1;
            while (isspace(request.content[space3])) space3--;
            request.content[space3 + 1] = '\0';
    }

    
	return request;
}

void printRequest(ClientRequest request) {
	printf("Client request is: `%s` `%s` `%s`\n", 
		request.action,
		request.str,
        request.content);
}

bool readFile(const char * filename, char * text) {
	char line[100];
    FILE * fr = fopen(filename, "r");
	if (fr == NULL){
        return false;
    }
    while(fgets(line, 100, fr)) {
        strcat(text, line);
    }
	fclose(fr);
	return true;
}
int createFile(char * filename, char * text){

    FILE * fw = fopen(filename, "w");
    if(fw == NULL){
        return 0;
    }
    for(int i =0; i < strlen(text);i++){
        fprintf(fw, "%c", text[i]);
    }
    fclose(fw);
    return 1;
}

int main(void) {
    UdpClient * server = UdpClient_init(&(UdpClient){});
    IpAddress * address = IpAddress_initAny(&(IpAddress){}, 9994);
    if (!UdpClient_bind(server, address)) {
        perror("Can't start server");
        return 1;
    }
    printf("Udp server started on port %d\n", 
        IpAddress_port(UdpClient_address(server)));
    
    NetMessage * message = NetMessage_init(
        &(NetMessage){},  
        (char[BUFFER_LEN]){},  
        BUFFER_LEN);

    IpAddress clientAddress;



    while (1) {
        puts("Waiting for data...");
        if(!UdpClient_receiveFrom(server, message, &clientAddress)) {
			perror("recv");
			return 1;
		}
        ClientRequest req = parseRequest(NetMessage_data(message));
		printRequest(req);
        if(0 == strcmp(req.action, "read")){
            char text[10000];
                if(readFile(req.str, text) != false ){
                    NetMessage_setDataString(message, text);
                }
                else{
                    NetMessage_setDataString(message, "Файл не знайдено");
                }
            
        }
        else if(0 == strcmp(req.action, "create")){
            NetMessage_setDataString(message, req.str);
            if(createFile(req.str, req.content) == 0){
                NetMessage_setDataString(message, "false");
            }
            else{
                NetMessage_setDataString(message, "true");
            }
           // NetMessage_setDataString(message, "Файл");
        }  
        else if(0 == strcmp(req.action, "q")){
            NetMessage_setDataString(message, "exit");
            printf("Received message from %s:%d (%d bytes): `%s`\n",
            IpAddress_address(&clientAddress),  // client IP-address
            IpAddress_port(&clientAddress),  // client port
            NetMessage_dataLength(message),
            NetMessage_data(message));
            UdpClient_sendTo(server, message, &clientAddress);
            break;
        }
        else{
            NetMessage_setDataString(message, "Error");
        }

        printf("Received message from %s:%d (%d bytes): `%s`\n",
        IpAddress_address(&clientAddress),  // client IP-address
        IpAddress_port(&clientAddress),  // client port
        NetMessage_dataLength(message),
        NetMessage_data(message)); 
        if (!UdpClient_sendTo(server, message, &clientAddress)) {
            perror("send");
            return 1;
        }
    }
    UdpClient_close(server);
	return 0;
}
