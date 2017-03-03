/* 
 * Zetta(c) (and rebranded) cameras configuration functions headers
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

#include "zetta_conf_files.h"
 
extern dvr_info_t     dvr_info;
extern dvr_settings_t dvr_settings;
extern dvr_time_t     dvr_time;
extern dvr_schedule_t dvr_schedule;

int dvr_open_ro_files();
int dvr_open_rw_files();
void dvr_close_files();

int dvr_load_confs();

void dvr_print_info();
void dvr_print_settings();
void dvr_print_time();
void dvr_print_schedule();

int dvr_write_settings();
int dvr_write_time();
int dvr_write_schedule();

void dvr_copy_settings(dvr_settings_t *dst_dvr_settings);
void dvr_copy_time(dvr_time_t *dst_dvr_time);
void dvr_copy_schedule(dvr_schedule_t *dst_dvr_schedule);