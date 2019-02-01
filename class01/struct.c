#include<stdio.h>
typedef struct laptop{
int serialno;
char *brand;
char *modelname;
float price;
float weight;
float screensize[5];
};
int main(){
struct laptop mylaptop;
mylaptop.brand="Apple";
mylaptop.modelname="Macbook Pro";
mylaptop.serialno=1231231;
mylaptop.price=85000;
mylaptop.weight=2.2;
mylaptop.screensize[0]=13.3;
printf("%d %s %s %f %f %f",mylaptop.serialno,mylaptop.brand,mylaptop.modelname,mylaptop.price,mylaptop.weight,mylaptop.screensize);
return 0;
}
