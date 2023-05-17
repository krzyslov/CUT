#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *reader() 
{
    FILE *fp;
    char buff[255];
    fp= fopen("/proc/stat", "r");

    if(fp == NULL){
        printf("File cannot open \n");
    }else{
        printf("File opened \n");
        char cpun[6];
        long int user, nice, system, idle, iowait, irq, softirq, steal, guest, geust_nice;
        while (fscanf(fp,"%5s %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", cpun, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &geust_nice) != EOF)
        {
            if ( !strstr(cpun,"cpu"))
                break;
            printf("%s %ld\n", cpun, user);
        }
        fclose(fp);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t thread_Reader;
    int result = pthread_create(&thread_Reader, NULL, reader, NULL);
    if (result != 0) {
        perror("Could not create thread.");
    }
    pthread_join(thread_Reader, NULL);
    printf("Main thread exiting.\n");

    return 0;
}