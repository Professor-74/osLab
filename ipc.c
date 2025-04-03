#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    void *shared_memory;
    char buffer[100];
    int shmid;

 
    shmid = shmget((key_t)1222, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    
    printf("Key of the shared memory is %d\n", shmid);

    
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }
    
    printf("Process is attached at %p\n", shared_memory);

   
    printf("Enter the data: ");
    int bytes_read = read(0, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';  
    }

   
    strcpy(shared_memory, buffer);

    
    printf("You wrote: %s\n", (char *)shared_memory);

    return 0;
}
