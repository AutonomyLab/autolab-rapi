/***************************************************************************
 * Project: RAPI                                                           *
 * Author:  Jens Wawerla (jwawerla@sfu.ca)                                 *
 * $Id: $
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 **************************************************************************/

#ifndef RAPIROBOTCTRL_H
#define RAPIROBOTCTRL_H

#include "robot.h"
#include <string>

namespace Rapi
{

/**
 * Abtract base class for robot controllers. This allows robot controllers
 * to register with the framework
 * @author Jens Wawerla <jwawerla@sfu.ca>
 */
class ARobotCtrl : public IRobotUpdate
{
  public:
    /** Default desctructor */
    virtual ~ARobotCtrl();
    /**
     * A printf that adds the robots name in the front of the string
     * @param str string to print
     */
    virtual void rprintf ( const char* format, ... );
    /** RPrintf string */
    std::string mRPrintfString;
    /**
     * Gets the robot of this controller
     * @return robot
     */
    ARobot* getRobot() const;

  protected:
    /**
     * Default constructor
     * @param robot this controller controls
     */
    ARobotCtrl( ARobot* robot );
    /**
     * Update controller for the current time step
     * @param dt time since last upate [s]
     */
    virtual void updateData(float dt) = 0;
    /** Robot controlled by this controller */
    ARobot* mRobot;

};

}

#endif
