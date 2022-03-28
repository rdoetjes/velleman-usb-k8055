#include "k8055.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define DELAY_US 50000

void openDevice(int ipid){
    if ( OpenDevice(ipid)<0 ) {
		printf("Could not open the k8055 (port:%d)\nPlease ensure that the device is correctly connected.\n",ipid);
		exit(1);
    }
            
}

void knightRiderScan(int up){
  static int dout = 1;

  for(int i=0; i<7; ++i){
    WriteAllDigital((long)dout);
    OutputAnalogChannel(1, (long)dout);
    OutputAnalogChannel(2, (long)dout);
    if ( ReadAllDigital() >0){
      CloseDevice();
      exit(0);
    }
    
    dout = up ? dout << 1 : dout >> 1;
    usleep(DELAY_US);
  }
}
int main(){
 
    openDevice(0);

    while(1){
      knightRiderScan(1);
      knightRiderScan(0);
    }
}