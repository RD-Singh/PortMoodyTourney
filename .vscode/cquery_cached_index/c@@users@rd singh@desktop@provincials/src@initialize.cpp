#include "main.h"


void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void checkAutoSelected()
{
  std::string selectedAuto = "";
  switch(auton)
  {
    case 0:
      selectedAuto = "BLUE MIDDLE FLAGS";
      break;
		case 1:
			selectedAuto = "BLUE PLATFORM";
			break;
    case 2:
      selectedAuto = "RED MIDDLE FLAGS";
      break;
		case 3:
			selectedAuto = "RED PLATFORM";
			break;
    case 4:
      selectedAuto = "SKILLS";
      break;
  }

  pros::lcd::set_text(3, "Current Selection: " + selectedAuto);
  pros::lcd::set_text(5, "The Current Number is: " + std::to_string(auton));
}

void on_left_button() {
auton--;
if(auton < 0)
{
	auton = 4;
}
checkAutoSelected();
}

void on_right_button()
{
  auton++;
	if(auton > 4)
	{
		auton = 0;
	}
	checkAutoSelected();
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */



void initialize() {

	pros::lcd::initialize();

	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::register_btn2_cb(on_right_button);

	pros::ADIGyro leftGyro ('A');
	pros::ADIGyro rightGyro ('B');

	pros::ADIUltrasonic leftW ('C', 'D');
	pros::ADIUltrasonic rightW ('E', 'F');
	pros::ADIUltrasonic front ('G', 'H');

	leftGyro.reset();
	rightGyro.reset();

	pros::delay(600);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */


void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */


void competition_initialize()
{




}
