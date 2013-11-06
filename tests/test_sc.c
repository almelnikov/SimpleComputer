#include "mySimpleComputer.h"

int main()
{
	int mem1, mem2;
	int bit1, bit2;
	int comm1, comm2;
	int command, operand;
	int ret;
	
	sc_memoryInit();
	sc_memorySet(3, 0x123);
	sc_memoryGet(1, &mem1);
	sc_memoryGet(3, &mem2);
	printf("0?%X :: 123?%X\n", mem1, mem2);
	sc_memorySave("memory");
	/* Меняем ячейку памяти, загружаем память в неизмененном состоянии */
	sc_memorySet(3, 1);
	sc_memoryLoad("memory");
	sc_memoryGet(3, &mem1);
	printf("123?%X\n", mem1);
	/* Проверка функций работы с регистром флагов */
	sc_regInit();
	sc_regSet(FLAG_DIVISION, 1);
	sc_regSet(FLAG_INTERRUPT, 1);
	printf("Flag register is %X\n", sc_reg_flags);
	sc_regGet(FLAG_DIVISION, &bit1);
	sc_regSet(FLAG_DIVISION, 0);
	sc_regGet(FLAG_DIVISION, &bit2);
	printf("1?%d 0?%d\n", bit1, bit2);
	/* Кодирование/декодирование комманд */
	ret = sc_commandEncode(0x21, 4, &comm1);
	printf("Encoded command is %X Return value: %d\n", comm1, ret);
	ret = sc_commandEncode(0x4, 4, &comm2);
	printf("Encoded command is %X Return value: %d\n", comm2, ret);
	ret = sc_commandDecode(0x1084, &command, &operand);
	printf("Command; %d Operand: %d Return value: %d\n", command, operand, ret);
	ret = sc_commandDecode(0xB84, &command, &operand);
	printf("Command; %d Operand: %d Return value: %d\n", command, operand, ret);
	return 0;
}