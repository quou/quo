#define QUO_IMPL
#include <quo.h>

/* This example demonstrates the use of Quo's binary serialisation module,
 * which can be used to save game states, level data, etc.
 * IT DOES NOT USE ENCRYPTION, MEANING ANYONE WITH A HEX-EDITOR CAN EDIT
 * THE SAVED DATA. Implement your own solution for security-critical
 * applications */

/* This example does not demonstate any rendering capability, that is
 * left out for simplicity. */

int main() {
	/* Example of writing data to a file: */
	{
		/* Initialise a new byte buffer */
		quo_ByteBuffer buffer;
		quo_init_byte_buffer(&buffer);

		/* Write an integer to the buffer */
		quo_byte_buffer_write(&buffer, int, 124);

		/* Write a string to the buffer */
		char string[1024] = "Hello, world";

		/* The string must be written one character at a time */
		for (int i = 0; i < strlen(string); i++) {
			quo_byte_buffer_write(&buffer, char, string[i]);
		}

		/* Open a file for writing in binary mode */
		FILE* file_handle = fopen("test.dat", "wb");

		/* Dump the data into the file */
		quo_byte_buffer_dump(&buffer, file_handle);

		/* Close the file */
		fclose(file_handle);

		/* Free the byte buffer */
		quo_free_byte_buffer(&buffer);
	}

	/* Example of reading data from a file: */
	/* Data must be read back in the same order as it was written */
	{
		quo_ByteBuffer buffer;

		/* Read the raw data from the file */
		FILE* file_handle = fopen("test.dat", "rb");
		quo_byte_buffer_read_file(&buffer, file_handle);
		fclose(file_handle);

		int int_val;
		char string_value[1024];

		/* The integer can be read back in the same way as it was written*/
		quo_byte_buffer_read(&buffer, int, &int_val);

		/* The string can be read back all at once, we don't have to do
		 * it one character at a time. */
		quo_byte_buffer_read(&buffer, char*, string_value);

		/* Print the loaded values */
		printf("int: %d, string: %s\n", int_val, string_value);

		/* Free the byte buffer */
		quo_free_byte_buffer(&buffer);
	}

}
