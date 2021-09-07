#define _GNU_SOURCE 1
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <poll.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define USER_LIMIT 5
#define BUFFER_SIZE 64
#define FD_LIMIT 65535

struct {
    struct sockaddr_in address;
    char* write_buf;
    char buf [BUFFER_SIZE];
}client_data;

int main( int argc, char* argv[]){
    if( argc <= 2){
        printf("argument error");
        return 1;
    }

    const char* ip = argv[1];
    int port = atoi( argv[2] );

    struct sockaddr_in address;
    bzero( &address, sizeof( address) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr);
    address.sin_port = htons( port );

    int listenfd = socket( PF_INET, SOCK_STREAM, 0);
    asser( listenfd>=0 );

    int ret = 0;
    ret = bind( listenfd, ( struct sockaddr* )&address, sizeof( address ) );
    assert( ret != -1 );

    ret = listen( listenfd, 5 );
    assert( ret != -1 );

    client_data* users = new client_data[FD_LIMIT]

    pollfd fds[USER_LIMIT+1];
    int user_count = 0;
    for( int i = 1; i<=USER_LIMIT; ++i){
        fds[i].fd = -1;
        fds[i].events = 0;
    }
    fds[0].fd = listenfd;
    fds[0].events = POLLIN | POLLERR;
    fds[0].revents = 0;

    while( 1 ){
        ret = poll( fds, user_count+1, -1);
        if ( ret < 0){
            printf("poll failure\n");
            break;
        }

        for( int i = 0; i < user_count+1; ++i){
            if((fds[i].fd == listenfd) && (fds[i].revents & POLLIN)){
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof( client_address);
                int connfd = accept( listenfd, (struct sockaddr*)
                                                &client_address, &client_addrlength);
                if ( connfd < 0 ){
                    printf("error");
                    continue;
                }

                if ( user_count >= USER_LIMIT ){
                    const char* info = "too many users\n";
                    send ( connfd, info, strlen(info), 0);
                    close (connfd);
                    continue;
                }

                user_count++;
                users[connfd].address = client_address;
                setnonblocking( connfd );
                fds[user_count].fd = connfd;
                fds[user_count].events = POLLIN | POLLHUP | POLLERR;
                fds[user_count].revents = 0;
                printf("a new user!\n");
            }
            else if ( fds[i].revents & POLLERR){
                printf("get an error!\n");
                char errors[100];
                /*获取socket的错误码，暂时没写*/
            }
            else if ( fds[i].revents & POLLHUP ){
                users[fds[i].fd] = 
            }
            else if ( fds[i].revents & POLLIN){
                int connfd = fds[i].fd;
                memset( users[connfd].buf, '\0', BUFFER_SIZE );
                ret = recv( connfd, users[connfd].buf, BUFFER_SIZE-1, 0);
                print("get %d bytes of client data %s from %d\n", ret,users[connfd].buf, connfd);
                if ( ret < 0 ){
                    if ( errno != EAGAIN ){
                        close( connfd );
                        users[fds[i].fd] = users[fds[user_count].fd];
                        fds[i] = fds[user_count];
                        i--;
                        user_count--;
                    }
                }
                else if (ret==0){

                }
                else{
                    for ( int j = 1; j <= user_count; ++j){
                        if( fds[j].fd == connfd){
                            continue;
                        }
                        fds[j].events |= ~POLLIN;
                        fds[j].events |= POLLOUT;
                        users[fds[j].fd].write_buf = users[connfd].buf;
                    }
                }
            }
            else if ( fds[i].revents & POLLOUT){
                int connfd = fds[i].fd;
                if ( ! users[connfd].write_buf ){
                    continue;
                }
                ret = send( connfd, users[connfd].write_buf, strlen( uses[connfd].write_buf), 0 );
                users[connfd].write_buf = NULL;

                fds[i].events |= ~POLLOUT;
                fds[i].events |= POLLIN;  
            }
        }
    }
    delete [] users;
    close(listenfd);
    return 0;








}