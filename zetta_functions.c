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
#include <utime.h>
#include <errno.h>

#include "zetta_conf_files.h"
 
FILE *fd_info;
FILE *fd_sched;
FILE *fd_setting;
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
	fd_setting = fopen(DVR_SETTINGS_FILENAME,"r");
	if (!fd_setting){
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
	fd_setting = fopen(DVR_SETTINGS_FILENAME,"r+");
	if (!fd_setting){
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
	fclose(fd_setting);
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
	rsize=fread(&dvr_settings,sizeof(dvr_settings_t),1,fd_setting);
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
	printf("Current date/time:   %s", asctime(localtime((time_t *)&(dvr_time.epoch))));
	printf("Timezone:            %+d\n", dvr_time.timezone/3600);
	printf("Daylight:            %+d\n", dvr_time.daylight/3600);
}

void dvr_print_schedule(){
	printf("TODO");
}

void dvr_copy_settings(dvr_settings_t *dst_dvr_settings){
	if (!dst_dvr_settings){
		dst_dvr_settings->jpegqfactor = dvr_settings.jpegqfactor;
		dst_dvr_settings->resolution = dvr_settings.resolution;
		dst_dvr_settings->motiondetect = dvr_settings.motiondetect;
		dst_dvr_settings->showtimestamp = dvr_settings.showtimestamp;
		dst_dvr_settings->circularrec = dvr_settings.circularrec;
		dst_dvr_settings->framerate = dvr_settings.framerate;
		dst_dvr_settings->splitfiletime = dvr_settings.splitfiletime;
		dst_dvr_settings->daynightmode = dvr_settings.daynightmode;
		dst_dvr_settings->orientation = dvr_settings.orientation;
		dst_dvr_settings->autostartmode = dvr_settings.autostartmode;
		dst_dvr_settings->voxsens = dvr_settings.voxsens;
		dst_dvr_settings->voicerec = dvr_settings.voicerec;
		dst_dvr_settings->vibdetectsens = dvr_settings.vibdetectsens;
		dst_dvr_settings->vibstandbymode = dvr_settings.vibstandbymode;
		dst_dvr_settings->aliveduration = dvr_settings.aliveduration;
		dst_dvr_settings->ledindication = dvr_settings.ledindication;
		dst_dvr_settings->bandingfilter = dvr_settings.bandingfilter;
		dst_dvr_settings->extintype = dvr_settings.extintype;
		dst_dvr_settings->extouttype = dvr_settings.extouttype;
		dst_dvr_settings->buzzarduration = dvr_settings.buzzarduration;
		dst_dvr_settings->sensorsens = dvr_settings.sensorsens;
		dst_dvr_settings->pir = dvr_settings.pir;	
	}
}

void dvr_copy_time(dvr_time_t *dst_dvr_time){
	if (!dst_dvr_time){
		dst_dvr_time->epoch = dvr_time.epoch;
		dst_dvr_time->timezone = dvr_time.timezone;
		dst_dvr_time->daylight = dvr_time.daylight;
	}
}

void dvr_copy_schedule(dvr_schedule_t *dst_dvr_schedule){
	if (!dst_dvr_schedule){
		printf("TODO");
	}
}

int dvr_write_settings(){
	int ret,wsize;
	ret=dvr_open_rw_files();
	wsize=fwrite(&dvr_settings,sizeof(dvr_settings_t),1,fd_setting);
	if (!wsize){
		perror(DVR_SETTINGS_FILENAME);
		ret=errno;
	}
	dvr_close_files();
	return(ret);
}

int dvr_write_time(){
	int ret,wsize;
	struct utimbuf dvr_new_times;
	
	ret=dvr_open_rw_files();
	wsize=fwrite(&dvr_time,sizeof(dvr_time_t),1,fd_time);
	if (!wsize){
		perror(DVR_TIME_FILENAME);
		ret=errno;
	}
	dvr_close_files();
	/* time.dat needs a modified time updated to apply */
	dvr_new_times.actime = dvr_time.epoch+dvr_time.timezone+dvr_time.daylight;
	dvr_new_times.modtime = dvr_time.epoch+dvr_time.timezone+dvr_time.daylight;;
	if (utime(DVR_TIME_FILENAME, &dvr_new_times)){
		perror(DVR_TIME_FILENAME);
		ret=errno;
	}
	return(ret);
}

int dvr_write_schedule(){
	int ret;
	ret=dvr_open_rw_files();
	printf("TODO");
	dvr_close_files();
	return(ret);
}
