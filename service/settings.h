/******************************************************************************
     * File: settings.h
     * Description: ���������� ������ �� ����� ������������.
     * Created: 3 ������ 2021
     * Author: ������� ���������

******************************************************************************/

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "config.ini"		// ��� ����� �� ���������
#define SETTINGS_BUFFER_SIZE 64		// ������ ������ ��� ���������� ������

typedef enum { FALSE, TRUE } Bool;

/**
@brief ���������, ��������� �� ������ ������ ������? 
@param section �������� ������
@return TRUE - � ������ ��� �������� ���������
*/
Bool is_reading_settings_section(char *section);

/**
@brief ��������� �������� ��������� ���������
@return �������� ���������
*/
char *read_setting_name();

/**
@brief ��������� ������������� �������� ���������
@return �������� ���������
*/
int read_setting_i();

/**
@brief ��������� ������������� �������� ���������
@return �������� ���������
*/
float read_setting_f();

/**
@brief ��������� ��������� �������� ���������
@return �������� ���������
*/
char *read_setting_s();

#endif 