#include "monty.h"

/**
 * error - Prints error messarges according to their error code.
 * @error_code: The error codes are:
 * error 1 => The user does not give any file or more than one file to the program.
 * error 2 => The file provided can't be opened or read.
 * error 3 => The file provided contains an invalid instructions.
 * error 4 => When the program is unable to malloc more memory.
 * error 5 => When the parameter passed to the instruction "push" is not an int.
 */
void error(int error_code, ...)
{
	va_list arg;
	char *op;
	int num1;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USargE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			num1 = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num1, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usarge: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles errors.
 * @error_code: The error codes are:
 * error 6 => When the stack it empty for pint.
 * error 7 => When the stack it empty for pop.
 * error 8 => When stack is too short for operation.
 * error 9 => Division by zero.
 */
void more_error(int error_code, ...)
{
	va_list arg;
	char *op;
	int num1;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			num1 = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num1, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles string errors.
 * @error_code: The error codes are:
 * error 10 => The number inside a node is outside ASCII bounds.
 * error 11 => The stack is empty.
 */
void string_error(int error_code, ...)
{
	va_list arg;
	int num1;

	va_start(arg, error_code);
	num1 = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num1);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num1);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
