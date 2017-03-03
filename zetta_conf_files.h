/* 
 * Zetta(c) (and rebranded) cameras configuration file structures
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

#include <stdint.h>

#define DVR_INFO_FILENAME      "info.dat"
#define DVR_SCHEDULE_FILENAME  "schedule.dat"
#define DVR_SETTINGS_FILENAME  "settings.dat"
#define DVR_TIME_FILENAME      "time.dat"

typedef struct dvr_info
{
	uint8_t model_len;
	char    model[0xf];
	uint8_t fw_ver_len;
	char    fw_ver[0xf];
} dvr_info_t;

typedef struct dvr_schedule
{
	uint8_t struct_TODO;
} dvr_schedule_t;

typedef struct dvr_settings
{
	uint8_t jpegqfactor;
	uint8_t resolution;
	uint8_t motiondetect;
	uint8_t showtimestamp;
	uint8_t circularrec;
	uint8_t framerate;
	uint8_t splitfiletime;
	uint8_t daynightmode;
	uint8_t orientation;
	uint8_t autostartmode;
	uint8_t voxsens;
	uint8_t voicerec;
	uint8_t vibdetectsens;
	uint8_t vibstandbymode;
	uint8_t aliveduration;
	uint8_t ledindication;
	uint8_t bandingfilter;
	uint8_t extintype;
	uint8_t extouttype;
	uint8_t buzzarduration;
	uint8_t sensorsens;
	uint8_t pir;
	uint8_t padding[0x1a];
} dvr_settings_t;

typedef struct dvr_time
{
	uint32_t epoch;
	int32_t  timezone;
	int32_t  daylight;
} dvr_time_t;

/*
 * Setting values mapping
 */
extern char * jpegqfactor_values[];
extern char * resolution_values[];
extern char * motiondetect_values[];
extern char * showtimestamp_values[];
extern char * circularrec_values[];
extern char * framerate_values[];
extern char * splitfiletime_values[];
extern char * daynightmode_values[];
extern char * orientation_values[];
extern char * autostartmode_values[];
extern char * voxsens_values[];
extern char * voicerec_values[];
extern char * vibdetectsens_values[];
extern char * vibstandbymode_values[];
extern char * aliveduration_values[];
extern char * ledindication_values[];
extern char * bandingfilter_values[];
extern char * extintype_values[];
extern char * extouttype_values[];
extern char * buzzarduration_values[];
extern char * sensorsens_values[];
extern char * pir_values[];