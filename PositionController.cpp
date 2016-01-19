#include "PositionController.h"
#include "Robot.h"

void PositionController::Execute()
{
  Robot::Instance()->GetSpeedController(); 
}



/* ----------------------------------------------------------------------- */

#include <math.h>   /* trig function header */

/* ----------------------------------------------------------------------- */
/* SR04 defines */

#define LEFT_CLICKS_PER_INCH 79.52
#define RIGHT_CLICKS_PER_INCH 79.48
#define WHEEL_BASE 9.73

#define TWOPI 6.2831853070    /* nice to have float precision */
#define RADS 57.2958      /* radians to degrees conversion */

/* ----------------------------------------------------------------------- */
/* odometers() maintains these global accumulator variables: */

float theta;                    /* bot heading */
float X_pos;                    /* bot X position in inches */
float Y_pos;                    /* bot Y position in inches */
float total_inches;             /* total inches traveled */

/* ----------------------------------------------------------------------- */
/* using these local variables */

float left_inches;
float right_inches;
float inches;

long L_ticks, R_ticks;   /* icc11 typedefs defined in <int32.h> */
long last_left, last_right;
long lsamp, rsamp;

/* ----------------------------------------------------------------------- */
/* odometers() is a task run by the round-robin multi-tasking scheduler 20
  times per second.  It uses the left_distance and right_distance variables as
  inputs to maintain a set of global position and heading variables: X_pos,Y_pos,
  and theta. */

void odometers()
{
  while (1) {

    /* sample the left and right encoder counts as close together */
    /* in time as possible */

    ////                lsamp = left_distance;
    ////                rsamp = right_distance;
    //
    //    /* determine how many ticks since our last sampling? */
    //                L_ticks = int32_sub(lsamp,last_left);
    //                R_ticks = int32_sub(rsamp,last_right);
    //
    //    /* and update last sampling for next time */
    //                last_left = lsamp;
    //                last_right = rsamp;
    //
    //    /* convert the longs to floats */
    //                long_to_float(&L_ticks,&left_inches);
    //                long_to_float(&R_ticks,&right_inches);
    //
    //    /* and convert ticks to inches */
    //                left_inches /= LEFT_CLICKS_PER_INCH;
    //                right_inches /= RIGHT_CLICKS_PER_INCH;
    //
    //    /* calculate distance we have traveled since last sampling */
    //                inches = (left_inches + right_inches) / 2.0;
    //
    //    /* and accumulate total inches we have traveled */
    //                total_inches += inches;
    //
    //    /* accumulate total rotation around our center */
    //                theta += (left_inches - right_inches) / WHEEL_BASE;
    //
    //    /* and clip the rotation to plus or minus 360 degrees */
    //                theta -= (float)((int)(theta/TWOPI))*TWOPI;
    //
    //    /* now calculate and accumulate our position in inches */
    //                Y_pos += (inches * (cos(theta*RADS)));
    //                X_pos += (inches * (sin(theta*RADS)));
  }
}
