#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * Returns the tm structure base on the Given Timezone and time structre.
 * if the timezone can't be match will use UTC.
 *
 * **/
struct tm  *getTime(char* tz, time_t *rawTime){
    setenv("TZ", tz, 1);
    tzset();
    struct tm *result = localtime(rawTime);
    unsetenv("TZ");
    return result;
}

/**
 * Main function.
 * **/
int main (int argc, char **argv){
    if (argc==1){
        puts("Time zone is required");
        return 3;
    }
    time_t rawTime = time(NULL);
    char buffer[80];
    if(rawTime == -1){
        printf("Unable to get time");
        return 1;
    }
    for(int i = 1; i<argc; i++){
        struct tm *loctime = getTime(argv[i], &rawTime);
        strftime(buffer,80,"%c", loctime);
        printf("%s %s\n",argv[i], buffer);
    }
    return 0;
}
