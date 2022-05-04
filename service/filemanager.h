/******************************************************************************
     * File: filemanager.h
     * Description: �������� ���������� ������������� ����������� � �����.
     * Created: 3 ������ 2021
     * Author: ������� ���������

******************************************************************************/

#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include <windows.h>

#include "settings.h"

// �������� ������, ������� ���� ���������
typedef struct Fragment
{
	char *text;					// ���������� ������
	struct Fragment *next;		// ������ �� ��������� ��������
} Fragment;

// ���� � ������� ���� ��������� ���������
typedef struct FilesList
{
	short id;					// ������������� �����	
	char *name;					// ��� �����
	Fragment *b_fragment;		// ������ �� ������ ��������
	Fragment *e_fragment;		// ������ �� ��������� ��������
	struct FilesList *next;		// ������ �� ��������� ����
} FilesList;

/**
@brief ��������� �������� �� ���������� ������
*/
void run_filemanager();

/**
@brief ������������ ����� ���� ��� ������
@param filename ��� �����
@return ������������� �� ������� 
*/
short reg_file(char* filename);

/**
@brief ���������� ��������� ��� ���������� � ����
@param id ��� �����
@param text ���������� ������
*/
void add_fragment(short id, char* text);

#endif