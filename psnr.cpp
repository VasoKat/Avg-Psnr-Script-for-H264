#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
  FILE *infile;
  char buf[6000];
  char f[1000];
  char a[1000];
  char b[1000];
  char c[1000];
  char d[1000];
  char e[1000];
  float count;
  float sum;
  char s1[1000];
  char s2[1000];
  char s3[1000];
  char s4[1000];
  char s5[1000];
  char s6[1000];
  char s7[1000];
  char s8[1000];
  char s9[1000];
  char s10[1000];
  char s11[1000];
  float w;
  remove("log.dec");
  system("./lencod.exe -f encoder.cfg");
  for(int i=0;i<100;i++){
      system("./rtp_loss.exe test.264 test1.264 5 0");	
      system("./ldecod.exe -f decoder.cfg"); 
  }
  if ((infile = fopen("log.dec", "r"))==NULL) {
      return 1;
  }
  while (fgets(buf, 6000, infile) != NULL) {
      if (strstr(buf, "FRExt") != NULL){ 
          sscanf(buf, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,f,a,b,c,d);
          char * token = strtok(d, "|");
          while(token != NULL) {
              token = strtok(NULL, "|");
              count++;
              if(count==1){
                 w=atof(token);
                 sum=sum+w;
              }
          }
          count=0;
      }	  
  }
  fclose(infile);
  printf("Average PSNR is %f \n",sum/100);
  return 0;
}
