#include "mbed.h"
#include "glibr.h"
// #include "SDFileSystem.h"
// #include "wave_player.h"

glibr GSensor(D4,D5);
// SDFileSystem sd(p5, p6, p7, p8, "sd"); //SD card
// AnalogOut DACout(p18);
// wave_player waver(&DACout);
int isr_flag = 0;
DigitalOut myled(LED1);
//InterruptIn interrupt(p11);
//Serial pc(USBTX, USBRX);
bool ret;
int val;

int main()
{
    myled = 0;
    ret = 0;
    val = 0;
    if ( GSensor.ginit() ) {
        printf("APDS-9960 initialization complete\n\r");
    } else {
        printf("Something went wrong during APDS-9960 init\n\r");
    }

    // Start running the APDS-9960 gesture sensor engine
    if ( GSensor.enableProximitySensor(false) ) {
        printf("Gesture sensor is now running\n\r");
    } else {
        printf("Something went wrong during gesture sensor init!\n\r");
    }

    uint8_t proximity_data = 0;
    if ( !GSensor.setProximityGain(PGAIN_2X) ) { // muss nach enableProximitySensor aufgerufen werden
        printf("Something went wrong trying to set PGAIN\n");
    }
    // FILE *Up;
    // FILE *Down;
    // FILE *Left;
    // FILE *Right;
    // FILE *Far;
    // FILE *Near;

    //   waver.play(wave_file);
    while(1) {
        /* ret = GSensor.isGestureAvailable();
         pc.printf("Is Gesture Available?: %d\n", ret);
         myled = ret;
         val = GSensor.readGesture();
         */
        // if ( GSensor.isGestureAvailable() ) {
        //     printf("Gesture Available\n");
        //     switch ( GSensor.readGesture() ) {
        //         case DIR_UP:
        //             printf("UP\n");
        //             // Up=fopen("/sd/up.wav","r");
        //             // if(Up!=NULL){
        //             // waver.play(Up);
        //             // }else{ pc.printf("Up not open");} 
        //             // fclose(Up);   
        //             break;
        //         case DIR_DOWN:
        //             printf("DOWN\n");
        //             // Down=fopen("/sd/down.wav","r");
        //             // if(Down!=NULL){
        //             // waver.play(Down);
        //             // }else{ pc.printf("Down not open");}
        //             // fclose(Down);
        //             break;
        //         case DIR_LEFT:
        //             printf("LEFT\n");
        //             // Left=fopen("/sd/left.wav","r");
        //             // if(Left!=NULL){
        //             // waver.play(Left);
        //             // }else{pc.printf("Left not open");}
        //             // fclose(Left);
        //             break;
        //         case DIR_RIGHT:
        //             printf("RIGHT\n");
        //             //  Right=fopen("/sd/right.wav","r");
        //             // if(Right!=NULL){
        //             // waver.play(Right);
        //             // }else{pc.printf("Right not open");}
        //             // fclose(Right);
        //             break;
        //         case DIR_NEAR:
        //             printf("NEAR\n");
        //             // Near=fopen("/sd/near.wav","r");
        //             // if(Near!=NULL){
        //             // waver.play(Near);
        //             // }else{pc.printf("Near not open");}
        //             // fclose(Near);
        //             break;
        //         case DIR_FAR:
        //             printf("FAR\n");
        //             // Far=fopen("/sd/far.wav","r");
        //             // if(Far!=NULL){
        //             // waver.play(Far);
        //             // }else{pc.printf("Far not open");}
        //             // fclose(Far);
        //             break;
        //         default:
        //             printf("NONE\n");
        //     }
        // }

          // Read the proximity value
        if ( !GSensor.readProximity(proximity_data) ) {
            printf("Error reading proximity value");
        } else {
            printf("Proximity: %i\n", proximity_data);
        }
        
        // Wait 250 ms before next reading
        wait_us(250000);


           //wait_us(500000);

    }



}