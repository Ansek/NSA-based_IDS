/******************************************************************************
     * File: settings.c
     * Description: ���������� ������ �� ����� ������������.
     * Created: 3 ������ 2021
     * Author: ������� ���������

******************************************************************************/

#include "settings.h"

char settings_buffer[SETTINGS_BUFFER_SIZE];	// ����� ��� ���������� ������
FILE *settings;  						    // ������ ����� ��������

// ���������������, ��� �������� �� ����� ��������
Bool check_available()
{
	if (!feof(settings))
	{
		char c = getc(settings);
		// ������������� ������ �����������
		while (c != EOF && c == ';')
		{
			//C��������� �� ����� ������
			do {
				c = getc(settings);
			} while (c != EOF && c != '\n');
			c = getc(settings);
		}
		// ���� ��� ����� ������ ��� ������ ������
		if (c != EOF && c != '[' && c != ' ' && c != '\n' && c != '\r')
		{
			ungetc(c, settings);
			return TRUE;
		}
	}
	return FALSE;
}

Bool is_reading_settings_section(char *section)
{
	Bool is_available = FALSE;
	// ���� �������� ��� ���������������
	if (settings != NULL)
	{
		// ��������, ��� �������� ����
		is_available = check_available();
		if (!is_available)
		{
			fclose(settings);
			settings = NULL;
		}			
	}
	else 
	{
		char c;
		char *p = NULL;
		settings = fopen(FILE_NAME, "r");
		// ����� ������ ������
		do {
			// ����� �������� �������
			do {
				c = getc(settings);
			} while (c != EOF && c != '[');
			if (c != EOF)
			{
				// ��������� ��������
				p = section;
				do {
					c = getc(settings);
					if (*p == c)
						p++;
					else
						break;
				} while (c != EOF);
				// ���� ����� ������ ������
				if (c != EOF && c == ']')
				{
					//C��������� �� ����� ������
					do {
						c = getc(settings);
					} while (c != EOF && c != '\n');
					// ��������, ��� �������� ����
					is_available = check_available();
					if (is_available)
						break;
				}
			}
		} while (c != EOF);
	}
	return is_available;
}

char *read_setting_name()
{
	int i = 0;
	// ���������� ����� �� ����������� "="
	for (; i < SETTINGS_BUFFER_SIZE; i++)
	{
		settings_buffer[i] = getc(settings);
		if (settings_buffer[i] == EOF)
			i = SETTINGS_BUFFER_SIZE;
		else if (settings_buffer[i] == '=')
			break;
	}
	// �������� �� ������������ ���������� �����
	if (i == SETTINGS_BUFFER_SIZE)
	{
		fprintf(stderr, "�������� � ������������ ���������: {%s}\n",
			settings_buffer[i]);
        exit(1);
	}
	else
	{
		settings_buffer[i] = '\0';
	}
	return settings_buffer;
}

int read_setting_i()
{
	char c;
	int i;
	fscanf(settings, "%d", &i);
	//C��������� �� ����� ������
	do {
		c = getc(settings);
	} while (c != EOF && c != '\n');
	return i;
}

float read_setting_f()
{
	char c;
	float f;
	fscanf(settings, "%f", &f);
	//C��������� �� ����� ������
	do {
		c = getc(settings);
	} while (c != EOF && c != '\n');
	return f;
}

char *read_setting_s()
{
	if (fgets(settings_buffer, SETTINGS_BUFFER_SIZE, settings) != NULL)
	{
		// �������� ������� ����� ������
		int i = strlen(settings_buffer);
		settings_buffer[i - 1] = '\0'; 
		return settings_buffer;
	}
	return "";
} 