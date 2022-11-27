#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utility.h"

#define   MAX_FILE_NAME_LEN 80

//dosyalar parcalanacak bolunecek

//bol.exe recep.exe 1000
//parca_001.par 1000
//parca_002.par 1000
//parca_003.par 555


int main(int argc, char **argv)
{
    char source_file_name[MAX_FILE_NAME_LEN + 1];
    char dest_file_name[40];
    int chunk;
    int file_count = 0;
    int byte_count = 0;
    int c;

    FILE *fs, *fd;


    if(argc != 3){
        printf("bolunecek dosya ismi : ");
        scanf("%s", source_file_name);
        printf("kac byte'lik parcalara bolunsun : ");
        scanf("%d", &chunk);
    } else {
        strcpy(source_file_name, argv[1]);
        chunk = atoi(argv[2]);
    }

    if((fs = fopen(source_file_name, "rb")) == NULL){
        fprintf(stderr, "bolunecek %s dosyasi acilamadi\n", source_file_name);
        return 2;
    }

    fd = NULL;

    while((c = fgetc(fs)) != EOF){
        if(fd == NULL){
            sprintf(dest_file_name, "parca%03d.png", file_count + 1);
            fd = fopen(dest_file_name, "wb");
            if(fd == NULL){
                fprintf(stderr, "%s dosyasi olusturulamadi\n", dest_file_name);
                return 2;
            }
            ++file_count;
        }
        fputc(c, fd);
        ++byte_count;
        if(byte_count % chunk == 0){
            fclose(fd);
            fd = NULL;
        }

    }

    if(fd)
        fclose(fd);

    fclose(fs);


    printf("%d byte'lik %s dosyasi %d byte'lik %d dosyaya bolundu\n", byte_count, source_file_name, chunk, file_count);


}


/****************************************************/
/****************************************************/







