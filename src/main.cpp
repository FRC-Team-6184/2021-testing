#include <frc>
using namespace frc;
class Robot: public TimedRobot{
  //drive
  PWMVictorSPX::rightm(1);
  PWMVictorSPX::leftm(0);
  DifferentialDrive::robotdrive(leftm,rightm);
  XboxController::controller(1); //Lx=0 Ly=1 Lt=2 rt=3 Rx=4 ry=5 
  
  //pnematics
  Compressor::compressor(); //the id might be wrong
  
 
  public void TeleopInit(){
  compressor.start();
  }
  public void TeleopPeriodic(){
    
    robotdrive.ArcadeDrive(controller.GetRawAxis(1),controller.GetRawAxis(4));
    
    
  
  }
}
