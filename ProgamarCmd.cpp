/*
 * File:   ProgamarCmd.cpp
 * Author: Tomas Salazar
 *
 * Created on Agosto 11, 2013, 1:35 PM
 */

#include "ProgramarCmd.h"
#include <string.h>
#include <stdio.h>

ProgramarCmd::ProgramarCmd(Model* model, Controller* controller) {
	this->procesa = false;
	this->procesaHoraInicio = false;
	this->procesaTiempo = false;
	this->procesaDia = false;
	this->controller = controller;
	this->model = model;

	this-> hourPG1 = 0;
	this->minutePG1 = 0;
	this->minutesOnPG1 = 0;
	this->dayPG1 = 0;
	this->dayWeek = 37;

	this->currentDay = 1;
}

ProgramarCmd::~ProgramarCmd() {
}

void ProgramarCmd::ok() {

	if (procesa == false && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {
		procesa = true;
	} else if (procesa == true && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {
		procesaHoraInicio = true;

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== false && procesaDia == false) {
		procesaTiempo = true;

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== true && procesaDia == false) {

		int tD = dayWeek & 1;
		int tL = dayWeek & 2;
		int tM = dayWeek & 4;
		int tMi = dayWeek & 8;
		int tJ = dayWeek & 16;
		int tV = dayWeek & 32;
		int tS = dayWeek & 64;

		if (currentDay == 1) {
			if (tD == 1) {
				dayWeek = dayWeek - 1;
			} else {
				dayWeek = dayWeek + 1;
			}
		}

		if (currentDay == 2) {
			if (tL == 2) {
				dayWeek = dayWeek - 2;
			} else {
				dayWeek = dayWeek + 2;
			}

		}

		if (currentDay == 3) {
			if (tM == 4) {
				dayWeek = dayWeek - 4;
			} else {
				dayWeek = dayWeek + 4;
			}

		}

		if (currentDay == 4) {
			if (tMi == 8) {
				dayWeek = dayWeek - 8;
			} else {
				dayWeek = dayWeek + 8;
			}

		}

		if (currentDay == 5) {
			if (tJ == 16) {
				dayWeek = dayWeek - 16;
			} else {
				dayWeek = dayWeek + 16;
			}

		}

		if (currentDay == 6) {
			if (tV == 32) {
				dayWeek = dayWeek - 32;
			} else {
				dayWeek = dayWeek + 32;
			}

		}

		if (currentDay == 7) {
			if (tS == 64) {
				dayWeek = dayWeek - 64;
			} else {
				dayWeek = dayWeek + 64;
			}

		}


		if (currentDay == 8) {
			procesaDia = true;
		}

		//validation to avoid overflow
		if(dayWeek > 127){
			dayWeek = 127;
		}
		if(dayWeek < 0){
			dayWeek = 0;
		}


	}
}

void ProgramarCmd::cancel() {

	controller->goHome();

}

void ProgramarCmd::up() {

	if (procesa == false && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {

		controller->goX(true);

	} else if (procesa == true && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {
		this->minutePG1 = this->minutePG1 + 5;
		if (this->minutePG1 >= 60) {
			this->hourPG1++;
			this->minutePG1 = 0;
		}
		if (this->hourPG1 >= 24) {
			this->hourPG1 = 0;
		}

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== false && procesaDia == false) {
		if (this->minutesOnPG1 < 60) {

			this->minutesOnPG1 = this->minutesOnPG1 + 1;
		}

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== true && procesaDia == false) {
		currentDay++;
		if (currentDay >= 9) {
			currentDay = 1;
		}

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== true && procesaDia == true) {

	}

}

void ProgramarCmd::down() {

	if (procesa == false && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {

		controller->goX(true);

	} else if (procesa == true && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {
		this->minutePG1 = this->minutePG1 - 5;
		if (this->minutePG1 <= 0) {
			this->hourPG1--;
			this->minutePG1 = 59;
		}
		if (this->hourPG1 >= 0) {
			this->hourPG1 = 23;
		}

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== false && procesaDia == false) {

		if (this->minutesOnPG1 > 0) {

			this->minutesOnPG1 = this->minutesOnPG1 - 1;
		}
	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== true && procesaDia == false) {
		currentDay--;
				if (currentDay <= 0) {
					currentDay = 8;
				}

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== true && procesaDia == true) {

	}

}

void ProgramarCmd::display(char msg[]) {

	//Limpia string
	strcpy(msg, "");

	if (procesa == false && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {
		strcat(msg, "  Programar      encendido ?: ");

	} else if (procesa == true && procesaHoraInicio == false && procesaTiempo
			== false && procesaDia == false) {
		char hour[4];
		char minute[4];
		sprintf(hour, "%d", this->hourPG1);
		sprintf(minute, "%d", this->minutePG1);

		strcat(msg, "    Hora de     encendido? ");
		strcat(msg, hour);
		strcat(msg, ":");
		strcat(msg, minute);

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== false && procesaDia == false) {
		char onTime[4];
		sprintf(onTime, "%d", this->minutesOnPG1);
		strcat(msg, "   Tiempo de    encendido ");
		strcat(msg, onTime);
		strcat(msg, " min  ");

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== true && procesaDia == false) {
		if(currentDay == 8){
			strcat(msg, "Guardar dias:  OK");
		}else{
			strcat(msg, "   Que dia: ?   ");
		}

		int tD = dayWeek & 1;
		int tL = dayWeek & 2;
		int tM = dayWeek & 4;
		int tMi = dayWeek & 8;
		int tJ = dayWeek & 16;
		int tV = dayWeek & 32;
		int tS = dayWeek & 64;

		if (tD == 1) {
			if (currentDay == 1) {
				strcat(msg, "&D");
			} else {
				strcat(msg, "*D");
			}

		} else {
			if (currentDay == 1) {
				strcat(msg, "_D");
			} else {
				strcat(msg, " D");
			}

		}
		if (tL == 2) {
			if (currentDay == 2) {
				strcat(msg, "&L");
			} else {
				strcat(msg, "*L");
			}
		} else {
			if (currentDay == 2) {
				strcat(msg, "_L");
			} else {
				strcat(msg, " L");
			}
		}
		if (tM == 4) {
			if (currentDay == 3) {
				strcat(msg, "&M");
			} else {
				strcat(msg, "*M");
			}
		} else {
			if (currentDay == 3) {
				strcat(msg, "_M");
			} else {
				strcat(msg, " M");
			}
		}
		if (tMi == 8) {
			if (currentDay == 4) {
				strcat(msg, "&M");
			} else {
				strcat(msg, "*M");
			}
		} else {
			if (currentDay == 4) {
				strcat(msg, "_M");
			} else {
				strcat(msg, " M");
			}
		}
		if (tJ == 16) {
			if (currentDay == 5) {
				strcat(msg, "&J");
			} else {
				strcat(msg, "*J");
			}

		} else {
			if (currentDay == 5) {
				strcat(msg, "_J");
			} else {
				strcat(msg, " J");
			}

		}
		if (tV == 32) {
			if (currentDay == 6) {
				strcat(msg, "&V");
			} else {
				strcat(msg, "*V");
			}

		} else {
			if (currentDay == 6) {
				strcat(msg, "_V");
			} else {
				strcat(msg, " V");
			}
		}
		if (tS == 64) {
			if (currentDay == 7) {
				strcat(msg, "&S  ");
			} else {
				strcat(msg, "*S  ");
			}

		} else {
			if (currentDay == 7) {
				strcat(msg, "_S  ");
			} else {
				strcat(msg, " S  ");
			}

		}

	} else if (procesa == true && procesaHoraInicio == true && procesaTiempo
			== true && procesaDia == true) {
		strcat(msg, "Registro guardado exitosomante   ");

	}

}

