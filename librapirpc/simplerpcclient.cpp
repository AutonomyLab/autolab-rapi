#include <string.h>
#include "RapiRpc"
#include "cbrobot.h"
#include "i2c/robostix_drv.h"


int main (int argc, char* argv[])
{
    if( argc != 3 ) 
    {
        std::cerr << "Arguments is a host IP and a port number" << std::endl;
        return -1;
    }
    
    Rapi::RobotRpcClient* robot;
    std::string address= argv[1];
    int port = atoi(argv[2]);
    
    robot = new Rapi::RobotRpcClient(address, port);
    //robot->init();
    
    std::cout << "Init Done ..." << std::endl;
    
    double maxCapacity;
    unsigned int numBumpers;
    unsigned int numWheels;
    unsigned int numCliffs;
    unsigned int numPhotos;
    double maxRange;
    std::vector<float> ranges;
    std::vector<bool> bumpers;
    std::vector<bool> wheels;
    std::vector<bool> cliffs;
    std::vector<float> photos;
    Rapi::CVelocity2d vel(0.0, 0.0, 0.0);
    unsigned int numLights;
    
    while (true)
    {
        std::cout << "Testing robot " << address << std::endl;
        robot->getPowerPackDev(maxCapacity);
        ranges = robot->getRanges();
        std::cout << "Range[0] :" << ranges.at(0) << std::endl;   
        robot->getBumperDev(numBumpers);
        bumpers = robot->getBumpers();
        std::cout << "Bumpers Count: " << numBumpers << std::endl;
        std::cout << "Bumpers Status : " << bumpers[0] << " , " << bumpers[1] << std::endl;
        robot->getWheelDropDev(numWheels);
        wheels = robot->getWheelDrops();
        std::cout << "WheelDrop Count: " << numWheels << std::endl;
        std::cout << "WheelDrop Status : " << wheels[0] << "," << wheels[1] << "," << wheels[2] << std::endl;
        robot->getWheelDropDev(numCliffs);
        cliffs = robot->getCliffs();
        std::cout << "Cliffs Count: " << numCliffs << std::endl;
        std::cout << "Cliffs Status : " << cliffs[0] << " , " << cliffs[1] << " , " << cliffs[2] << " , " << cliffs[3]<< std::endl;
        robot->getPhotoDev(numPhotos, maxRange);
        photos = robot->getPhotos();
        std::cout << "Photos Count : " << numPhotos << std::endl;
        std::cout << "Analog Photo: " << photos[0] << " , max : " << maxRange << std::endl;
        std::cout << "Setting velcoity over RPC to : ";
        std::cout << std::endl;
        
        robot->setDrivetrain(vel);
        robot->getLightsDev(numLights);
        std::cout << "Number of lights : " << numLights << std::endl;
        robot->setLights(0, false, Rapi::CRgbColor(255,0,0), false, 0);
        robot->setLights(1, false, Rapi::CRgbColor(0,255,0), false, 0);
        robot->setLights(2, false, Rapi::CRgbColor(0,0,255), false, 0);
        robot->setLights(3, true, Rapi::CRgbColor(0,0,0), true, 100); 
        
        usleep(500000); // Please don't overload robot 
    }
    //robot->quit();
    
    std::cout << "Quit!" << std::endl;
    
    return 0;
    
}
