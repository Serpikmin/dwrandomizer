
#include <stdio.h>
#include "patch.h"
#include "mt64.h"
#include "dwr.h"
#include "flute_music.h"

/**
 * Applies speedup to the flute music.
 * This has been tested with the original song as well as the above ones, but I'm not familiar enough with the DW music engine to guarantee this will work with every possible song.
 *
 * @param rom The rom struct
 */
void speed_up_flute_song(dw_rom *rom)
{
    BOOL song_ended = FALSE;
    uint32_t address = FLUTE_MUSIC_ADDRESS + 6; // speed hacks don't modify the song "header", except for tempo
    uint8_t i;
    uint8_t skip = 2;

    printf("SPEEDING UP FLUTE SONG\n");

    vpatch(rom, FLUTE_MUSIC_ADDRESS+3, 1, 0x78); // tempo
    while(!song_ended && address < FLUTE_MUSIC_ADDRESS+71)
    {
        i = rom->content[address];
        switch(i)
        {
            case(0xf6):
                skip = 2; // might be "note + length" bytes from now on
                address++;
                break;
            case(0xf7): // sets fixed note length until disabled
                skip = 1; // single notes until otherwise noted
                address++; // skip this instruction
                vpatch(rom, address, 1, 1); // set said fixed length to the minimum
                address++;
                break;
            case(0xfb):
                if(rom->content[address+1] == 0 && rom->content[address+2] == 0)
                {
                    song_ended = TRUE;
                }
                else if(rom->content[address+1] == 0 && rom->content[address+2] != 0) // rest
                {
                    vpatch(rom, address+2, 1, 1); // set rest length to the minimum
                    address += 5;
                }
                else // just adjusting duty cycle, volume and such
                {
                    address += 2;
                }
                break;
            case(0xfc):
            case(0x00):
                song_ended = TRUE;
                break;
            default: // just a note
                if(skip == 2)
                {
                    vpatch(rom, address+1, 1, 1);
                }
                address += skip;
                break;
        }
    }
    return;
}
