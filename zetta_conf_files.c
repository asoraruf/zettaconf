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

 
/* Setting values mapping ("-" means "Unused") */

char * jpegqfactor_values[]    = {"-","Low","Medium","-","High"};
char * resolution_values[]     = {"320x240","640x480","640x360","1280x720"};
char * motiondetect_values[]   = {"Off","Low","Medium","High"};
char * showtimestamp_values[]  = {"Off","On"};
char * circularrec_values[]    = {"Off","On"};
char * framerate_values[]      = {"Low","High"};
char * splitfiletime_values[]  = {"-","10 min","15 min","20 min","30 min","-","-","-","60 min"};
char * daynightmode_values[]   = {"Day","Night","Auto"};
char * orientation_values[]    = {"-","Normal","Flip"};
char * autostartmode_values[]  = {"-","Off","Adapter absent[start] present[stop]","Adapter present[start] absent[stop]","Adapter present[start] absent[still on]","Scheduled"};
char * voxsens_values[]        = {"-","Off","Low","Medium","High"};
char * voicerec_values[]       = {"-","Off","On"};
char * vibdetectsens_values[]  = {"-","Off","Low","Medium","High"};
char * vibstandbymode_values[] = {"-","Power save","Fast wake up"};
char * aliveduration_values[]  = {"-","5 min","2 min"};
char * ledindication_values[]  = {"-","Off","On"};
char * bandingfilter_values[]  = {"-","Indoor 50Hz","Indoor 60Hz","Outdoor"};
char * extintype_values[]      = {"-","Off","NO","NC"};
char * extouttype_values[]     = {"-","Off","NO","NC"};
char * buzzarduration_values[] = {"-","Off","While recording","5 min","1 min"};
char * sensorsens_values[]     = {"-","Low","Medium","High"};
char * pir_values[]            = {"-","Off","On"};
