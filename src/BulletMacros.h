#ifndef BMACROS_H
#define BMACROS_H

#include <vector>


///// bullet anims /////
#define ET_PELLET 0
#define ET_PELLET2 1
#define ET_POPCORN 2
#define ET_PELLET3 3
#define ET_BALL 4
#define ET_BALL2 5
#define ET_OUTLINE 6
#define ET_OUTLINE2 7
#define ET_RICE 8
#define ET_KUNAI 9
#define ET_SHARD 10
#define ET_AMULET 11
#define ET_ARROWHEAD 12
#define ET_BULLET 13
#define ET_LASERHEAD 14
#define ET_BACTERIA 15
#define ET_STAR 16
#define ET_COIN 17
#define ET_MENTOS 18
#define ET_MENTOS2 19
#define ET_JELLYBEAN 20
#define ET_KNIFE 21
#define ET_BUTTERFLY 22
#define ET_BIGSTAR 23
#define ET_BIGSTAR2 24
#define ET_FIREBALL_RED 25
#define ET_FIREBALL_PURPLE 26
#define ET_FIREBALL_BLUE 27
#define ET_FIREBALL_YELLOW 28
#define ET_HEART 29
#define ET_PULSE 30
#define ET_ARROW 31
#define ET_BUBBLE 32
#define ET_ORB 33
#define ET_DROPLET 34
#define ET_RICE_SPIN 35
#define ET_SHARD_SPIN 36
#define ET_STAR2 37
#define ET_LASER 38
#define ET_NOTE_RED 39
#define ET_NOTE_BLUE 40
#define ET_NOTE_GREEN 41
#define ET_NOTE_PURPLE 42
#define ET_REST 43


///// bullets colors /////
#define COLOR16_BLACK 0
#define COLOR16_DARKRED 1
#define COLOR16_RED 2
#define COLOR16_PURPLE 3
#define COLOR16_PINK 4
#define COLOR16_DARKBLUE 5
#define COLOR16_BLUE 6
#define COLOR16_DARKCYAN 7
#define COLOR16_CYAN 8
#define COLOR16_DARKGREEN 9
#define COLOR16_GREEN 10
#define COLOR16_LIME 11
#define COLOR16_DARKYELLOW 12
#define COLOR16_YELLOW 13
#define COLOR16_ORANGE 14
#define COLOR16_WHITE 15

#define COLOR_COIN_GOLD 0
#define COLOR_COIN_SILVER 1
#define COLOR_COIN_BRONZE 2

#define COLOR8_BLACK 0
#define COLOR8_RED 1
#define COLOR8_PINK 2
#define COLOR8_BLUE 3
#define COLOR8_CYAN 4
#define COLOR8_GREEN 5
#define COLOR8_YELLOW 6
#define COLOR8_WHITE 7

#define COLOR4_RED 0
#define COLOR4_BLUE 1
#define COLOR4_GREEN 2
#define COLOR4_YELLOW 3


///// aim modes /////
// AT -> at player // ST -> static
#define AIM_AT 0
#define AIM_ST 1
#define AIM_AT_RING 2
#define AIM_ST_RING 3
#define AIM_AWAY_RING 4
#define AIM_ST_RING2 5
#define AIM_RAND 6
#define AIM_RAND_RING 7
#define AIM_MEEK 8
#define AIM_AT_PYRAMID 9
#define AIM_ST_PYRAMID 10
#define AIM_PEANUT 11
#define AIM_PEANUT2 12

///// etEx functions /////
#define EX_SPEED_UP 1  //speedup for 15 frames
#define EX_ANIM 2      //set bullet spawn anim a
#define EX_ACCEL_F 4   //accelerate forwards by r for a frames
#define EX_ACCEL_S 8   //accelerate sideways by r for a frames
#define EX_STEP 16     //?
//32 unknown
#define EX_BOUNCE 64   //bounce a times on walls b, speed r, distTD s and dist LR m
#define EX_INVULN 128  //invulnerable to bomb for a frames
#define EX_OFFSCREEN 256 //?
#define EX_SPRITE 512  //set sprite type a color b
#define EX_DELETE 1024 //delete bullet with anim a
#define EX_SOUND 2048  //plays sound a
#define EX_WRAP 4096   //wrap bullets a times around walls b, speed r
#define EX_SHOOTPREP 8192
#define EX_SHOOT 16384
#define EX_REACT 32768
#define EX_GOTO 65536
#define EX_MOVE 131072
#define EX_VEL 262144
#define EX_VELADD 524288
#define EX_BRIGHT 1048576
#define EX_ACCELWEIRD 2097152
#define EX_SIZE 4194304
#define EX_SAVE 8388608 
#define EX_ENMCREATE 16777216 
#define EX_LAYER 33554432
#define EX_DELAY 67108864
#define EX_LASER 134217728
//unused
#define EX_HITBOX 536870912
//unused
#define EX_WAIT -2147483648


#endif
