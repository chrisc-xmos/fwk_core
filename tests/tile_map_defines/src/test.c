/* System headers */
#include <platform.h>
#include <xcore/channel.h>
#include <stdio.h>
#include "main_tile.h"

void do_tile_test_3 (int tile_no, chanend_t a,  chanend_t b,  chanend_t c);
void do_tile_test_2 (int tile_no, chanend_t a,  chanend_t b);
void do_tile_test_1 (int tile_no, chanend_t a);

#define HAS_TILE_0   ((PLATFORM_USES_TILE0 == 1) && (PLATFORM_SUPPORTS_TILE0 == 1))
#define HAS_TILE_1   ((PLATFORM_USES_TILE1 == 1) && (PLATFORM_SUPPORTS_TILE1 == 1))
#define HAS_TILE_2   ((PLATFORM_USES_TILE2 == 1) && (PLATFORM_SUPPORTS_TILE2 == 1))
#define HAS_TILE_3   ((PLATFORM_USES_TILE3 == 1) && (PLATFORM_SUPPORTS_TILE3 == 1))

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

#elseif (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c1, chanend_t c2)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(0, c1, c2);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c1, chanend_t c3)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(0, c1, c3);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c2, chanend_t c3)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(0, c2, c3);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c1)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(0, c1);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c2)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(0, c2);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile0(chanend_t c3)
#else
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(0, c3);
}

#endif //Tile 0


// Tile 1
#if (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3) 
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c1, chanend_t c2, chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_3(1, c1, c2, c3);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c1, chanend_t c2)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(1, c1, c2);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c1, chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(1, c1, c3);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c2, chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(1, c2, c3);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c1)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(1, c1);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c2)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(1, c2);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile1(chanend_t c3)
#else
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(1, c3);
}

#endif //Tile 1


// Tile 2
#if (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3) 
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c1, chanend_t c2, chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_3(2, c1, c2, c3);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c1, chanend_t c2)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(2, c1, c2);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c1, chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(2, c1, c3);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c2, chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(2, c2, c3);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c1)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(2, c1);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c2)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(2, c2);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile2(chanend_t c3)
#else
void main_tile2(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(2, c3);
}

#endif //Tile 2




// Tile 3
#if (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3) 
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c1, chanend_t c2, chanend_t c3)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_3(3, c1, c2, c3);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c1, chanend_t c2)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(3, c1, c2);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c1, chanend_t c3)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(3, c1, c3);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c2, chanend_t c3)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_2(3, c2, c3);
}

#elseif (HAS_TILE_0 && HAS_TILE_1 && !HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c1)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(3, c1);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && HAS_TILE_2 && !HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c2)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(3, c2);
}

#elseif (HAS_TILE_0 && !HAS_TILE_1 && !HAS_TILE_2 && HAS_TILE_3)
#ifdef MINIMISE_MAIN_TILE_ARGS
void main_tile3(chanend_t c3)
#else
void main_tile3(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3)
#endif
{
  do_tile_test_1(3, c3);
}

#endif //Tile 3





void do_tile_test_3 (int tile_no, chanend_t a,  chanend_t b,  chanend_t c)
{
  printf("Tile %d has %d channels to other tiles\n", tile_no, 3);
}


void do_tile_test_2 (int tile_no, chanend_t a,  chanend_t b)
{
  printf("Tile %d has %d channels to other tiles\n", tile_no, 2);
}


void do_tile_test_1 (int tile_no, chanend_t a)
{
  printf("Tile %d has %d channels to other tiles\n", tile_no, 1);
}




