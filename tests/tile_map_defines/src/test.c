/* System headers */
#include <platform.h>
#include <xcore/channel.h>
#include <stdio.h>
#include <stdbool.h>
#include "main_tile.h"

bool do_tile_test_3 (int tile_no, chanend_t a,  chanend_t b,  chanend_t c);
bool do_tile_test_2 (int tile_no, chanend_t a,  chanend_t b);
bool do_tile_test_1 (int tile_no, chanend_t a);
bool do_tile_test_0 (int tile_no);

bool do_channel_test(int tile_no, chanend_t chan_a);



#define HAS_TILE_0   ((PLATFORM_USES_TILE_0 == 1) && (PLATFORM_SUPPORTS_TILE_0 == 1))
#define HAS_TILE_1   ((PLATFORM_USES_TILE_1 == 1) && (PLATFORM_SUPPORTS_TILE_1 == 1))
#define HAS_TILE_2   ((PLATFORM_USES_TILE_2 == 1) && (PLATFORM_SUPPORTS_TILE_2 == 1))
#define HAS_TILE_3   ((PLATFORM_USES_TILE_3 == 1) && (PLATFORM_SUPPORTS_TILE_3 == 1))



// Tile 0
#if (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3) 
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c1, chanend_t c2, chanend_t c3)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_3(0, c1, c2, c3);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c1, chanend_t c2)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_2(0, c1, c2);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c1, chanend_t c3)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_2(0, c1, c3);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c2, chanend_t c3)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_2(0, c2, c3);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c1)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_1(0, c1);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c2)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_1(0, c2);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c3)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_1(0, c3);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0()
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
    do_tile_test_0(0);
}

#endif //Tile 0


// Tile 1
#if (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3) 
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c0, chanend_t c2, chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_3(1, c0, c2, c3);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c0, chanend_t c2)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(1, c0, c2);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c0, chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(1, c0, c3);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c2, chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(1, c2, c3);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c0)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(1, c0);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c2)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(1, c2);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(1, c3);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1()
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_0(1);
}

#endif //Tile 1


// Tile 2
#if (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3) 
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_3(2, c0, c1, c3);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c0, chanend_t c1)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(2, c0, c1);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c0, chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(2, c0, c3);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c1, chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(2, c1, c3);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c0)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(2, c0);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c1)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(2, c1);
}

#elif (!HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(2, c3);
}

#elif (!HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2()
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_0(2);
}

#endif //Tile 2




// Tile 3
#if (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3) 
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_3(3, c0, c1, c2);
}

#elif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c0, chanend_t c1)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(3, c0, c1);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c0, chanend_t c2)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(3, c0, c2);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c1, chanend_t c2)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(3, c1, c2);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c0)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(3, c0);
}

#elif (!HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c1)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(3, c1);
}

#elif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c0)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(3, c0);
}

#elif (!HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3()
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_0(3);
}

#endif //Tile 3


// For the do_test_n functions, it is essential that channels are organised in the call
// connect in lowest to highest tile number from a to c. So for a do_tile_test_3 call
// on tile 1, chan_a connects to tile 0, chan_b connects to tile 2, and chan_c connects
// to tile 3.
bool do_tile_test_3 (int tile_no, chanend_t chan_a,  chanend_t chan_b,  chanend_t chan_c)
{
    printf("Chanend a resource ID on tile %d is %08X\n", tile_no, chan_a);
    printf("Chanend b resource ID on tile %d is %08X\n", tile_no, chan_b);
    printf("Chanend c resource ID on tile %d is %08X\n", tile_no, chan_c);

    if(!do_channel_test (tile_no, chan_c))
    {
        printf("Tile %d failed for channel c\n",tile_no);
        return false;        
    }
    
    if(!do_tile_test_2  (tile_no, chan_a, chan_b))
    {
        return false;        
    }
    return true;   
}


bool do_tile_test_2 (int tile_no, chanend_t chan_a,  chanend_t chan_b)
{    
    printf("Chanend a resource ID on tile %d is %08X\n", tile_no, chan_a);
    printf("Chanend b resource ID on tile %d is %08X\n", tile_no, chan_b);
    
    if(!do_channel_test (tile_no, chan_b))
    {
        printf("Tile %d failed for channel b\n",tile_no);
        return false;        
    }
    
    if(!do_tile_test_1  (tile_no, chan_a))
    {
        return false;        
    }
    return true;   
}


bool do_tile_test_1 (int tile_no, chanend_t chan_a)
{
    printf("Chanend a resource ID on tile %d is %08X\n", tile_no, chan_a);

    if(!do_channel_test (tile_no, chan_a))
    {
        printf("Tile %d failed for channel a\n",tile_no);
        return false;        
    }
    
    printf("Tile %d passed\n",tile_no);
    return true;   
}


bool do_tile_test_0 (int tile_no)
{
    printf("Tile %d passed\n",tile_no);
    return true;
}


bool do_channel_test(int tile_no, chanend_t chan)
{
    printf("Channel test on tile %d\n", tile_no);
    printf("Chanend resource ID is %08X\n", chan);
    
    if (chan == 0)
    {
        printf("Error: Tile %d chanend resource ID is 0\n", tile_no);
        return false;        
    }
    
    // Note: use word chanend operations. As a single word is sent, 
    // and the channel has not been used before, it cannot block.
    chanend_out_word(chan, tile_no);
    printf("Tile %d sent %d to tile a\n", tile_no, tile_no);
    
    int other_tile = chanend_in_word(chan);
    printf("Tile %d got %d from tile a\n", tile_no, other_tile);
    
    if (tile_no == other_tile) // The other tile thinks it's on the same tile.
    {
        printf("Error: %d = %d \n", tile_no, other_tile);
        // todo how to report this? 
         
        return false;
    }
    else if (tile_no > other_tile)
    {
        // This tile is ok. Close the link to indicate success.
        chanend_out_end_token(chan);
        chanend_check_end_token(chan);
        printf("Success: %d > %d \n", tile_no, other_tile);  
        return true;
    }
    else if (tile_no < other_tile) 
    {
        // This tile is ok. Close the link to indicate success.
        chanend_check_end_token(chan);  
        chanend_out_end_token(chan);
        
        printf("Success: %d < %d \n", tile_no, other_tile);        
        return true;
    }
}


