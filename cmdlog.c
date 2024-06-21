#include <stdio.h>
#include <time.h>

void isotime(char *res){
    time_t local;
    time(&local);
    struct tm utc = *gmtime(&local);
    char mon[3];
    char mday[3];
    char hour[3];
    char min[3];
    char sec[3];
    
    sprintf(mon, "%i", utc.tm_mon);
    sprintf(mday, "%i", utc.tm_mday);
    sprintf(hour, "%i", utc.tm_hour);
    sprintf(min, "%i", utc.tm_min);
    sprintf(sec, "%i", utc.tm_sec);
    
    if (utc.tm_mon < 10){
        sprintf(mon, "0%i", utc.tm_mon);
    }
    if (utc.tm_mday < 10){
        sprintf(mday, "0%i", utc.tm_mday);
    }
    if (utc.tm_hour < 10){
        sprintf(hour, "0%i", utc.tm_hour);
    }
    if (utc.tm_min < 10){
        sprintf(min, "0%i", utc.tm_min);
    }
    if (utc.tm_sec < 10){
        sprintf(sec, "0%i", utc.tm_sec);
    }
    
    sprintf(res, "%i-%s-%sT%s:%s:%sZ", (utc.tm_year+1900), (mon), (mday), (hour), (min), (sec));
}

int main(int argc, char *argv[]) {
    FILE *log;
    char time[21];
    isotime(time);
    int begin = 2;
    if (argc >= 3)
    {
      log = fopen(argv[1], "a");
      begin = 2;
    }
    else
    {
      log = fopen("E:\\dev\\logs\\.log", "a");
      begin = 1;
    }
    fprintf(log, "[%s]", time);
    for(int i = begin; i<argc; i++){
        fprintf(log, " %s", argv[i]);
    }
    fprintf(log, "\n");

    return 0;
}
