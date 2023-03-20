/* 
 * File:   controls.h
 * Author: Michael Nimdea-Gyan Adu
 *
 * Created on 04 March 2023, 13:36
 */

#include "controls.h"
enum chess_stages currentStage= CONFIGURATION;
void setMatchStatus(enum chess_stages stage)
{
    currentStage=stage;
}
