/*
 * AccelerationMonitor.h
 *
 *  Created on: Feb 11, 2015
 *      Author: Henry
 */

#ifndef ACCELERATIONMONITOR_H_
#define ACCELERATIONMONITOR_H_


/**
 * The accerlerationMonitor takes an input from an accelerometer and using this input determines if the
 * wearer has fallen by checking if they accelerate and then quickly stop accelerating. If it suspects
 * the wearer has fallen it sends a warning signal to the wearer by lighting up the LED. 15 seconds after
 * the algorithm detects a fall it will send a message unless the attached button is pressed.
 */
class AccelerationMonitor {

	/**
	 * field that will contain the reading of the accelerometer in m/s/s
	 */
	private:double acceleration = 0;

	/**
	 * field that represents the acceleration that causes the monitoring of the change in acceleration in
	 * m/s/s
	 */
	private:double max_acceleration = 8;

	/**
	 * the time interval between each measurement of acceleration
	 */
	private:int time_interval = 100;

	/**
	 * max allowable change in acceleration over one second for there to be no warning sent in m/s/s
	 */
	private:double max_change_in_acceleration = 8;

	/**
	 * amount of time the user has to cancel the warning before it is sent
	 */
	private:int time_to_cancel = 15000;

	/**
	 * amount of time in seconds the program will check for a large change in acceleration
	 */
	private:int time_to_check_for_acceleration_change = 3;



public:
	AccelerationMonitor();
	virtual ~AccelerationMonitor();

	/**
	 * starts the monitoring of the acceleration. Reads the acceleration every time interval and checks if
	 * the acceleration large enough to start monitoring the change in acceleration.
	 */
	void start_monitoring() {
		while (true) {
			sleep(time_interval);
			//
			//read acceleration and save it to acceleration field
			//
			if (acceleration > max_acceleration) {
				monitor_change_in_acceleration(acceleration);
			}
		}
	}
	//https://code.google.com/p/icarefalldetector/


	/**
	 * Once a large enough acceleration has been reached to cause an examination this method takes a
	 * reading of the acceleration once per second. It then checks to see if the change in acceleration
	 * exceeds the maximum allowed. Exceeding the maximum means there was a sudden change in acceleration
	 * which indicates a fall.
	 */
private:void monitor_change_in_acceleration(double high_acceleration) {
		last_acceleration_reading = high_acceleration;
		for(int i = 0; i < time_to_check_for_change_in_acceleration; i++) {

			sleep(1000);

			double current_acceleration = 0; //change to read accelerometer!!!!!!!!!!!

			if((last_acceleration_reading - current_acceleration) > max_change_in_acceleration) {
				fall_detected();
				break;
			}
			last_acceleration_reading = current_acceleration;
		}
	}



	/**
	 * This method turns of the warning light and makes a sound warning the wearer that a message will soon
	 * be sent. A event for the button is created that allows the wearer to cancel the message if they have
	 * not fallen.
	 */
private:void fall_detected () {
		bool cancel_button_pressed = false;

		//turn on light and/or make noise

		//create event for button press that changes cancel_button_pressed to true

		sleep(time_to_cancel);

		if(!cancel_button_pressed) {
			//send text message
		} else {
			//turn off light
		}
	}

};

#endif /* ACCELERATIONMONITOR_H_ */
