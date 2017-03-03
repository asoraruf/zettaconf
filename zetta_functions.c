/* 
 * Zetta(c) (and rebranded) cameras configuration functions
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
#include <time.h>
#include <errno.h>

#include "zetta_conf_files.h"
 
FILE *fd_info;
FILE *fd_sched;
FILE *fd_set;
FILE *fd_time;

dvr_info_t     dvr_info;
dvr_settings_t dvr_settings;
dvr_time_t     dvr_time;
dvr_schedule_t dvr_schedule;

int dvr_open_ro_files(){
	int ret;
	ret=0;
	fd_info = fopen(DVR_INFO_FILENAME,"r");
	if (!fd_info){
		perror(DVR_INFO_FILENAME);
		ret=errno;
	}
	fd_sched = fopen(DVR_SCHEDULE_FILENAME,"r");
	if (!fd_sched){
		perror(DVR_SCHEDULE_FILENAME);
		ret=errno;
	}
	fd_set = fopen(DVR_SETTINGS_FILENAME,"r");
	if (!fd_set){
		perror(DVR_SETTINGS_FILENAME);
		ret=errno;
	}
	fd_time = fopen(DVR_TIME_FILENAME,"r");
	if (!fd_time){
		perror(DVR_TIME_FILENAME);
		ret=errno;
	}
	return(ret);
}
int dvr_open_rw_files(){
	int ret;
	ret=0;
	/* info.dat always read only */
	fd_info = fopen(DVR_INFO_FILENAME,"r");
	if (!fd_info){
		perror(DVR_INFO_FILENAME);
		ret=errno;
	}
	fd_sched = fopen(DVR_SCHEDULE_FILENAME,"r+");
	if (!fd_sched){
		perror(DVR_SCHEDULE_FILENAME);
		ret=errno;
	}
	fd_set = fopen(DVR_SETTINGS_FILENAME,"r+");
	if (!fd_set){
		perror(DVR_SETTINGS_FILENAME);
		ret=errno;
	}
	fd_time = fopen(DVR_TIME_FILENAME,"r+");
	if (!fd_time){
		perror(DVR_TIME_FILENAME);
		ret=errno;
	}
	return(ret);
}
void dvr_close_files(){
	fclose(fd_info);
	fclose(fd_sched);
	fclose(fd_set);
	fclose(fd_time);
}

int dvr_load_confs(){
	int ret,rsize;
	ret=dvr_open_ro_files();
	rsize=fread(&dvr_info,sizeof(dvr_info_t),1,fd_info);
	if (!rsize){
		perror(DVR_INFO_FILENAME);
		ret=errno;
	}
	rsize=fread(&dvr_settings,sizeof(dvr_settings_t),1,fd_set);
	if (!rsize){
		perror(DVR_SETTINGS_FILENAME);
		ret=errno;
	}
	rsize=fread(&dvr_time,sizeof(dvr_time_t),1,fd_time);
	if (!rsize){
		perror(DVR_TIME_FILENAME);
		ret=errno;
	}
	dvr_close_files();
	return(ret);
}

void dvr_print_info(){
	printf("Model:               %s\n", dvr_info.model);
	printf("Firmware:            %s\n", dvr_info.fw_ver);
}

void dvr_print_settings(){
	printf("Video quality:       %s\n", jpegqfactor_values[dvr_settings.jpegqfactor]);
	printf("Resolution:          %s\n", resolution_values[dvr_settings.resolution]);
	printf("Motion detection:    %s\n", motiondetect_values[dvr_settings.motiondetect]);
	printf("Show timestamp:      %s\n", showtimestamp_values[dvr_settings.showtimestamp]);
	printf("Circular recording:  %s\n", circularrec_values[dvr_settings.circularrec]);
	printf("Frame rate:          %s\n", framerate_values[dvr_settings.framerate]);
	printf("Splitfile time:      %s\n", splitfiletime_values[dvr_settings.splitfiletime]);
	printf("Day/night mode:      %s\n", daynightmode_values[dvr_settings.daynightmode]);
	printf("Orientation:         %s\n", orientation_values[dvr_settings.orientation]);
	printf("Autostart mode:      %s\n", autostartmode_values[dvr_settings.autostartmode]);
	printf("Voice detection:     %s\n", voxsens_values[dvr_settings.voxsens]);
	printf("Voice recording:     %s\n", voicerec_values[dvr_settings.voicerec]);
	printf("Vibration detection: %s\n", vibdetectsens_values[dvr_settings.vibdetectsens]);
	printf("Standby mode:        %s\n", vibstandbymode_values[dvr_settings.vibstandbymode]);
	printf("Alive duration:      %s\n", aliveduration_values[dvr_settings.aliveduration]);
	printf("Led indicator:       %s\n", ledindication_values[dvr_settings.ledindication]);
	printf("Lighting Condition:  %s\n", bandingfilter_values[dvr_settings.bandingfilter]);
	printf("EXT in type:         %s\n", extintype_values[dvr_settings.extintype]);
	printf("EXT out type:        %s\n", extouttype_values[dvr_settings.extouttype]);
	printf("Buzzer duration:     %s [UNUSED]\n", buzzarduration_values[dvr_settings.buzzarduration]);
	printf("Sensor sensibility:  %s [UNUSED]\n", sensorsens_values[dvr_settings.sensorsens]);
	printf("PIR sensor:          %s\n", pir_values[dvr_settings.pir]);
}

void dvr_print_time(){
	printf("Current epoch:       %d\n", dvr_time.epoch);
	printf("Current date/time:   %s", asctime(gmtime((time_t *)&(dvr_time.epoch))));
	printf("Timezone:            %+d\n", dvr_time.timezone/3600);
	printf("Daylight:            %+d\n", dvr_time.daylight/3600);
}

void dvr_print_schedule(){
	printf("TODO");
}

int dvr_write_settings(){
	int ret,wsize;
	ret=dvr_open_rw_files();
	wsize=fwrite(&dvr_settings,sizeof(dvr_settings_t),1,fd_set);
	if (!wsize){
		perror(DVR_SETTINGS_FILENAME);
		ret=errno;
	}
	dvr_close_files();
	return(ret);
}

int dvr_write_time(){
	int ret,wsize;
	ret=dvr_open_rw_files();
	wsize=fwrite(&dvr_time,sizeof(dvr_time_t),1,fd_time);
	if (!wsize){
		perror(DVR_TIME_FILENAME);
		ret=errno;
	}
	dvr_close_files();
	return(ret);
}

int dvr_write_schedule(){
	int ret;
	ret=dvr_open_rw_files();
	printf("TODO");
	dvr_close_files();
	return(ret);
}