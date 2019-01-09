#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct tm  *getTime(char* tz, time_t *rawTime){
    setenv("TZ", tz, 1);
    tzset();
    struct tm *result = localtime(rawTime);
    unsetenv("TZ");
    return result;
}

int main (int argc, char **argv){
    time_t rawTime = time(NULL);
    if(rawTime == -1){
        printf("Unable to get time");
        return 1;
    }
    struct tm *loctime = getTime("Asia/Hong_Kong", &rawTime);
    printf("Hong Kong %02d:%02d:%02d\n",loctime->tm_hour, loctime->tm_min, loctime->tm_sec);
    loctim = getTime("EST", &rawTime);
    printf("EST %02d:%02d:%02d\n",loctime->tm_hour, loctime->tm_min, loctime->tm_sec);
    return 0;
}
