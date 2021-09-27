#include<bits/stdc++.h>
#include <winsock.h>
#include <windows.h>
#include <unistd.h>


using namespace std;

void error_handing(const char *msg){
    fputs(msg, stderr);
    fputs("\n", stderr);
    exit(0);
}

int main(int argc, char* argv[]){
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if(argc != 3){
        cout << "Usage : " << argv[0] << " <IP> <port>" << endl;
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handing("socket() error");

    memset(&serv_addr, 0, sizeof serv_addr);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*) &serv_addr, sizeof serv_addr) == -1){
        error_handing("connect() error");
    }

    str_len = read(sock, message, sizeof(message) -  1);
    if(str_len == -1)
        error_handing("read() error");

    cout << "get message:" << message << endl;
    close(sock);
    return 0;
}
