/* 
 * Zetta(c) (and rebranded) cameras configuration utility
 *
 * This file is part of the zettaconf distribution
 *                              (https://github.com/asoraruf/zettaconf)
 * Copyright (c) 2017 Alessandro Soraruf.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 2.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#include "zetta_functions.h"

void print_usage(){
	printf("Usage:\n");
	printf("\n");
	printf("  zettaconf --print\n");
	printf("  zettaconf --help\n");
	printf("  zettaconf [--videoquality <low|medium|high>]\n"
		"      [--resolution <320x240|640x480|640x360|1280x720>]\n"
		"      [--motiondetect <off|low|medium|high>]\n"
		"      [--showtimestamp <off|on>]\n"
		"      [--circularrec <off|on>]\n"
		"      [--framerate  <low|high>]\n"
		"      [--splitfiletime <10|15|20|30|60>]\n"
		"      [--daynightmode <day|night|auto>]\n"
		"      [--orientation <normal|flip>]\n"
		"      [--autostartmode <off|absent|present|present_start|scheduled>]\n"
		"      [--voicedetect <off|low|medium|high>]\n"
		"      [--voicerec <off|on>]\n"
		"      [--vibrdetect <off|low|medium|high>]\n"
		"      [--standbymode <psave|fast>]\n"
		"      [--aliveduration <5|2>]\n"
		"      [--led <off|on>]\n"
		"      [--lighting <50hz|60hz|outdoor>]\n"
		"      [--extintype <off|no|nc>]\n"
		"      [--extouttype <off|no|nc>]\n"
		"      [--buzzarduration <off|rec|5|1>]\n"
		"      [--sensorsens <low|medium|high>]\n"
		"      [--pir <off|on>]\n"
		"      [--synctime]\n");
}

int main(int argc, char *argv[], char *envp[]){
	int i,ret;
	int set_schedule, set_settings, set_time;
	
	set_schedule=0;
	set_settings=0;
	set_time=0;

    printf("\n");
    printf(" -= Zetta Security Camcoders Configuration Utility =- \n");
    printf("\n");
	
	if (argc < 2){
		print_usage();
		return(1);
	}
	
	if (dvr_load_confs()) return(1);
	
	for (i = 1; i < argc; i++){
		if (strcasecmp(argv[i],"--help")==0){
			print_usage();
			return(0);
		}else if (strcasecmp(argv[i],"--print")==0){
			if (i == 1){
				dvr_print_info();
				printf("\n");
				dvr_print_settings();
				printf("\n");
				dvr_print_time();
				//printf("\n");
				//dvr_print_schedule();
				return (0);
			} else {
				print_usage();
				return(1);
			}
		}else if (strcasecmp(argv[i],"--videoquality")==0){
			i++;
			if (strcasecmp(argv[i],"low")==0){
				dvr_settings.jpegqfactor = 1;
			}else if (strcasecmp(argv[i],"medium")==0){
				dvr_settings.jpegqfactor = 2;
			}else if (strcasecmp(argv[i],"high")==0){
				dvr_settings.jpegqfactor = 4;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--resolution")==0){
			i++;
			if (strcasecmp(argv[i],"320x240")==0){
				dvr_settings.resolution = 0;
			}else if (strcasecmp(argv[i],"640x480")==0){
				dvr_settings.resolution = 1;
			}else if (strcasecmp(argv[i],"640x360")==0){
				dvr_settings.resolution = 2;
			}else if (strcasecmp(argv[i],"1280x720")==0){
				dvr_settings.resolution = 3;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--motiondetect")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.motiondetect = 0;
			}else if (strcasecmp(argv[i],"low")==0){
				dvr_settings.motiondetect = 1;
			}else if (strcasecmp(argv[i],"medium")==0){
				dvr_settings.motiondetect = 2;
			}else if (strcasecmp(argv[i],"high")==0){
				dvr_settings.motiondetect = 3;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--showtimestamp")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.showtimestamp = 0;
			}else if (strcasecmp(argv[i],"on")==0){
				dvr_settings.showtimestamp = 1;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--circularrec")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.circularrec = 0;
			}else if (strcasecmp(argv[i],"on")==0){
				dvr_settings.circularrec = 1;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--framerate")==0){
			i++;
			if (strcasecmp(argv[i],"low")==0){
				dvr_settings.framerate = 0;
			}else if (strcasecmp(argv[i],"high")==0){
				dvr_settings.framerate = 1;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--splitfiletime")==0){
			i++;
			if (strcasecmp(argv[i],"10")==0){
				dvr_settings.splitfiletime = 1;
			}else if (strcasecmp(argv[i],"15")==0){
				dvr_settings.splitfiletime = 2;
			}else if (strcasecmp(argv[i],"20")==0){
				dvr_settings.splitfiletime = 3;
			}else if (strcasecmp(argv[i],"30")==0){
				dvr_settings.splitfiletime = 4;
			}else if (strcasecmp(argv[i],"60")==0){
				dvr_settings.splitfiletime = 8;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--daynightmode")==0){
			i++;
			if (strcasecmp(argv[i],"day")==0){
				dvr_settings.daynightmode = 0;
			}else if (strcasecmp(argv[i],"night")==0){
				dvr_settings.daynightmode = 1;
			}else if (strcasecmp(argv[i],"auto")==0){
				dvr_settings.daynightmode = 2;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--orientation")==0){
			i++;
			if (strcasecmp(argv[i],"normal")==0){
				dvr_settings.orientation = 1;
			}else if (strcasecmp(argv[i],"flip")==0){
				dvr_settings.orientation = 2;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--autostartmode")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.autostartmode = 1;
			}else if (strcasecmp(argv[i],"absent")==0){
				dvr_settings.autostartmode = 2;
			}else if (strcasecmp(argv[i],"present")==0){
				dvr_settings.autostartmode = 3;
			}else if (strcasecmp(argv[i],"present_start")==0){
				dvr_settings.autostartmode = 4;
			}else if (strcasecmp(argv[i],"scheduled")==0){
				dvr_settings.autostartmode = 5;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--voicedetect")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.voxsens = 1;
			}else if (strcasecmp(argv[i],"low")==0){
				dvr_settings.voxsens = 2;
			}else if (strcasecmp(argv[i],"medium")==0){
				dvr_settings.voxsens = 3;
			}else if (strcasecmp(argv[i],"high")==0){
				dvr_settings.voxsens = 4;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--voicerec")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.voicerec = 1;
			}else if (strcasecmp(argv[i],"on")==0){
				dvr_settings.voicerec = 2;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--vibrdetect")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.vibdetectsens = 1;
			}else if (strcasecmp(argv[i],"low")==0){
				dvr_settings.vibdetectsens = 2;
			}else if (strcasecmp(argv[i],"medium")==0){
				dvr_settings.vibdetectsens = 3;
			}else if (strcasecmp(argv[i],"high")==0){
				dvr_settings.vibdetectsens = 4;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--standbymode")==0){
			i++;
			if (strcasecmp(argv[i],"psave")==0){
				dvr_settings.vibstandbymode = 1;
			}else if (strcasecmp(argv[i],"fast")==0){
				dvr_settings.vibstandbymode = 2;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--aliveduration")==0){
			i++;
			if (strcasecmp(argv[i],"5")==0){
				dvr_settings.aliveduration = 1;
			}else if (strcasecmp(argv[i],"2")==0){
				dvr_settings.aliveduration = 2;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--led")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.ledindication = 1;
			}else if (strcasecmp(argv[i],"on")==0){
				dvr_settings.ledindication = 2;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--lighting")==0){
			i++;
			if (strcasecmp(argv[i],"50hz")==0){
				dvr_settings.bandingfilter = 1;
			}else if (strcasecmp(argv[i],"60hz")==0){
				dvr_settings.bandingfilter = 2;
			}else if (strcasecmp(argv[i],"outdoor")==0){
				dvr_settings.bandingfilter = 3;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--extintype")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.extintype = 1;
			}else if (strcasecmp(argv[i],"no")==0){
				dvr_settings.extintype = 2;
			}else if (strcasecmp(argv[i],"nc")==0){
				dvr_settings.extintype = 3;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--extouttype")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.extouttype = 1;
			}else if (strcasecmp(argv[i],"no")==0){
				dvr_settings.extouttype = 2;
			}else if (strcasecmp(argv[i],"nc")==0){
				dvr_settings.extouttype = 3;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--buzzarduration")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.buzzarduration = 1;
			}else if (strcasecmp(argv[i],"rec")==0){
				dvr_settings.buzzarduration = 2;
			}else if (strcasecmp(argv[i],"5")==0){
				dvr_settings.buzzarduration = 3;
			}else if (strcasecmp(argv[i],"1")==0){
				dvr_settings.buzzarduration = 4;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--sensorsens")==0){
			i++;
			if (strcasecmp(argv[i],"low")==0){
				dvr_settings.sensorsens = 1;
			}else if (strcasecmp(argv[i],"medium")==0){
				dvr_settings.sensorsens = 2;
			}else if (strcasecmp(argv[i],"high")==0){
				dvr_settings.sensorsens = 3;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--pir")==0){
			i++;
			if (strcasecmp(argv[i],"off")==0){
				dvr_settings.pir = 1;
			}else if (strcasecmp(argv[i],"on")==0){
				dvr_settings.pir = 2;
			}else{
				print_usage();
				return(1);
			}
			set_settings=1;
		}else if (strcasecmp(argv[i],"--synctime")==0){
			time_t now = time(NULL);
			/* The camera uses UTC epoch only */
			dvr_time.epoch = now + difftime(mktime(localtime(&now)), mktime(gmtime(&now)));
			dvr_time.timezone = 0; // seems to be not used anymore
			dvr_time.daylight = 0; // seems to be not used anymore
			set_time=1;
		}else{
			print_usage();
			return(1);
		}
	}
	if (set_settings){
		printf("Saving \"%s\"...", DVR_SETTINGS_FILENAME);
		ret=dvr_write_settings();
		if (ret) return(ret);
		printf("\t[OK]\n");
	}
	if (set_time){
		printf("Saving \"%s\"...", DVR_TIME_FILENAME);
		ret=dvr_write_time();
		if (ret) return(ret);
		printf("\t\t[OK]\n");
	}
	if (set_schedule){
		printf("Saving \"%s\"...", DVR_SCHEDULE_FILENAME);
		ret=dvr_write_schedule();
		if (ret) return(ret);
		printf("\t[OK]\n");
	}
	return (0);
}

