/******************************************************************************
     * File: main.c
     * Description: ����������� ��������� ������� �������.
     * Created: 3 ������ 2021
     * Author: ������� ���������

******************************************************************************/

#include "main.h"

int main()
{
	// ****** ������������ ������ ���������� �������� *********
	printf("Section 3\n");
	while (is_reading_settings_section("Section 3"))
	{
		char *name = read_setting_name();
		if (strcmp(name, "var3") == 0)
			printf("var3 - %d\n", read_setting_i());
		else if (strcmp(name, "var2") == 0)
			printf("var2 - %s\n", read_setting_s());
		else if (strcmp(name, "var1") == 0)
			printf("var1 - %f\n", read_setting_f());
	}
	printf("\nSection 2\n");
	while (is_reading_settings_section("Section 2"))
	{
		char *name = read_setting_name();
		if (strcmp(name, "var1") == 0)
			printf("var1 - %s\n", read_setting_s());
		else if (strcmp(name, "var2") == 0)
			printf("var2 - %d\n", read_setting_i());
		else if (strcmp(name, "var3") == 0)
			printf("var3 - %f\n", read_setting_f());
	}
	printf("\nSection 1\n");
	while (is_reading_settings_section("Section 1"))
	{
		char *name = read_setting_name();
		if (strcmp(name, "var1") == 0)
			printf("var1 - %s\n", read_setting_s());
		else if (strcmp(name, "var2") == 0)
			printf("var2 - %s\n", read_setting_s());
	}
	// *******************************************************
		
	return 0;
}