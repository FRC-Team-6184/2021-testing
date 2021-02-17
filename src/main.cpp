#include <frc>
using namespace frc;

bool ButtonToggle(button,state){
  if(button==true && state = true){
  state = false;
  }
  if(button==true && state = false){
  state = true;
  }
  return state
}
class Robot: public TimedRobot{
  //drive
  PWMVictorSPX rightm{1};
  PWMVictorSPX leftm{0};
  DifferentialDrive robotdrive{leftm,rightm};
  XboxController controller{1}; /*Axis: Lx=0, Ly=1, Lt=2, rt=3, Rx=4, ry=5; 
                                   Button: A=1, B=2, X=3, Y=4, BL=5, BR=6, back=7, start=8, SL=9, SR=10
                                 */
  //pnematics
  Compressor::compressor{}; //the id might be wrong
  compState;
  Solenoid topLeft{0};
  Solenoid topRight{1};
  Solenoid bottomLeft{2};
  Solenoid bottomRight{3};
  TLState;
  TRState;
  BLState;
  BRState;
  public void TeleopInit(){
  compState = 0;
  }
  public void TeleopPeriodic(){
    
    robotdrive.ArcadeDrive(controller.GetRawAxis(1),controller.GetRawAxis(4));
    
    //pnumatic control
    if(controller.GetRawButtonPressed(8)==true && compState==false){
      compressor.start();
      compstate= 1;
    }
    if(controller.GetRawButtonPressed(8)==true && compState==true){
      compressor.stop();
      compstate=0;
    }
    topLeft.Set(ButtonToggle(controller.GetRawButtonPressed(1),TLstate));
    topRight.Set(ButtonToggle(controller.GetRawButtonPressed(2),TRstate));
    bottomLeft.Set(ButtonToggle(controller.GetRawButtonPressed(3),BLstate));
    bottomRight.Set(ButtonToggle(controller.GetRawButtonPressed(4),BRstate));
    
    
  }
}
