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
#ifndef RAPICBBUMPER_H
#define RAPICBBUMPER_H

#include "binarysensorarray.h"
#include "cbdriver.h"

namespace Rapi {

/**
 * This class provides a Chatterbox implementation of a bumper sensor
 * @author Jens Wawerla
 */
class CCBBumper : public ABinarySensorArray
{
    /** We are friends with our robot, so we get updated */
    friend class CCBRobot;

  public:
    /**
     * Default constructor
     * @param cbDriver HAL of the chatterbox
     * @param devName name of this device
     */
    CCBBumper(CCBDriver* cbDriver, std::string devName);
    /** Default destructor */
    virtual ~CCBBumper();
    /**
     * Enables or disables the device
     * @param enable = true to enable, false to disable
     */
    virtual void setEnabled ( bool enable );
    /**
     * Initializes the device
     * @param return 1 if success 0 otherwise
     */
    virtual int init();

  protected:
    /**
     * This method gets called by the framework every step to update
     * the sensor data
     * @param dt size of time step [s]
     */
    virtual void updateData(const double dt);
    /** HAL of the chatterbox */
    CCBDriver* mCBDriver;

};

} // namespace

#endif
