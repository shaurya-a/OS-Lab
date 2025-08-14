#include <stdio.h>

int main() {
    int i = 42;
    float f = 3.14159;
    double d = 12345.6789;
    char c = 'A';
    char str[] = "Hello";

    // Integer formats
    printf("Decimal (%%d): %d\n", i);
    printf("Unsigned (%%u): %u\n", i);
    printf("Octal (%%o): %o\n", i);
    printf("Hexadecimal lowercase (%%x): %x\n", i);
    printf("Hexadecimal uppercase (%%X): %X\n", i);

    // Floating-point formats
    printf("Float (%%f): %f\n", f);
    printf("Float in scientific notation (%%e): %e\n", f);
    printf("Float in scientific notation uppercase (%%E): %E\n", f);
    printf("Double (%%lf): %lf\n", d);
    printf("General format (%%g): %g\n", d);

    // Character and string formats
    printf("Character (%%c): %c\n", c);
    printf("String (%%s): %s\n", str);

    // Pointer format
    printf("Pointer (%%p): %p\n", (void *)str);

    // Width and precision
    printf("Width 10 (%%10d): %10d\n", i);
    printf("Precision .2 for float (%%.2f): %.2f\n", f);
    printf("Width 10, precision 2 (%%10.2f): %10.2f\n", f);

    return 0;
}

