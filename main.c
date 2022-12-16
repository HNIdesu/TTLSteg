
#include <stdio.h>

int main(int argc,char** argv){
    if(argc==1){
        puts("Usage:\t\ttlsteg sourpath destpath");
        return 0;
    }
    if(argc!=3){
        puts("the number of arguments is incorrect");
        return 0;
    }
    char* sourpath=argv[1];
    char* destpath=argv[2];
    FILE* sour=fopen(sourpath,"rb");
    FILE* dest=fopen(destpath,"wb");
    for(int b=fgetc(sour);b!=-1;b=fgetc(sour)){
        int result=b&0xC0;
        for(int i=1;i<=3;i++)
            result|=((fgetc(sour)&0xC0)>>i*2);
        fputc(result,dest);
    }
    fclose(sour);
    fclose(dest);
    return 0;
}