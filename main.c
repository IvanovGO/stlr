#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int STL_Size=0;

char *  STL_Load(char  fname[80]){
FILE *fp;
char str[80];
char sx[4],sy[4],sz[4];
int flen=0;
fp=fopen(fname,"r");
while (!feof(fp)){
fscanf(fp,"%s",str);
if (!strcmp(str,"loop")) flen++;
}
STL_Size=flen;
int * block=malloc(flen*9*sizeof(int)+1);

int fpos=0;
fsetpos(fp,0);
while(!feof(fp)){
fscanf(fp,"%s",str);
if  (!strcmp(str,"loop")) {
for (int i=0;i<3;i++){
fscanf(fp,"%s",str);
if (!strcmp(str,"vertex") fscanf("%s%s%s",sx,sy,sz);
} }
&block[fpos]=
}
}

printf("Number of loops%i\n",flen);
fclose(fp);
return NULL;
}




int main(int argc,char *argv[]){

printf("Argc=%i\n",argc);
for (int i=1; i<argc+1;i++) printf("Argv[%i]=%s\n",i,argv[i-1]);

FILE *fp;
if ((fp = fopen(argv[1], "r"))==NULL) {
printf("Cannot open file -  %s\n",argv[1]);
exit(1);}
/*
char str[80];
int rez;
while (!feof(fp)){
rez=fscanf(fp,"%s",str);
printf("%i-  str=%s\n",rez,&str);
}
*/
STL_Load(argv[1]);


}
